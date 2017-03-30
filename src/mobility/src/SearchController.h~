#ifndef SEARCH_CONTROLLER
#define SEARCH_CONTROLLER

#include <geometry_msgs/Pose2D.h>
#include <random_numbers/random_numbers.h>

/**
 * This class implements the search control algorithm for the rovers. The code
 * here should be modified and enhanced to improve search performance.
 */
class SearchController {

  public:

    SearchController();

//NAVI refers to the sub-statemachine used for controlling the searchController && 
const static int SETTING_INITIAL_HEADING = 0, WAITING_FOR_MOMENTUM_BEFORE_MOVING = 1, MOVING_TO_GOAL = 2, REACHED_GOAL = 3, REACHED_GOAL_PAUSE=4;


ros::Duration timeDifferenceObject;
ros::Time omniTimerStartingTime;
int state;

std::string getStateName() {
const std::string stateNames[] = {"SETTING_INITIAL_HEADING", "WAITING_FOR_MOMENTUM", "MOVING_TO_GOAL","REACHED_GOAL","REACHED_GOAL_PAUSE"};
return stateNames[getState()];
}

int getState(){return state;}
void setState(int s){state=s;}


    // performs search pattern
    geometry_msgs::Pose2D search(geometry_msgs::Pose2D currentLocation);

  private:

    random_numbers::RandomNumberGenerator* rng;
};

#endif /* SEARCH_CONTROLLER */
