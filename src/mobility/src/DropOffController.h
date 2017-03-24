#ifndef DROPOFCONTROLLER_H
#define DROPOFCONTROLLER_H
#define HEADERFILE_H

#include <geometry_msgs/Pose2D.h>
#include <std_msgs/Float32.h>


struct DropOffResult {
    float cmdVel;//the speed of the robot
    float angleError;//the angle to set the robot to
    float fingerAngle;//fingerangle (close or open)
    float wristAngle;//wristangle (up or down)
    bool goalDriving; //set true for when driving is goal location oriented and false when it is target or time oriented
    geometry_msgs::Pose2D centerGoal;//the location of the goal in x,y (probably 0,0 i guess?)
    bool reset;//flag to reset the state of the robot or something in the mobility.cpp
    bool timer;//flag to reset the "timer" associated with dropoff controller in the mobility.cpp
};

class DropOffController
{
public:
    DropOffController();
    ~DropOffController();

    void reset();

    DropOffResult getState() {return result;}
    float getCentX() { return centerLocation.x;}//literally never used
    float getCount() { return count;}//when you make a getter for something that is only used privately :^)

    void setDataTargets(int ccount, double lleft, double rright);
    void setCenterDist(float dist) {distanceToCenter = dist;}
    void setDataLocations(geometry_msgs::Pose2D center, geometry_msgs::Pose2D current, float sync);
const static float FINGERS_OPEN = M_PI_2;
const static float FINGERS_CLOSED = 0;
const static float WRIST_UP = 0;
const static float WRIST_DOWN = 1.25;

private:

    bool right;
    bool left;
    bool reachedCollectionPoint;


    //set to true when we are entering the center circle
    bool centerApproach;

    //we have seen enough central collection tags to be certain we are either in or driving towards the nest.
    bool seenEnoughCenterTags;

    //central collection point has been seen (aka the nest)
    bool centerSeen;

    time_t timeWithoutSeeingEnoughCenterTags;
    float cameraOffsetCorrection;
    float centeringTurn;
    int seenEnoughCenterTagsCount;
    DropOffResult result;
    int count;
    int prevCount;
    double countLeft;
    double countRight;
    float collectionPointVisualDistance;//a constant hard coded in constructor
    float distanceToCenter;//continuously calculated at runtime
    geometry_msgs::Pose2D centerLocation;
    geometry_msgs::Pose2D currentLocation;
    float timerTimeElapsed;
    time_t timerStartTime;
    float timeElapsedSinceTimeSinceSeeingEnoughCenterTags;//that variable name tho

    float searchVelocity;

    void calculateDecision();


};
#endif // end header define
