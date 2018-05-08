#include <iostream>
#include "assign1.h"
#include <math.h>

Spatial pathLength(Point path[], int numPoints)
{
	// Variable to hold the total distance
	Spatial distance = 0.0;
	
	// Number of lines is exactly equal to number of points minus one. Hence the -1 in the for.
	for(int i = 0; i < numPoints-1; i++)
	{
		// Find the componenets of distance for each point
		Spatial verticalDistance = path[i+1].x-path[i].x;
		Spatial horizontalDistance = path[i+1].y-path[i].y;
		
		// Use pythag. to find the distance using the componenets.
		// a^2 + b^2 = c^2
		distance += sqrt(horizontalDistance*horizontalDistance + verticalDistance*verticalDistance);
	}
	return distance;
}

