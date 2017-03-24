#include "SearchController.h"

SearchController::SearchController() {
  rng = new random_numbers::RandomNumberGenerator();
}

/**
 * This code implements a basic random walk search.
 */
geometry_msgs::Pose2D SearchController::search(geometry_msgs::Pose2D currentLocation) {
  geometry_msgs::Pose2D goalLocation;

float newAngle = rng->gaussian(currentLocation.theta, 0.50);

//select new position!
goalLocation.x = currentLocation.x + 0.75 * cos(newAngle);
goalLocation.y = currentLocation.y + 0.75 * sin(newAngle);


  return goalLocation;
}


