#include "DropOffController.h"

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
//approaching or entering base code
    centeringTurn = 0.15; //radians but how much even is .15 radians
    seenEnoughCenterTagsCount = 10;//seen enough for what tho? i said for what tho?
    collectionPointVisualDistance = 0.5; //in meters


//return to base code?
    result.cmdVel = 0;//the movement speed to give mr. robot upon exiting this module
    result.angleError = 0;//the angle to turn the robot upon exiting this module
    result.centerGoal; //struct goal that is center location or based upon the center location.  literally what?
    result.goalDriving = true;//goalDriving means that we are holding the cube and trying to navitate to the general area of the collectionPoint. set true if we are driving to the collectionPPont & you want mobility to control movement. set to false if you want to cntrol the movement yourself.

//is this the state controller? or is result.goalDriving the state controller? what is the difference between the two?
    reachedCollectionPoint = false;


//claw code
    result.fingerAngle = -1;//finger angle. -1 is a special value and means "dont touch it"
    result.wristAngle = -1;//wrist angle. -1 is a special value and means "dont touch it"
    
//claw code & resets other variables too. resets them both inside this and outside somewhere maybe? not sure
    result.reset = false;//reset what tho? i said,  what tho?
    result.timer = false;//why do i feel like this is never used outside this module

	//the fuck do these even mean lmao
    left = false;
    right = false;
	countLeft = 0; countRight = 0;

	//entering base code
    centerApproach = false;
    timeWithoutSeeingEnoughCenterTags = time(0);
    seenEnoughCenterTags = false;
    centerSeen = false;
    timeElapsedSinceTimeSinceSeeingEnoughCenterTags = time(0);
    prevCount = 0;

//final constant 
    searchVelocity = 0.20;//i guess they have it a little slower than the normal code so it doesnt drop the cube? shits stupid tho lol also why isnt it commented. they had it at .15 im changing it back to 0.20 for now.
}

//make sure this thing leaves the navigation alone
//this is called "locally" on setDataLocations. see SetDataLocations
void DropOffController::calculateDecision() {

    result.goalDriving = true; //this is steven control variable now.
    result.timer = false;



    //if we are in the routine for exciting the circle once we have droppeda block off and reseting all our flags
    //to resart our search.
    if(reachedCollectionPoint)
    {
        result.goalDriving = false;

        //timerStartTime was reset before we entered reachedCollectionPoint so
        //we can now use it for our timeing of 2 seconds

        if (timerTimeElapsed >= 4)
        {
            result.reset = true; //tell mobility to reset to search parameters
        }
        else if (timerTimeElapsed >= 1)
        {
            //open fingers
            float angle;
            angle = M_PI_2;
            result.fingerAngle = angle;
            angle= 0;
            result.wristAngle = angle; //raise wrist

            result.cmdVel = -0.3;
            result.angleError = 0.0;
        }
        return;
    }//returns

    //reset timeWithoutSeeingEnoughCenterTags timout timer to current time
    if ((!centerApproach && !seenEnoughCenterTags) || (count > 0 && !seenEnoughCenterTags)) 
	timeWithoutSeeingEnoughCenterTags = time(0);//seen enough center tags for what?

    if (count > 0 || seenEnoughCenterTags || prevCount > 0) //if we have a target and the center is located drive towards it.
    {
        centerSeen = true;
        result.goalDriving = false;

        if (seenEnoughCenterTags) //if we have seen enough tags
        {
            if ((countLeft-5) > countRight) //and there are too many on the left
            {
                right = false; //then we say non on the right to cause us to turn right
            }
            else if ((countRight-5) > countLeft)
            {
                left = false; //or left in this case
            }
        }

        float turnDirection = 1;
        //reverse tag rejection when we have seen enough tags that we are on a
        //trajectory in to the square we dont want to follow an edge.
        if (seenEnoughCenterTags) turnDirection = -1;


        //otherwise turn till tags on both sides of image then drive straight
        if (left && right) {
            result.cmdVel = searchVelocity;
            result.angleError = 0.0;
        }
        else if (right) {
            result.cmdVel = -0.1 * turnDirection;//ok....
            result.angleError = -centeringTurn*turnDirection;
        }
        else if (left){
            result.cmdVel = -0.1 * turnDirection;
            result.angleError = centeringTurn*turnDirection;
        }
        else
        {
            result.cmdVel = searchVelocity;
            result.angleError = 0.0;
        }

//very obviously going to be changing this code later

        //must see greater than this many tags before assuming we are driving into the center and not along an edge.
        if (count > seenEnoughCenterTagsCount)
        {
            seenEnoughCenterTags = true; //we have driven far enough forward to be in the circle.
            timeWithoutSeeingEnoughCenterTags = time(0);
        }
        if (count > 0) //reset gaurd to prevent drop offs due to loosing tracking on tags for a frame or 2.
        {
            timeWithoutSeeingEnoughCenterTags = time(0);
        }
        //time since we dropped below countGuard tags
        timeElapsedSinceTimeSinceSeeingEnoughCenterTags = time(0) - timeWithoutSeeingEnoughCenterTags;

        //we have driven far enough forward to have passed over the circle.
        if (count == 0 && seenEnoughCenterTags && timeElapsedSinceTimeSinceSeeingEnoughCenterTags > 1) {
            centerSeen = false;
        }
        centerApproach = true;
        prevCount = count;
        count = 0;
    }//end if it is approaching the center
    //was on approach to center and did not seenEnoughCenterTags
    //for maxTimeAllowedWithoutSeeingCenterTags seconds so reset.
    else if (centerApproach) {
        result.goalDriving = false;
        int maxTimeAllowedWithoutSeeingCenterTags = 6; //seconds

        timeElapsedSinceTimeSinceSeeingEnoughCenterTags = time(0) - timeWithoutSeeingEnoughCenterTags;
        if (timeElapsedSinceTimeSinceSeeingEnoughCenterTags > maxTimeAllowedWithoutSeeingCenterTags)
        {
            //go back to drive to center base location instead of drop off attempt
            reachedCollectionPoint = false;
            seenEnoughCenterTags = false;
            centerApproach = false;
        }
        else
        {
            result.cmdVel = searchVelocity;
            result.angleError = 0.0;
        }

        right = false;
        left = false;
        count = 0;
        centerSeen = false;
        return;

    }

    if (!centerSeen && seenEnoughCenterTags)
    {
//drop the cube?
        reachedCollectionPoint = true;
        timerStartTime = time(0);
        result.goalDriving = false;
        centerApproach = false;
        result.timer = true;
    }

    return;
}


//this is called by mobility.cpp if case STATE_MACHINE_TRANSFORM and if (targetCollected && !avoidingObstacle) {
void DropOffController::setDataLocations(geometry_msgs::Pose2D center, geometry_msgs::Pose2D current, float sync) {
//center location is the (0,0) passed into this module.
    centerLocation = center;
    currentLocation = current;
    timerTimeElapsed = sync;
    calculateDecision();

}


void DropOffController::reset() {
    result.cmdVel = 0;
    result.angleError = 0;
    result.fingerAngle = -1;
    result.wristAngle = -1;
    //took goaldriving out of reset for now

    result.centerGoal; //goal that is center location or based upon the center location.
    result.reset = false;
    prevCount = 0;

    left = false;
    right = false;
	countLeft = 0; countRight = 0;
    centerSeen = false;

    //reset flags
    reachedCollectionPoint = false;
    seenEnoughCenterTags = false;

}

//setDataTargets is called on its own "thread" by the targetSubscriber (/bravo/targets) topic. only called VERBATIM IN MOBILITY.CPP if (message->detections.size() > 0 && !reachedCollectionPoint[note this is a completely different variable with the same name that lives in mobility.cpp]) 
//@param: ccount=total number of goalspots, @lleft = number of goalspots on left half of camera, @rright = number of goalspots on right half of camera
void DropOffController::setDataTargets(int ccount, double lleft, double rright)
{
    count = ccount;

left = (countLeft > 0);//these have to be defined here because apparently i dont change them after we have reached the collection point? whatever "reaching" it even means
right = (countRight > 0);


   countLeft = lleft;
   countRight = rright;
}

DropOffController::~DropOffController() {
//deconstructor desu
}
