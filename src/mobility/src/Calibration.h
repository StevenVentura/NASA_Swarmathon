#ifndef CALIBRATION_H
#define CALIBRATION_H
#include <ros/ros.h>
#include <geometry_msgs/Pose2D.h>


class Calibration {
public:
Calibration();
~Calibration();
void reset();


int state;
int getState(){ return state;}
void setState(int state){this->state = state;}
const static int BACKING_UP = 1, WAITING_1 = 2, MOVING_FORWARD = 3, WAITING_2 = 4, DONE_CALIBRATING = 5,STATE_INIT=6;
std::string getStateName() {
const std::string stateNames[] = {"BACKING_UP", "WAITING_1", "MOVING_FORWARD", "WAITING_2", "DONE_CALIBRATING","STATE_INIT"};
return stateNames[getState()];
}

geometry_msgs::Pose2D backupLocation;
geometry_msgs::Pose2D frontLocation;

float pickupSpeed;//meters per second

const static float backupTime = 4.0;//seconds

ros::Time omniTimerStartingTime;


};

#endif
