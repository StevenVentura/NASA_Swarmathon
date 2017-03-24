#ifndef PICKUPCONTROLLER_H
#define PICKUPCONTROLLER_H
#define HEADERFILE_H
#include <apriltags_ros/AprilTagDetectionArray.h>
#include <ros/ros.h>

struct PickUpResult {
  float cmdVel;
  float angleError;
  volatile float fingerAngle;
  volatile float wristAngle;
  bool pickedUp;
  bool giveUp;
float blockDist;
float blockYawError;
float debug;
};

class PickUpController
{
 public:
  PickUpController();
  ~PickUpController();

  PickUpResult selectTarget(const apriltags_ros::AprilTagDetectionArray::ConstPtr& message);
  PickUpResult pickUpSelectedTarget(bool blockBlock);

  float getDist() {return blockDist;}
  bool getLockTarget() {return lockTarget;}
  float getTD() {return td;}
void setDistanceToBlockUponFirstSight(float pls,float ok) {distanceToBlockUponFirstSight = pls; yawErrorToBlockUponFirstSight = ok;}

int getState() {return state;}

  void reset();
const static int FIXING_CAMERA=0, APPROACHING_CUBE=1, PICKING_UP_CUBE=2,VERIFYING_PICKUP=3,PICKUP_FAILED_BACK_UP=4,DONE_FAILING=5,DONE_SUCCESS=6,WAIT_BEFORE_RAISING_WRIST=7;
volatile int state;

const static float FINGERS_OPEN = M_PI_2;
const static float FINGERS_CLOSED = 0;
const static float WRIST_UP = 0;
const static float WRIST_DOWN = 1.25;

//this is set when you first switch to "state_pickup"
float distanceToBlockUponFirstSight;
float yawErrorToBlockUponFirstSight;



ros::Time omniTimerStartingTime;

private:
  //set true when the target block is less than targetDist so we continue attempting to pick it up rather than
  //switching to another block that is in view
  bool lockTarget; 
bool openCVThinksCubeIsHeld;

  // Failsafe state. No legitimate behavior state. If in this state for too long return to searching as default behavior.
  bool timeOut;
  bool thereIsAReallyCloseBlock;
  int nTargetsSeen;
  ros::Time millTimer;

  //yaw error to target block 
  double blockYawError;
  
  //distance to target block from front of robot
  double blockDist;

  //struct for returning data to mobility
  PickUpResult result;

  float td;
};
#endif // end header define
