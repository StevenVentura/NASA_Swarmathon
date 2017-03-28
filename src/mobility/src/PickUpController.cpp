#include "PickUpController.h"

PickUpController::PickUpController() {
    nTargetsSeen = 0;
    blockYawError = 0;
    blockDist = 0;
    td = 0;

    result.pickedUp = false;
    result.cmdVel = 0;
    result.angleError = 0;
    result.fingerAngle = -1;
    result.wristAngle = -1;
    result.giveUp = false;
result.debug = 0;

state = FIXING_CAMERA;
openCVThinksCubeIsHeld = false;

}

/*
3/19/17: 9:40PM
behavior before me fixing everything:
its being fucking stupid and like backing up at dumb times 
and its not moving forward the correct amount every time
and sometimes its not even trying to close its claw and 

its just stupid fix it.


what it should do:
the pickupcontroller is responsible for providing instructions on how to move the robot for each step after a block has been detected.

1) center camera on block
2) lower claw & approach block
3) push claw into block
4) pick up block
5) make sure block is in hand (if its tag appears on the screen at all desu? or blockblock)
6) set destination to the base. this might need to be a "permanent" destination ( if it gets interrupted then it will remember that it has to return to the base)


*/



PickUpResult PickUpController::pickUpSelectedTarget(bool blockBlock) {
result.debug = 0;

/*
variables i have to work with:

inputs:
  blockDist
  blockYawError
  nTargetsSeen (if it so happens that the thread sent that before between function calls)
  blockBlock
  thereIsAReallyCloseBlock //close to the camera using openCV

if (hypot(hypot(tagPose.pose.position.x, tagPose.pose.position.y), tagPose.pose.position.z) < 0.13 && Td < 3.8) {
        result.pickedUp = true;
    }

outputs:
struct PickUpResult{
  float cmdVel;//the speed to move robot after this loop
  float angleError;//the angle to move robot after this loop
  float fingerAngle;//has  control over wrist and finger of the claw
  float wristAngle;
  bool pickedUp;//this pretty much signals the end of the program
  bool giveUp;//may or may not use this
};
stuff he made up that i might not use:
lockTarget
timeOut
vel = blockDist * 0.20 (clamps it to [0.10, 0.20])
*/


//this means dont change these until they are set to something
result.fingerAngle = -1;
result.wristAngle = -1;

float duration;
ros::Duration timeDifferenceObject;

float timeToEnsureStraightening;

switch(state) {

//put target in center of camera
case (FIXING_CAMERA):
//do nothing! this is handled in mobility now!
break;

//walk to the cube on a timer
/*
3/24/17 measures i made with tapemeasure to see how far robot goes at 0.10 velocity && duration = 3.0 directly at cube detected. distance on right (0.325 etc) is the opencv calculated value  blockDist from below
13inches (ontop of it and to front of cube) = 0.325
13inches = 0.320
13 inches = 0.320 = good pickup (hits cube and then slides it forward a safe amount)
26 inches = 0.654 = bad pickup (too short)
*/
case (APPROACHING_CUBE):
timeToEnsureStraightening = 0;
duration = 2.5 * (distanceToBlockUponFirstSight / 0.320) + timeToEnsureStraightening;
timeDifferenceObject = ros::Time::now() - omniTimerStartingTime;
if ((timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) < duration)
{
result.cmdVel = 0.10;//inch forward
result.angleError = 0;
}
else
{
//it is done travelling
result.cmdVel = 0;
result.angleError = 0;
state = PICKING_UP_CUBE;
}
break;

case (PICKING_UP_CUBE):

// close fingers
result.fingerAngle = 0;



omniTimerStartingTime = ros::Time::now();//reset the timer again
state = WAIT_BEFORE_RAISING_WRIST;

break;

case (WAIT_BEFORE_RAISING_WRIST):
duration = 1.0;
timeDifferenceObject = ros::Time::now() - omniTimerStartingTime;
if ((timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) < duration)
{

}//do nothing; wait
else
{
//raise wrist back up
result.wristAngle = 0;
state = VERIFYING_PICKUP;
}
break;

case (VERIFYING_PICKUP):
duration = 2.0;
timeDifferenceObject = ros::Time::now() - omniTimerStartingTime;
if ((timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) < duration)
{
//check if the cube is in his hand or not!
if (blockBlock || openCVThinksCubeIsHeld)
	state = DONE_SUCCESS;
}
else
{
//time is up! didnt get the cube. reposition mr. robot now.
omniTimerStartingTime = ros::Time::now();//reset the timer again
state = PICKUP_FAILED_BACK_UP;
}//end outOfTime

break;

case(PICKUP_FAILED_BACK_UP):

duration = 1.75;
timeDifferenceObject = ros::Time::now() - omniTimerStartingTime;

if ((timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) < duration)
{
//raise wrist and back up
result.wristAngle = 0;
result.cmdVel = -0.2;
}
else
{
//time is up
result.cmdVel = 0;
state = DONE_FAILING;
}
break;

case (DONE_FAILING):
//do nothing. wait for mobility to recognize our failure so he can call void resetPickupController();
state = DONE_FAILING;
break;

case (DONE_SUCCESS):
result.pickedUp = true;//mobility.cpp looks for this flag
state = DONE_SUCCESS;
break;



default:
break;


}//end switch(state)


return result;
}//

/*
call frequency / origin:
this is called by the callback handler in mobility.cpp when a tag is detected on the message stream.


OUTPUTS and changed variables:
1) thereIsAReallyCloseBlock
2) blockDist
3) blockYawError (for some reason this is a value from [-10,10]? ??? 
4) nTargetsSeen


*/
PickUpResult PickUpController::selectTarget(const apriltags_ros::AprilTagDetectionArray::ConstPtr& message) {

  
    nTargetsSeen = 0;
    nTargetsSeen = message->detections.size();

    double closest = std::numeric_limits<double>::max();//Double.MAX_VALUE
    int target  = 0;
    for (int i = 0; i < message->detections.size(); i++) //this loop selects the closest visible block to makes goals for it
    {
        geometry_msgs::PoseStamped tagPose = message->detections[i].pose;
        double test = hypot(hypot(tagPose.pose.position.x, tagPose.pose.position.y), tagPose.pose.position.z); //absolute distance to block from camera lens

        if (test < closest)//find the closest block desu
        {
            target = i;
            closest = test;
            blockDist = hypot(tagPose.pose.position.z, tagPose.pose.position.y); //distance from bottom center of chassis ignoring height.
            blockDist = sqrt(blockDist*blockDist - 0.195*0.195);//not sure why
            blockYawError = atan((tagPose.pose.position.x + 0.020)/blockDist)*1.05; //angle to block from bottom center of chassis on the horizontal.
        }
    }

//literally how would it be greater than 10 if it comes from the atan function?.... i guess cos of that 1.05 multiplier they got there.....
    if ( blockYawError > 10) blockYawError = 10; //limits block angle error to prevent overspeed from PID.
    if ( blockYawError < - 10) blockYawError = -10; //due to detetionropping out when moveing quickly

    geometry_msgs::PoseStamped tagPose = message->detections[target].pose;

if (hypot(hypot(tagPose.pose.position.x, tagPose.pose.position.y), tagPose.pose.position.z) < 0.13) {
//there is areally close block so exit the program
openCVThinksCubeIsHeld = true;
    }

//so mobility.cpp can save the snapshot of block distance and yaw error
result.blockDist = blockDist;
result.blockYawError = blockYawError;
    

    return result;
}

void PickUpController::reset() {
    result.pickedUp = false;

state = FIXING_CAMERA;

    nTargetsSeen = 0;
    blockYawError = 0;
    blockDist = 0;
    td = 0;
openCVThinksCubeIsHeld = false;


    result.pickedUp = false;
    result.cmdVel = 0;
    result.angleError = 0;
    result.fingerAngle = -1;
    result.wristAngle = -1;
    result.giveUp = false;


}

PickUpController::~PickUpController() {
}
