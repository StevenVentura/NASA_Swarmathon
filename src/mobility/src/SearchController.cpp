#include "SearchController.h"

SearchController::SearchController() {
  rng = new random_numbers::RandomNumberGenerator();
  setState(SETTING_INITIAL_HEADING);
  comeBackToCluster = false;
	tryingToFindTheBase = false;	
	
}

void SearchController::initTryingToFindBase(float x,float y){

originX = x;
originY = y;


spiralAngle = 0;
spiralLength = 0;
spiralCounter = 0;

tryingToFindTheBase = true;

}//end void

/**
 * This code implements a basic random walk search.
 */
geometry_msgs::Pose2D SearchController::search(geometry_msgs::Pose2D currentLocation) {
  geometry_msgs::Pose2D goalLocation;


if (tryingToFindTheBase)
{
spiralAngle += (2*3.1415) / (float)numPoints;
goalLocation.x = originX + spiralLength * cos(spiralAngle);
goalLocation.y = originY + spiralLength * sin(spiralAngle);
spiralCounter++;
spiralLength = spiralCounter * (0.50);


return goalLocation;
}


if (comeBackToCluster && !tryingToFindTheBase)
{
goalLocation.x = clusterLocation.x;
goalLocation.y = clusterLocation.y; 
return goalLocation;
}







float newAngle = rng->gaussian(currentLocation.theta, 0.50);

//select new position!
goalLocation.x = currentLocation.x + 1.00 * cos(newAngle);
goalLocation.y = currentLocation.y + 1.00 * sin(newAngle);



  return goalLocation;
}


