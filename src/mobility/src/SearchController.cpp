#include "SearchController.h"

SearchController::SearchController() {
  rng = new random_numbers::RandomNumberGenerator();
  setState(SETTING_INITIAL_HEADING);
  comeBackToCluster = false;
}

/**
 * This code implements a basic random walk search.
 */
geometry_msgs::Pose2D SearchController::search(geometry_msgs::Pose2D currentLocation) {
  geometry_msgs::Pose2D goalLocation;



if (comeBackToCluster)
{
goalLocation.x = clusterLocation.x;
goalLocation.y = clusterLocation.y; 
return goalLocation;
}


float newAngle = rng->gaussian(currentLocation.theta, 0.50);

//select new position!
goalLocation.x = currentLocation.x + 0.70 * cos(newAngle);
goalLocation.y = currentLocation.y + 0.70 * sin(newAngle);




  return goalLocation;
}


