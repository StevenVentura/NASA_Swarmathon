#include "DropOffController.h"
#include <geometry_msgs/PoseStamped.h>

/*
two parts of this code:
1) RETURN_TO_BASE: navigate back to the base general area, with the cube in your hand
2) ENTER_BASE_AND_PLACE_CUBE_PROPERLY: once you are at the base, do a good job detecting the tags on it and drop off the cube properly and backout.

overall goals:
1) come back toward the base
2) get close enough
3) find the base tags
4) line yourself up with the tags
5) enter the base
6) drop off the cube
7) exit the base
8) return to searching
*/

DropOffController::DropOffController() {
	countLeft = 0; countRight = 0;
}

void DropOffController::setTagCountToZeroIfAppropriate()
{
//if it has been duration seconds, then it means the openCV has not given us new base tag info for 3 seconds so it probably hasn't seen the base for 3 seconds.
float duration = 3.0;
ros::Duration timeDifferenceObject = ros::Time::now() - lastTimeISawTheCenterBase;
if ((timeDifferenceObject.sec + timeDifferenceObject.nsec/1000000000.0) < duration)
{
return;//hasnt been duration seconds yet
}
else
{
countLeft = 0;
countRight = 0;
return;
}


}//end void setTagCountToZeroIfAppropriate

void DropOffController::reset() {
setState(DropOffController::FINDING_BASE);
numTimesPausedAndTurned = 0;

}

//setDataTargets is called on its own "thread" by the targetSubscriber (/bravo/targets) topic. only called VERBATIM IN MOBILITY.CPP if (message->detections.size() > 0 && !reachedCollectionPoint[note this is a completely different variable with the same name that lives in mobility.cpp]) 
//@param: ccount=total number of goalspots, @lleft = number of goalspots on left half of camera, @rright = number of goalspots on right half of camera
void DropOffController::setDataTargets(int lleft, int rright)
{
   countLeft = lleft;
   countRight = rright;
	//so i can set it to back to 0-targets-seen if it exceeds the threshold time (because i cant "poll" the sensors)
	lastTimeISawTheCenterBase = ros::Time::now();
}

DropOffController::~DropOffController() {
}
