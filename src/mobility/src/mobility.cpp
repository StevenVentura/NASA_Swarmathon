#include <ros/ros.h>

// ROS libraries
#include <angles/angles.h>
#include <random_numbers/random_numbers.h>
#include <tf/transform_datatypes.h>
#include <tf/transform_listener.h>

// ROS messages
#include <std_msgs/Float32.h>
#include <std_msgs/Int16.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/Range.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <apriltags_ros/AprilTagDetectionArray.h>

// Include Controllers
#include "PickUpController.h"
#include "DropOffController.h"
#include "SearchController.h"

// To handle shutdown signals so the node quits
// properly in response to "rosnode kill"
#include <ros/ros.h>
#include <signal.h>

using namespace std;

// Random number generator
random_numbers::RandomNumberGenerator* rng;

// Create controllers
PickUpController pickUpController;
DropOffController dropOffController;
SearchController searchController;

// Mobility Logic Functions
void sendDriveCommand(double linearVel, double angularVel);
void openFingers(); // Open fingers to 90 degrees
void closeFingers();// Close fingers to 0 degrees
void raiseWrist();  // Return wrist back to 0 degrees
void lowerWrist();  // Lower wrist to 50 degrees
void mapAverage();  // constantly averages last 100 positions from map

void continueInterruptedSearch();

void setDestination(float x, float y);
void setDestinationAngular(float angle, float distance);
void doPickupControllerMovements();
void resetPickUpController();
void resetDropOffController();

void print(string str);
void print(float f);
void print(int i);

// Numeric Variables for rover positioning
geometry_msgs::Pose2D currentLocation;
geometry_msgs::Pose2D currentLocationMap;
geometry_msgs::Pose2D currentLocationAverage;

//POSE VARIABLES
const float FINGERS_OPEN = M_PI_2;
const float FINGERS_CLOSED = 0;
const float WRIST_UP = 0;
const float WRIST_DOWN = 1.25;


//NAVIGATION VARIABLES
geometry_msgs::Pose2D goalLocation;//the location of the next place he is told to go to
geometry_msgs::Pose2D origin;//the location of the dropoff collection point base
geometry_msgs::Pose2D startingLocation;//steven variable, used for calculating distance travelled in linear travel objectives
bool alreadyFinishedSettingTheAngleHeading = false;//only 1 time

const static float NAVIGATION_ACCURACY = 0.25;//this many meters radius within specified location navigation



geometry_msgs::Pose2D centerLocation;
geometry_msgs::Pose2D centerLocationMap;
geometry_msgs::Pose2D centerLocationOdom;

int currentMode = 0;
float mobilityLoopTimeStep = 0.1; // time between the mobility loop calls
float status_publish_interval = 1;

// Set true when the target block is less than targetDist so we continue
// attempting to pick it up rather than switching to another block in view.
bool lockTarget = false;

// Failsafe state. No legitimate behavior state. If in this state for too long
// return to searching as default behavior.
bool timeOut = false;

// Set to true when the center ultrasound reads less than 0.14m. Usually means
// a picked up cube is in the way.
bool blockBlock = false;

// central collection point has been seen (aka the nest)
bool centerSeen = false;

// Set true when we are insie the center circle and we need to drop the block,
// back out, and reset the boolean cascade.
bool reachedCollectionPoint = false;

// used for calling code once but not in main
volatile bool initRun = true;

//LOOP CONTROL VARIABLES -- done by Steven
volatile bool headedToBaseOverwriteAll = false;
volatile bool giveControlToDropOffController = false;
volatile bool giveControlToPickupController = false;

//more compplicated loop control variables
float correctAngleBearingToPickUpCubePickUpController;


// used to remember place in mapAverage array
int mapCount = 0;

// How many points to use in calculating the map average position
const unsigned int mapHistorySize = 500;

// An array in which to store map positions
geometry_msgs::Pose2D mapLocation[mapHistorySize];

bool avoidingObstacle = false;

//steven code
//float searchVelocity = 0.0;
float searchVelocity = 0.2; // meters/second

std_msgs::String msg;

// state machine states
#define STATE_MACHINE_TRANSFORM (0)
//literally removed rotate
//literally removed skid_steer
//removed state_machine_pickup and replaced with variable giveControlToPickupController. this code now runs inside transform.
//dropoff gone
//removed backup
int stateMachineState = STATE_MACHINE_TRANSFORM;

geometry_msgs::Twist velocity;
char host[128];
string publishedName;	
char prev_state_machine[128];

// Publishers
ros::Publisher stateMachinePublish;
ros::Publisher status_publisher;
ros::Publisher fingerAnglePublish;
ros::Publisher wristAnglePublish;
ros::Publisher infoLogPublisher;
ros::Publisher driveControlPublish;

// Subscribers
ros::Subscriber joySubscriber;
ros::Subscriber modeSubscriber;
ros::Subscriber targetSubscriber;
ros::Subscriber obstacleSubscriber;
ros::Subscriber odometrySubscriber;
ros::Subscriber mapSubscriber;


// Timers
ros::Timer stateMachineTimer;
ros::Timer publish_status_timer;

// records time for delays in sequanced actions, 1 second resolution.
time_t timerStartTime;

// An initial delay to allow the rover to gather enough position data to 
// average its location.
unsigned int startDelayInSeconds = 1;
float timerTimeElapsed = 0;

//Transforms
tf::TransformListener *tfListener;

// OS Signal Handler
void sigintEventHandler(int signal);

//Callback handlers
void joyCmdHandler(const sensor_msgs::Joy::ConstPtr& message);
void modeHandler(const std_msgs::UInt8::ConstPtr& message);
void targetHandler(const apriltags_ros::AprilTagDetectionArray::ConstPtr& tagInfo);
void obstacleHandler(const std_msgs::UInt8::ConstPtr& message);
void odometryHandler(const nav_msgs::Odometry::ConstPtr& message);
void mapHandler(const nav_msgs::Odometry::ConstPtr& message);
void mobilityStateMachine(const ros::TimerEvent&);
void publishStatusTimerEventHandler(const ros::TimerEvent& event);

int main(int argc, char **argv) {

    gethostname(host, sizeof (host));
    string hostname(host);

    // instantiate random number generator
    rng = new random_numbers::RandomNumberGenerator();





    centerLocation.x = 0;//i dont use this stuff really
    centerLocation.y = 0;
    centerLocationOdom.x = 0;
    centerLocationOdom.y = 0;

    for (int i = 0; i < 100; i++) {
        mapLocation[i].x = 0;
        mapLocation[i].y = 0;
        mapLocation[i].theta = 0;
    }

    if (argc >= 2) {
        publishedName = argv[1];
        cout << "Welcome to the world of tomorrow " << publishedName
             << "!  Mobility turnDirectionule started." << endl;
    } else {
        publishedName = hostname;
        cout << "No Name Selected. Default is: " << publishedName << endl;
    }

    // NoSignalHandler so we can catch SIGINT ourselves and shutdown the node
    ros::init(argc, argv, (publishedName + "_MOBILITY"), ros::init_options::NoSigintHandler);
    ros::NodeHandle mNH;

    // Register the SIGINT event handler so the node can shutdown properly
    signal(SIGINT, sigintEventHandler);

    joySubscriber = mNH.subscribe((publishedName + "/joystick"), 10, joyCmdHandler);
    modeSubscriber = mNH.subscribe((publishedName + "/mode"), 1, modeHandler);
    targetSubscriber = mNH.subscribe((publishedName + "/targets"), 10, targetHandler);
    obstacleSubscriber = mNH.subscribe((publishedName + "/obstacle"), 10, obstacleHandler);
    odometrySubscriber = mNH.subscribe((publishedName + "/odom/filtered"), 10, odometryHandler);
    mapSubscriber = mNH.subscribe((publishedName + "/odom/ekf"), 10, mapHandler);

    status_publisher = mNH.advertise<std_msgs::String>((publishedName + "/status"), 1, true);
    stateMachinePublish = mNH.advertise<std_msgs::String>((publishedName + "/state_machine"), 1, true);
    fingerAnglePublish = mNH.advertise<std_msgs::Float32>((publishedName + "/fingerAngle/cmd"), 1, true);
    wristAnglePublish = mNH.advertise<std_msgs::Float32>((publishedName + "/wristAngle/cmd"), 1, true);
    infoLogPublisher = mNH.advertise<std_msgs::String>("/infoLog", 1, true);
    driveControlPublish = mNH.advertise<geometry_msgs::Twist>((publishedName + "/driveControl"), 10);

    publish_status_timer = mNH.createTimer(ros::Duration(status_publish_interval), publishStatusTimerEventHandler);
    stateMachineTimer = mNH.createTimer(ros::Duration(mobilityLoopTimeStep), mobilityStateMachine);
//http://docs.ros.org/jade/api/roscpp/html/classros_1_1NodeHandle.html#a3a267bf5bac429dc0948ca0bd0492a16
	/*
Timer ros::NodeHandle::createTimer 	( 	Duration  	period,
		void(T::*)(const TimerEvent &) const  	callback,
		T *  	obj,
		bool  	oneshot = false,
		bool  	autostart = true 
	) 		const [inline]

Create a timer which will call a callback at the specified rate. This variant takes a class member function, and a bare pointer to the object to call the method on.

When the Timer (and all copies of it) returned goes out of scope, the timer will automatically be stopped, and the callback will no longer be called.

Parameters:
    period	The period at which to call the callback
    callback	The method to call
    obj	The object to call the method on
    oneshot	If true, this timer will only fire once
    autostart	If true (default), return timer that is already started 

	*/

    tfListener = new tf::TransformListener();
    std_msgs::String msg;
    msg.data = "Log Started";
    infoLogPublisher.publish(msg);

    stringstream ss;
    ss << "Rover start delay set to " << startDelayInSeconds << " seconds";
    msg.data = ss.str();
    infoLogPublisher.publish(msg);

    timerStartTime = time(0);

    ros::spin();

    return EXIT_SUCCESS;
}

void initializeStuff()
{
std_msgs::Float32 fingerAngle,wristAngle;
fingerAngle.data = 0; wristAngle.data = 0;
    // close fingers
    fingerAnglePublish.publish(fingerAngle);
    // raise wrist
    wristAnglePublish.publish(wristAngle);


searchController.setState(SearchController::SETTING_INITIAL_HEADING);

//the origin is supposed to be like 50cm in front of him
origin.x = currentLocation.x + 0.50 * cos(currentLocation.theta);
origin.y = currentLocation.y + 0.50 * sin(currentLocation.theta);

setDestination(origin.x,origin.y);
print("done initializing");
}

//NOTE: this cannot be used until the publishers are set up!! this caused my robot to not appear on the list and gave me a runtime error!
//another note: SetDestination is part of normal movement controller, and is #Trumped by other control handler booleans. 
//steven code. used in pickupcontroller and sets the angle for you. cos thats how it should be done.
void setDestination(float x, float y)
{
if (headedToBaseOverwriteAll)
{
goalLocation.x = origin.x;
goalLocation.y = origin.y;
print("headed to base");
}
else
{
print("just set the new dest");
goalLocation.x = x;
goalLocation.y = y;
}
goalLocation.theta = atan2(y - currentLocation.y, x - currentLocation.x);

//reaching the goal control variables: used in bool travelledFarEnough & stuff
startingLocation.x = currentLocation.x;
startingLocation.y = currentLocation.y;
alreadyFinishedSettingTheAngleHeading = false;
searchController.setState(SearchController::SETTING_INITIAL_HEADING);
//now let the state machine go back to doing the navigating as before.
}

//not quite the same as setDestination
void setDestinationAngular(float angle, float distance)
{
goalLocation.x = currentLocation.x + distance * cos(currentLocation.theta + angle);
goalLocation.y = currentLocation.y + distance * sin(currentLocation.theta+angle);
goalLocation.theta = atan2(goalLocation.y - currentLocation.y, goalLocation.x - currentLocation.x);
}



/*
because ROS doesnt like the Sleep() function (it stacks it up improperly i guess)


Note that this code is placed after all the other movement code, so as to overwrite it.
*/
float driveOnTimerVelocity, driveOnTimerTorque, driveOnTimerDuration;
ros::Time driveOnTimerStartingTime;
bool isDoingDriveOnTimer = false;//this boolean value is meant to trump all other forms of movement.
bool hasBeenLongEnoughForDriveOnTimer()
{
ros::Duration timeDifferenceObject = ros::Time::now() - driveOnTimerStartingTime;
return (timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) > driveOnTimerDuration;
}

void driveOnTimer(float velocity, float torque, float duration)
{
isDoingDriveOnTimer = true;
driveOnTimerStartingTime = ros::Time::now();
driveOnTimerVelocity = velocity; driveOnTimerTorque = torque; driveOnTimerDuration = duration;
}
//instead of calling pickupController.reset
void resetPickUpController()
{
pickUpController.reset();
giveControlToPickupController = false;
}
void resetDropOffController()
{
dropOffController.reset();
giveControlToDropOffController = false;

}

//returns angleError

void doPickupControllerMovements()
{
if (pickUpController.getState() == pickUpController.DONE_FAILING)
{
resetPickUpController();
geometry_msgs::Pose2D tempLocation = searchController.search(currentLocation);
setDestination(tempLocation.x,tempLocation.y);
return;
}



PickUpResult result;

                result = pickUpController.pickUpSelectedTarget(blockBlock);
	if (pickUpController.getState() == pickUpController.FIXING_CAMERA)
		{
		//THIS STATE is handled in mobility because i dont have enough control over it inside pickupcontroller.cpp


//		float blockYawError = currentLocation.theta - correctAngleBearingToPickUpCubePickUpController;
float myAngle;
float goodAngle;
float twopi = 2*3.1415926535;
float pi = twopi / 2;
float tolerance = 0.10;

myAngle = currentLocation.theta;
goodAngle = correctAngleBearingToPickUpCubePickUpController;
while(myAngle < 0)
	myAngle = myAngle + twopi;
while (myAngle > twopi)
	myAngle = myAngle - twopi;
while (goodAngle < 0)
	goodAngle = goodAngle + twopi;
while (goodAngle > twopi)
	goodAngle = goodAngle - twopi;



float blockYawError = myAngle - goodAngle;
if (blockYawError < 0)
{
while (blockYawError < -pi)
	blockYawError = blockYawError + twopi;
}
else if (blockYawError > 0)
{
while(blockYawError > pi)
	blockYawError = blockYawError - twopi;

}


		if (blockYawError > tolerance)
		   result.angleError = 0.20;	
		else if (blockYawError < -tolerance)
		   result.angleError = -0.20;
		else //if its good!
		{
			result.angleError = 0;
			pickUpController.state = pickUpController.APPROACHING_CUBE;
			pickUpController.omniTimerStartingTime = ros::Time::now();
		}
		result.fingerAngle = FINGERS_OPEN;
		result.wristAngle = WRIST_DOWN;

		}//end STATE FIXING_CAMERA


const string stateNames[] = {"FIXING_CAMERA", "APPROACHING_CUBE", "PICKING_UP_CUBE","VERIFYING_PICKUP", "PICKUP_FAILED_BACK_UP","DONE_FAILING","DONE_SUCCESS","WAIT_BEFORE_RAISING_WRIST"};
print(stateNames[pickUpController.getState()]);

if (result.angleError != 0 && result.cmdVel == 0)
	sendDriveCommand(0.05,-1*result.angleError);
else
	sendDriveCommand(result.cmdVel,-1*result.angleError);

                std_msgs::Float32 fingerAngle;
		std_msgs::Float32 wristAngle;

		//copy fingers if valid value
                if (result.fingerAngle != -1) {
                    fingerAngle.data = result.fingerAngle;
                    fingerAnglePublish.publish(fingerAngle);
                }
		//copy new settings of wrist
                if (result.wristAngle != -1) {
                    wristAngle.data = result.wristAngle;
		    wristAnglePublish.publish(wristAngle);
                }
		//rip
                if (result.giveUp) {
			print("giving up!! D::: lol ");
                    sendDriveCommand(0,0);
                    resetPickUpController();
                }
		//got da cube! time 2 bring it home~
                if (result.pickedUp) {
                    resetPickUpController();

//the cube was just picked up! set the destination to the origin!
                    result.pickedUp = false;

//setting the destination to the origin ...
headedToBaseOverwriteAll = true;
setDestination(origin.x, origin.y);
giveControlToPickupController = false;
                    
		// lower wrist to avoid ultrasound sensors
                    std_msgs::Float32 angle;
                    angle.data = 0.8;
                    wristAnglePublish.publish(angle);

                    return;
                }



            


}//end doPickupControllerMovements
void doDropOffControllerMovements()
{
//state machine is handled in here
const string stateNames[] = {"FINDING_BASE","ADJUSTING_ANGLE_FOR_ENTRY","ENTERING_BASE","DROPPING_CUBE","BACKING_OUT_OF_BASE","DONE_DROPPING_OFF"
		,"PAUSING_BEFORE_ROTATING_AGAIN","SCOOTING_CLOSER_TO_BASE"};
print(stateNames[dropOffController.getState()]);
const int countLeft = dropOffController.getCountLeft();
const int countRight = dropOffController.getCountRight();

stringstream ss;
float duration;
ros::Duration timeDifferenceObject;
std_msgs::Float32 fingerAngle;
std_msgs::Float32 wristAngle;

dropOffController.setTagCountToZeroIfAppropriate();


switch(dropOffController.getState()) {
case (DropOffController::FINDING_BASE):
//spin until you find a tag
if (countLeft > 0 || countRight > 0)
{
	//found the base!
	dropOffController.numTimesPausedAndTurned = 0;//reset this value to 0
	dropOffController.setState(DropOffController::SCOOTING_CLOSER_TO_BASE);
	sendDriveCommand(0,0);
	dropOffController.omniTimerStartingTime = ros::Time::now();//reset the timer again
}
else
{
//spin in oval i guess xd
sendDriveCommand(0.05,0.35);
}

break;

case (DropOffController::SCOOTING_CLOSER_TO_BASE):
//radiusTho = 0;
duration = 0.50 - 0.50;
timeDifferenceObject = ros::Time::now() - dropOffController.omniTimerStartingTime;
if ((timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) < duration)
{
//scoot!
sendDriveCommand(0.20,0);
}
else
{

//done scooting
dropOffController.setState(DropOffController::ADJUSTING_ANGLE_FOR_ENTRY);
sendDriveCommand(0,0);
}

break;

//it just saw the base tag so lets rotate and find more
case (DropOffController::ADJUSTING_ANGLE_FOR_ENTRY):
duration = 0.75;
	if (countLeft == 0 && countRight == 0) 
	{
	//go back if theres no tags seen lately
	dropOffController.setState(DropOffController::FINDING_BASE);
	break;
	}

timeDifferenceObject = ros::Time::now() - dropOffController.omniTimerStartingTime;
if ((timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) < duration)
{
if (countRight > countLeft)
	sendDriveCommand(0.05,-0.30);
else
	sendDriveCommand(0.05,0.30);
}
else
{
  sendDriveCommand(0,0);
    if (countLeft > 4 && countRight > 4)
	dropOffController.setState(DropOffController::ENTERING_BASE);
    else
	{
	dropOffController.numTimesPausedAndTurned++;
	if (dropOffController.numTimesPausedAndTurned > DropOffController::giveUpAndDropAfterTurningThisManyTimes)
		dropOffController.setState(DropOffController::DROPPING_CUBE);//give up and drop the cube
	else
		dropOffController.setState(DropOffController::PAUSING_BEFORE_ROTATING_AGAIN);
	}
  dropOffController.omniTimerStartingTime = ros::Time::now();//reset the timer again
}//end if/else
break;

case (DropOffController::PAUSING_BEFORE_ROTATING_AGAIN):
duration = 2.0;
timeDifferenceObject = ros::Time::now() - dropOffController.omniTimerStartingTime;
if ((timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) < duration)
;//wait
else
{
dropOffController.setState(DropOffController::ADJUSTING_ANGLE_FOR_ENTRY);
dropOffController.omniTimerStartingTime = ros::Time::now();//reset the timer again
}

break;

case (DropOffController::ENTERING_BASE):
duration = 2.0;
timeDifferenceObject = ros::Time::now() - dropOffController.omniTimerStartingTime;
if ((timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) < duration)
{
// move forward into base
sendDriveCommand(0.20,0);
}
else
{
//stop and goto drop cube
sendDriveCommand(0,0);
dropOffController.setState(DropOffController::DROPPING_CUBE);
}

break;


case (DropOffController::DROPPING_CUBE):
//open the angle to drop the cube
fingerAngle.data = M_PI_2;
fingerAnglePublish.publish(fingerAngle);
//wrist up
wristAngle.data = 0;
wristAnglePublish.publish(wristAngle);

//re-calibrate the origin!

origin.x = currentLocation.x;
origin.y = currentLocation.y;
origin.theta = currentLocation.theta;


dropOffController.setState(DropOffController::BACKING_OUT_OF_BASE);
dropOffController.omniTimerStartingTime = ros::Time::now();//reset the timer again
break;

case (DropOffController::BACKING_OUT_OF_BASE):
duration = 4.0;
timeDifferenceObject = ros::Time::now() - dropOffController.omniTimerStartingTime;
if ((timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) < duration)
{
//back out
sendDriveCommand(-0.20,0);
}
else
{
//stop
sendDriveCommand(0,0);
dropOffController.setState(DropOffController::DONE_DROPPING_OFF);
}

break;

case (DropOffController::DONE_DROPPING_OFF):
//close the angle
fingerAngle.data = 0;
fingerAnglePublish.publish(fingerAngle);


resetDropOffController();

break;

default:
dropOffController.setState(DropOffController::FINDING_BASE);
break;


}//end switch


}//end doDropOffControllerMovements

/*
travelledFarEnough is used for search algorithm (the destination thing)
if he has travelled euclidean distance of the proposed search then he is good.

its a new approach, instead of saying "if he is within 30cm of his goal" or whatever
*/
const float percentageTravelCounter = 1.00;//this should be a value from like 0.70 to 1.00
bool travelledFarEnough()
{
float distanceFromStartToFinish = hypot(goalLocation.x - startingLocation.x, goalLocation.y - startingLocation.y);
float currentDistanceFromStart = hypot(startingLocation.x - currentLocation.x, startingLocation.y - currentLocation.y);

return (currentDistanceFromStart / distanceFromStartToFinish) >= percentageTravelCounter;
}

void doFreeMovementStuff()
{
float rotateOnlyAngleTolerance = 0.10;
//print debug stuff
float errorYaw = angles::shortest_angular_distance(currentLocation.theta, goalLocation.theta);
stringstream ss;

float duration;//for use in switch
float currentDistanceFromBase;

print(searchController.getStateName());


switch (searchController.getState()) {
//const static int SETTING_INITIAL_HEADING = 0, WAITING_FOR_MOMENTUM_BEFORE_MOVING = 1, MOVING_TO_GOAL = 2, REACHED_GOAL = 3, REACHED_GOAL_PAUSE=4;


case (SearchController::SETTING_INITIAL_HEADING):
if (fabs(errorYaw) > rotateOnlyAngleTolerance)
	//if the angle is not set good enough yet
	sendDriveCommand(0.05, errorYaw);
else
{
	//else it the angle is done being fixed
	searchController.omniTimerStartingTime = ros::Time::now();
	searchController.setState(SearchController::WAITING_FOR_MOMENTUM_BEFORE_MOVING);
}
break;
case (SearchController::WAITING_FOR_MOMENTUM_BEFORE_MOVING):
duration = 1.0;
searchController.timeDifferenceObject = ros::Time::now() - searchController.omniTimerStartingTime;
if ((searchController.timeDifferenceObject.sec + searchController.timeDifferenceObject.nsec/1000000000.0) < duration)
{
sendDriveCommand(0,0);
//do nothing. just wait before turning.
}
else
{
if (fabs(errorYaw) > rotateOnlyAngleTolerance)
	searchController.setState(SearchController::SETTING_INITIAL_HEADING);
else
	searchController.setState(SearchController::MOVING_TO_GOAL);
}

break;

case (SearchController::MOVING_TO_GOAL):

if (!travelledFarEnough())
{
//keep marching to goal. stay in this state.
sendDriveCommand(searchVelocity,0);
}
else//it has travelled far enough. check if it is within range of goal, and then change state.
{
//stop it!
sendDriveCommand(0,0);
if (hypot(currentLocation.x - goalLocation.x , currentLocation.y - goalLocation.y) > NAVIGATION_ACCURACY)
{
//reset everything and travel to the destination again.
setDestination(goalLocation.x,goalLocation.y);
}
else //if close enough to the destination
{
searchController.setState(SearchController::REACHED_GOAL_PAUSE);
}//end else distance>1


}//end else travelledFarEnough()






break;

case (SearchController::REACHED_GOAL_PAUSE):
duration = 1.00;
searchController.timeDifferenceObject = ros::Time::now() - searchController.omniTimerStartingTime;
if ((searchController.timeDifferenceObject.sec + searchController.timeDifferenceObject.nsec/1000000000.0) < duration)
{
//do nothing

}
else
{
searchController.setState(SearchController::REACHED_GOAL);
}

break;

case (SearchController::REACHED_GOAL):
searchController.setState(SearchController::REACHED_GOAL);

//choose a new heading if we have none!        

print("picking new destination");
geometry_msgs::Pose2D tempLocation;
if (travelledFarEnough())
	tempLocation = searchController.search(goalLocation);
else
	tempLocation = searchController.search(currentLocation);

  setDestination(tempLocation.x,tempLocation.y);


break;

}//end switch


}//end doFreeMovementStuff
void doDriveOnTimerStuff()
{

sendDriveCommand(driveOnTimerVelocity,driveOnTimerTorque);


if (hasBeenLongEnoughForDriveOnTimer()) {
isDoingDriveOnTimer = false;
print("TIMER EXPIRED");
continueInterruptedSearch();
}
}//end doDriveOnTimerStuff

void mobilityStateMachine(const ros::TimerEvent&) {

if (initRun && (currentMode == 2 || currentMode == 3) )
{
initializeStuff();
initRun = false;
return;
}

    std_msgs::String stateMachineMsg;
    
    int returnToSearchDelay = 3;

    // calls the averaging function, also responsible for
    // transform from Map frame to odom frame. its important this is called in manual mode because the map data still changes in manual mode.
    mapAverage();

    // Robot is in automode
    if (currentMode == 2 || currentMode == 3) {



        // Select rotation or translation based on required adjustment
        switch(stateMachineState) {

        // If no adjustment needed, select new goal
        case STATE_MACHINE_TRANSFORM: {
            stateMachineMsg.data = "TRANSFORMING";



if (giveControlToPickupController == true)
{
doPickupControllerMovements();
}

//really needing to do a clean surgery replacement of this if() with dropoff controller variable. But avoidingObstacle is important/unhandled right now
if (giveControlToDropOffController)// && !avoidingObstacle)
{
doDropOffControllerMovements();
}

if (!isDoingDriveOnTimer && !giveControlToPickupController && !giveControlToDropOffController)//some of the code in here fires when target is Collected (the code to return to base for example)
{
doFreeMovementStuff();
}

//driveOnTimer overwrites everything, so you have to be careful what you allow to start it. This could be problematic for pickup controller?
if (isDoingDriveOnTimer)
{
doDriveOnTimerStuff();
}

		break;
 	 }//end case_transform

///////////////////////////////////////////////////////////////
        
	
        default: {
            break;
        }

        } /* end of switch() */
    }
    // mode is NOT auto
    else {
        // publish current state for the operator to see
        stateMachineMsg.data = "WAITING";
    }

    // publish state machine string for user, only if it has changed, though
    if (strcmp(stateMachineMsg.data.c_str(), prev_state_machine) != 0) {
        stateMachinePublish.publish(stateMachineMsg);
        sprintf(prev_state_machine, "%s", stateMachineMsg.data.c_str());
    }
}

void sendDriveCommand(double linearVel, double angularError)
{


    velocity.linear.x = linearVel,
    velocity.angular.z = angularError;

    velocity.angular.z *= 0.75;//slow it down for picking up blocks

float minStrength = 0.135;
//cos it doesnt spin in this case
if (velocity.angular.z != 0 && fabs(velocity.angular.z) < minStrength)
	if (velocity.angular.z < 0)//if its negative
		velocity.angular.z = -minStrength;
	else//else if its postive
		velocity.angular.z = minStrength;


    // publish the drive commands
    driveControlPublish.publish(velocity);
}



void print(string str)
{
std_msgs::String msg;
msg.data = str;
infoLogPublisher.publish(msg);
}
void print(float f)
{
stringstream ss;
ss << "" << f;
print(ss.str());
}
void print(int i)
{
stringstream ss;
ss << "" << i;
print(ss.str());
}

/*
"search" can be interrupted by collision of a obstacle or detection of a base or something
*/
void continueInterruptedSearch()//for use when traveling across the field: either towards dropping off, or headed out to cubes.
{

//list all of the special cases in here. this is if the robot needs to remember the last path it was taking. otherwise just assign a new random path.
if (headedToBaseOverwriteAll == true)
{
setDestination(origin.x, origin.y);
}
else
{
print("collision found. changing route");
geometry_msgs::Pose2D tempLocation = searchController.search(currentLocation);
setDestination(tempLocation.x,tempLocation.y);
}




}//end continueinterruptedsearch


void doHitTheBaseCode()
{
//he just detected one of the base tags
if (headedToBaseOverwriteAll) {
headedToBaseOverwriteAll = false;
giveControlToDropOffController = true;
}
}

/*************************
 * ROS CALLBACK HANDLERS *
 *************************/



//this is called if it sees either a Base tag, or a Cube tag. the first half of the code here handles Base tag and returns.
void targetHandler(const apriltags_ros::AprilTagDetectionArray::ConstPtr& message) {

    // If in manual mode do not try to automatically pick up the target
    if (currentMode == 1 || currentMode == 0)
        return;

    // if a target is detected and we are looking for center tags
    if (message->detections.size() > 0) 
{
        float cameraOffsetCorrection = 0.020; //meters;

        centerSeen = false;
        int countRight = 0;
        int countLeft = 0;

        // this loop is to get the number of center tags
        for (int i = 0; i < message->detections.size(); i++) {
            if (message->detections[i].id == 256) {
                geometry_msgs::PoseStamped cenPose = message->detections[i].pose;

                // checks if tag is on the right or left side of the image
                if (cenPose.pose.position.x + cameraOffsetCorrection > 0) {
                    countRight++;//i like this 

                } else {
                    countLeft++;
                }//end if

		//if at least 1 tag is seen then centerSeen is true
                centerSeen = true;
            }//end if 256
        }//end for



//dropoff tag stuff
if (countLeft > 0 || countRight > 0)
{
dropOffController.setDataTargets(countLeft,countRight);//has the number of left and right 256 tags (the base tags)

        if (centerSeen && headedToBaseOverwriteAll)
		doHitTheBaseCode();

	//to avoid the center blocks if they are considered an obstacle
	if (!giveControlToDropOffController)
		driveOnTimer(0.05,0.55,1);
	
	continueInterruptedSearch();


	//note that cubes inside or around the base should not be grabbed

        resetPickUpController();//cos you dont want to pick up cubes inside or around the base
        return;
}//end if dropoff code
        }//end if more than 0 tags (base or cube) are detected


	//start of pickup code

    PickUpResult result;
    if (message->detections.size() > 0 && !giveControlToDropOffController && !headedToBaseOverwriteAll) {
if (!giveControlToPickupController)
	print("GIVING CONTROL TO PICKUP CONTROLLER");

result = pickUpController.selectTarget(message);
if (!giveControlToPickupController)//this code runs once per "state change"
{
	//because sometimes its still avoiding an obstacle or something but then it sees the block and it forgets to fix the angle after it finishes doing drive on timer
	isDoingDriveOnTimer = false;
	sendDriveCommand(0,0);
	//its a snapshot
	pickUpController.setDistanceToBlockUponFirstSight(result.blockDist,result.blockYawError);
	//corrects the angle, first, inside of mobility.cpp in the pickup area.
	correctAngleBearingToPickUpCubePickUpController = currentLocation.theta - result.blockYawError;
}

if (!giveControlToPickupController)
{
	std_msgs::Float32 fingerAngle;
	std_msgs::Float32 wristAngle;
//copy fingers if valid value
                if (result.fingerAngle != -1) {
                    fingerAngle.data = result.fingerAngle;
                    fingerAnglePublish.publish(fingerAngle);
                }
		//copy new settings of wrist
                if (result.wristAngle != -1) {
                    wristAngle.data = result.wristAngle;
		    wristAnglePublish.publish(wristAngle);
                }
}
//true = true = true = true until its not
giveControlToPickupController = true;

    }//end of found at least 1 cube tag
}//end targetHandler callback

void modeHandler(const std_msgs::UInt8::ConstPtr& message) {
stringstream ss;
ss << "changing mode from " << currentMode << " to " << (int)(message->data);
print(ss.str());
    currentMode = message->data;

    sendDriveCommand(0.0, 0.0);
}

void obstacleHandler(const std_msgs::UInt8::ConstPtr& message) {

if (! (currentMode == 2 || currentMode == 3)) return; //its in manual mode so dont move it pls

    if (message->data > 0) {



        // obstacle on right side
        if (message->data == 1) {
            // select new heading 0.2 radians to the left
if (!isDoingDriveOnTimer && !headedToBaseOverwriteAll && !giveControlToPickupController)	//because the cube blocks the sensor    
{
print("obstacle on right. turning left");
driveOnTimer(0.05,0.55,1.0);
}

        }

        // obstacle in front or on left side
        else if (message->data == 2) {
            // select new heading 0.2 radians to the right
if (!isDoingDriveOnTimer && !headedToBaseOverwriteAll && !giveControlToPickupController)//because the cube blocks the sensor
{
print("obstacle on left. turning right");
driveOnTimer(0.05,0.55,1.0);
}


        }

    }

    // the front ultrasond is blocked very closely. 0.14m currently. this is very important code as it tells us when the block has been picked up.
    if (message->data == 4) {
        blockBlock = true;
    } else {
        blockBlock = false;
    }
}

void odometryHandler(const nav_msgs::Odometry::ConstPtr& message) {
    //Get (x,y) location directly from pose
    currentLocation.x = message->pose.pose.position.x;
    currentLocation.y = message->pose.pose.position.y;

    //Get theta rotation by converting quaternion orientation to pitch/roll/yaw
    tf::Quaternion q(message->pose.pose.orientation.x, message->pose.pose.orientation.y, message->pose.pose.orientation.z, message->pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    currentLocation.theta = yaw;
}

void mapHandler(const nav_msgs::Odometry::ConstPtr& message) {
    //Get (x,y) location directly from pose
    currentLocationMap.x = message->pose.pose.position.x;
    currentLocationMap.y = message->pose.pose.position.y;

    //Get theta rotation by converting quaternion orientation to pitch/roll/yaw
    tf::Quaternion q(message->pose.pose.orientation.x, message->pose.pose.orientation.y, message->pose.pose.orientation.z, message->pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    currentLocationMap.theta = yaw;
}

void joyCmdHandler(const sensor_msgs::Joy::ConstPtr& message) {
    if (currentMode == 0 || currentMode == 1) {
        sendDriveCommand(abs(message->axes[4]) >= 0.1 ? message->axes[4] : 0, abs(message->axes[3]) >= 0.1 ? message->axes[3] : 0);
    }
}


void publishStatusTimerEventHandler(const ros::TimerEvent&) {
    std_msgs::String msg;
    msg.data = "online";
    status_publisher.publish(msg);
}




void sigintEventHandler(int sig) {
    // All the default sigint handler does is call shutdown()
    ros::shutdown();
}

void mapAverage() {
    // store currentLocation in the averaging array
    mapLocation[mapCount] = currentLocationMap;
    mapCount++;

    if (mapCount >= mapHistorySize) {
        mapCount = 0;
    }

    double x = 0;
    double y = 0;
    double theta = 0;

    // add up all the positions in the array
    for (int i = 0; i < mapHistorySize; i++) {
        x += mapLocation[i].x;
        y += mapLocation[i].y;
        theta += mapLocation[i].theta;
    }

    // find the average
    x = x/mapHistorySize;
    y = y/mapHistorySize;
    
    // Get theta rotation by converting quaternion orientation to pitch/roll/yaw
    theta = theta/100;
    currentLocationAverage.x = x;
    currentLocationAverage.y = y;
    currentLocationAverage.theta = theta;


    
}

