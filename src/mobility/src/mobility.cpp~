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
void resetPickupController();

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
const int NAVI_SETTING_INITIAL_HEADING = 0, NAVI_WAITING_FOR_MOMENTUM_BEFORE_MOVING = 1, NAVI_MOVING = 2, NAVI_REACHED_GOAL = 3,NAVI_REACHED_GOAL_PAUSE=4;
int navi_state = NAVI_SETTING_INITIAL_HEADING;
ros::Duration navi_timeDifferenceObject;
ros::Time navi_omniTimerStartingTime;



geometry_msgs::Pose2D centerLocation;
geometry_msgs::Pose2D centerLocationMap;
geometry_msgs::Pose2D centerLocationOdom;

int currentMode = 0;
float mobilityLoopTimeStep = 0.1; // time between the mobility loop calls
float status_publish_interval = 1;
float killSwitchTimeout = 10;
bool targetDetected = false;
bool targetCollected = false;

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
bool init = false;

bool reachedGoalLocation = false;//steven variable. this is in conjunction with setDestination. it means "reached next transformation destination"

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
ros::Timer targetDetectedTimer;

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
void targetDetectedReset(const ros::TimerEvent& event);

int main(int argc, char **argv) {

    gethostname(host, sizeof (host));
    string hostname(host);

    // instantiate random number generator
    rng = new random_numbers::RandomNumberGenerator();

origin.theta = 0;//means nothing in the code im pretty sure cos usually we use setDestination(float,float)
origin.x = 0;
origin.y = 0;

//setDestination(1.0, 0.0);
goalLocation.x = -0.5;
goalLocation.y = 0;
goalLocation.theta = 3.14;


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
    targetDetectedTimer = mNH.createTimer(ros::Duration(0), targetDetectedReset, true);//http://docs.ros.org/jade/api/roscpp/html/classros_1_1NodeHandle.html#a3a267bf5bac429dc0948ca0bd0492a16
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
print("its doing this one");
goalLocation.x = x;
goalLocation.y = y;
}
goalLocation.theta = atan2(y - currentLocation.y, x - currentLocation.x);
stateMachineState = STATE_MACHINE_TRANSFORM;

//reaching the goal control variables: used in bool travelledFarEnough & stuff
startingLocation.x = currentLocation.x;
startingLocation.y = currentLocation.y;
reachedGoalLocation = false;
alreadyFinishedSettingTheAngleHeading = false;
navi_state = NAVI_SETTING_INITIAL_HEADING;
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
stateMachineState = STATE_MACHINE_TRANSFORM;
}
//instead of calling pickupController.reset
void resetPickupController()
{
pickUpController.reset();
giveControlToPickupController = false;
targetDetected = false;
}

//returns angleError

void doPickupControllerMovements()
{
if (pickUpController.getState() == pickUpController.DONE_FAILING)
{
resetPickupController();
geometry_msgs::Pose2D tempLocation = searchController.search(currentLocation);
setDestination(tempLocation.x,tempLocation.y);
}



PickUpResult result;

            // we see a block and have not picked one up yet
            if (targetDetected && !targetCollected) {
                result = pickUpController.pickUpSelectedTarget(blockBlock);
	if (pickUpController.getState() == pickUpController.FIXING_CAMERA)
		{
		//THIS STATE is handled in mobility because i dont have enough control over it inside pickupcontroller.cpp
		float blockYawError = currentLocation.theta - correctAngleBearingToPickUpCubePickUpController;
		if (blockYawError > 0.1 || blockYawError < -0.1)
			result.angleError = blockYawError;
		else
		{
			result.angleError = 0;
			pickUpController.state = pickUpController.APPROACHING_CUBE;
			pickUpController.omniTimerStartingTime = ros::Time::now();
		}
		result.fingerAngle = FINGERS_OPEN;
		result.wristAngle = WRIST_DOWN;

		}//end STATE FIXING_CAMERA

stringstream ss;
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
                    targetDetected = false;
                    sendDriveCommand(0,0);
                    resetPickupController();
                }
		//got da cube! time 2 bring it home~
                if (result.pickedUp) {
print("@@@@@@GOT IT   GOT THE CUBE DESU@@@@@@@@@@@");
                    resetPickupController();

                    // assume target has been picked up by gripper
                    targetCollected = true;
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
            } 

else {
if (targetCollected)
	print("the target is collected!");
//cube is collected?
//i guess if we are holding the cube then keep going.  
print("going to state machine transform i guess");

            }




        /*// time since timerStartTime was set to current time
        timerTimeElapsed = time(0) - timerStartTime;

       //one time init code runs here
        if (!init) {
            if (timerTimeElapsed > startDelayInSeconds) {
                centerLocationMap.x = currentLocationAverage.x;
                centerLocationMap.y = currentLocationAverage.y;
                centerLocationMap.theta = currentLocationAverage.theta;
                init = true;//never run again
            } else {
		//wait for the start delay
                return;
            }

        }

        //if just travelling normally then reset claw values
        if (!targetCollected && !targetDetected) {
            // set gripper
            std_msgs::Float32 angle;
	    // open fingers
            angle.data = M_PI_2;fingerAnglePublish.publish(angle);angle.data = 0;
            // raise wrist
            wristAnglePublish.publish(angle);
        }*/



}//end doPickupControllerMovements
void doDropOffControllerMovements()
{
if (targetCollected && !avoidingObstacle) {
                // calculate the euclidean distance between
                // centerLocation and currentLocation
                dropOffController.setCenterDist(hypot(origin.x - currentLocation.x, origin.y - currentLocation.y));
                dropOffController.setDataLocations(origin, currentLocation, timerTimeElapsed);
                DropOffResult result = dropOffController.getState();
//DROPOFF CONTROLLER
                if (result.timer) {
                    timerStartTime = time(0);
                    reachedCollectionPoint = true;
                }

                std_msgs::Float32 fingerAngle;
		std_msgs::Float32 wristAngle;

//if he set the finger angle, then set it to the one he gave.
                if (result.fingerAngle != -1) {
                    fingerAngle.data = result.fingerAngle;
                    fingerAnglePublish.publish(fingerAngle);
                }
//if he set the wrist angle, then set it to the one he gave.
                if (result.wristAngle != -1) {
                    wristAngle.data = result.wristAngle;
                    wristAnglePublish.publish(wristAngle);
                }

//what does reset mean? does it mean he is done taking control of the robot desu?
                if (result.reset) {
                    timerStartTime = time(0);
                    targetCollected = false;
                    targetDetected = false;
                    lockTarget = false;
                    sendDriveCommand(0.0,0);

                    // move back to transform step
                    stateMachineState = STATE_MACHINE_TRANSFORM;
                    reachedCollectionPoint = false;
                    centerLocationOdom = currentLocation;//literally what the fuck lol

                    dropOffController.reset();
                }
                //dropoff is controlling robo movement. not mobility.
                else if (result.goalDriving == false) { 
                    reachedGoalLocation = true; 
                    sendDriveCommand(result.cmdVel,result.angleError);//let the dropoffcontroller do the navigation
                    stateMachineState = STATE_MACHINE_TRANSFORM;//force the machine state to stay in transform and no backup or pickup bullshit

                    return;
                }//end if
               }//END TARGETCOLLECTED DROPOFFCONTROLLER

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

const string stateNames[] = {"SETTING_INITIAL_HEADING", "WAITING_FOR_MOMENTUM", "NAVI_MOVING","NAVI_REACHED_GOAL","NAVI_REACHED_GOAL_PAUSE"};

switch (navi_state) {
//const int NAVI_SETTING_INITIAL_HEADING = 0, NAVI_WAITING_FOR_MOMENTUM_BEFORE_MOVING = 1, NAVI_MOVING = 2, NAVI_REACHED_GOAL = 3;

case (NAVI_SETTING_INITIAL_HEADING):
if (!reachedGoalLocation && !targetDetected && !isDoingDriveOnTimer) {
if (fabs(angles::shortest_angular_distance(currentLocation.theta, goalLocation.theta)) > rotateOnlyAngleTolerance)
	sendDriveCommand(0.05, errorYaw);
else
{
	navi_omniTimerStartingTime = ros::Time::now();
	navi_state = NAVI_WAITING_FOR_MOMENTUM_BEFORE_MOVING;
}
}//end if
break;
case (NAVI_WAITING_FOR_MOMENTUM_BEFORE_MOVING):
duration = 1.0;
navi_timeDifferenceObject = ros::Time::now() - navi_omniTimerStartingTime;
if ((navi_timeDifferenceObject.sec + navi_timeDifferenceObject.nsec/1000000000.0) < duration)
{
sendDriveCommand(0,0);
//do nothing. just wait before turning.
}
else
{
if (fabs(angles::shortest_angular_distance(currentLocation.theta, goalLocation.theta)) > rotateOnlyAngleTolerance)
	navi_state = NAVI_SETTING_INITIAL_HEADING;
else
	navi_state = NAVI_MOVING;
}

break;

case (NAVI_MOVING):
if (!reachedGoalLocation && !targetDetected && !isDoingDriveOnTimer) {
sendDriveCommand(searchVelocity,0);
}//end if

//did we reach the goal yet?
if (travelledFarEnough() && !reachedGoalLocation && !isDoingDriveOnTimer) 
{
//stop it!
sendDriveCommand(0,0);
print("REACHED GOAL");
reachedGoalLocation = true;
if (headedToBaseOverwriteAll) {
headedToBaseOverwriteAll = false;
giveControlToDropOffController = true;
}
navi_state = NAVI_REACHED_GOAL_PAUSE;

}//end travelled far enough within .30 meters or whatever


break;

case (NAVI_REACHED_GOAL_PAUSE):
duration = 1.00;
navi_timeDifferenceObject = ros::Time::now() - navi_omniTimerStartingTime;
if ((navi_timeDifferenceObject.sec + navi_timeDifferenceObject.nsec/1000000000.0) < duration)
{
//do nothing

}
else
{
navi_state = NAVI_REACHED_GOAL;
}

break;

case (NAVI_REACHED_GOAL):
navi_state = NAVI_REACHED_GOAL;

//choose a new heading if we have none!        
if (reachedGoalLocation == true && !targetDetected && !isDoingDriveOnTimer) {
print("picking new destination");
geometry_msgs::Pose2D tempLocation;
if (travelledFarEnough())
{
	tempLocation = searchController.search(goalLocation);
stringstream ss;
ss << "heading is " << tempLocation.theta;
print(ss.str());
}
else
	tempLocation = searchController.search(currentLocation);
setDestination(tempLocation.x,tempLocation.y);
      }

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
if (giveControlToDropOffController && targetCollected && !avoidingObstacle)
{
print("DROPOFF CONTROLLER IS DOING STUFF NOW");
doDropOffControllerMovements();
}

if (!isDoingDriveOnTimer && !giveControlToPickupController && !giveControlToDropOffController)//some of the code in here fires when targetCollected (the code to return to base for example)
{
doFreeMovementStuff();
}

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
if (velocity.angular.z != 0 && abs(velocity.angular.z) < minStrength)
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
    if (message->detections.size() > 0 && !reachedCollectionPoint) {
        float cameraOffsetCorrection = 0.020; //meters;

        centerSeen = false;
        double count = 0;
        double countRight = 0;
        double countLeft = 0;

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
		//count-suru all of the tags
                count++;
            }//end if
        }//end for

        if (centerSeen && targetCollected) {
headedToBaseOverwriteAll = false;//cos obviously im at the base
            stateMachineState = STATE_MACHINE_TRANSFORM;
print("not really sure what it does here to be quite honest desu");
reachedGoalLocation = true;
        }//end if

//by "targets" it means the base tags. even though "target" refers to the cubes half the time in this shit code.
        dropOffController.setDataTargets(count,countLeft,countRight);//has the number of left and right 256 tags (the base tags)

        // if we see the center and we dont have a cube in our hand
        if (centerSeen && !targetCollected) {


            // this code keeps the robot from driving over the center when searching for blocks
            if (right) {//literally where is this defined
                // turn away from the center to the left if just driving
                // around/searching.
	print("am i turning backwards? if so flip me right");
	driveOnTimer(0.05,0.55,1);
            } else {
	print("am i turning backwards? if so flip me left");
	driveOnTimer(0.05,-0.55,1);
            }


continueInterruptedSearch();

            targetDetected = false;//cos cubes around or inside the base dont count
            resetPickupController();//cos you dont want to pick up cubes inside or around the base
            return;
        }
    }// end of if (center blocks seen & not holding cube)


	//start of cuck code. everything below is a cube april tag i guess cos of the return ? 

    PickUpResult result;
	    //foudn cube tag
    if (message->detections.size() > 0 && !targetCollected) {
targetDetected = true;
if (!giveControlToPickupController)
	print("GIVING CONTROL TO PICKUP CONTROLLER");



PickUpResult result = pickUpController.selectTarget(message);
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

    if ((!targetDetected || targetCollected) && (message->data > 0)) {

if (!isDoingDriveOnTimer)
{
stringstream ss;
ss << "(algy?) obstacle detected! " << (int)(message->data) << "  " << (int)(time(0));
print(ss.str());
}


        // obstacle on right side
        if (message->data == 1) {
            // select new heading 0.2 radians to the left
if (!isDoingDriveOnTimer)	    
{
print("obstacle on right. turning left");
driveOnTimer(0.05,0.55,1.0);
}

        }

        // obstacle in front or on left side
        else if (message->data == 2) {
            // select new heading 0.2 radians to the right
if (!isDoingDriveOnTimer)
{
print("obstacle on left. turning right");
driveOnTimer(0.05,0.55,1.0);
}

        }

        // switch to transform state to trigger collision avoidance
        stateMachineState = STATE_MACHINE_TRANSFORM;

      //  avoidingObstacle = true;
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


/*
targetDetectedReset is only called once at the start of the program.
*/
void targetDetectedReset(const ros::TimerEvent& event) {
    targetDetected = false;

    std_msgs::Float32 angle;
    angle.data = 0;

    // close fingers
    fingerAnglePublish.publish(angle);

    // raise wrist
    wristAnglePublish.publish(angle);
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


    // only run below code if a centerLocation has been set by initilization
    if (init) {
        // map frame
        geometry_msgs::PoseStamped mapPose;

        // setup msg to represent the center location in map frame
        mapPose.header.stamp = ros::Time::now();

        mapPose.header.frame_id = publishedName + "/map";
        mapPose.pose.orientation = tf::createQuaternionMsgFromRollPitchYaw(0, 0, centerLocationMap.theta);
        mapPose.pose.position.x = centerLocationMap.x;
        mapPose.pose.position.y = centerLocationMap.y;
        geometry_msgs::PoseStamped odomPose;
        string x = "";

        try { //attempt to get the transform of the center point in map frame to odom frame.
            tfListener->waitForTransform(publishedName + "/map", publishedName + "/odom", ros::Time::now(), ros::Duration(1.0));
            tfListener->transformPose(publishedName + "/odom", mapPose, odomPose);
        }

        catch(tf::TransformException& ex) {
            ROS_INFO("Received an exception trying to transform a point from \"map\" to \"odom\": %s", ex.what());
            x = "Exception thrown " + (string)ex.what();
            std_msgs::String msg;
            stringstream ss;
            ss << "Exception in mapAverage() " + (string)ex.what();
            msg.data = ss.str();
            infoLogPublisher.publish(msg);
        }

        // Use the position and orientation provided by the ros transform.
        centerLocation.x = odomPose.pose.position.x; //set centerLocation in odom frame
        centerLocation.y = odomPose.pose.position.y;


    }
}

