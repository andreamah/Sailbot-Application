
#include "pch.h"
#include <iostream>

/*
* HELPER METHOD
* Changes an angle to an equivalent angle within the range [0, 360]
* @param angle as the original input angle in degrees.
* @return the equivalent angle within [0, 360] in degrees.
*/
float convertTo360(float angle)
{
	//convert negative angles to positive
	while (angle < 0)
	{
		angle += 360;
	}

	//convert angles above 360 to below 360
	while (angle > 360)
	{
		angle -= 360;
	}
	return angle;
}
/**
* Bounds the provided angle between [-180, 180) degrees.
* Ex. 360 becomes 0, 270 becomes -90, -450 becomes -90.
* @param angle Input angle in degrees.
* @return The bounded angle in degrees.
*/
float BoundTo180(float angle)
{
	//convert the input angle to an eqivalent angle within [0, 360]
	float finAn = convertTo360(angle);

	//if the angle is out of [-180, 180), convert it to an eqivalent value within the range
	if (finAn < -180 || finAn >= 180)
	{
		finAn = -(360 - abs(finAn));
	}
	return finAn;

}
/**
* Determines whether |middle_angle| is in the acute angle between the other two
bounding angles.
* Note: Input angles are bounded to 180 for safety.
* Ex. -180 is between -90 and 110 but not between -90 and 80.
* @param first_angle First angle in degrees.
* @param middle_angle Middle angle in degrees.
* @param second_angle Second angle in degrees.
* @return Whether |middle_angle| is between |first_angle| and |second_angle|
(exclusive).
*/
bool IsAngleBetween(float first_angle, float middle_angle, float second_angle) {

	float smaller_angle;
	float larger_angle;
	
	//convert all angles to equivalent angles within [0, 360]
	first_angle = convertTo360(first_angle);
	second_angle = convertTo360(second_angle);
	middle_angle = convertTo360(middle_angle);

	//if the middle angle equals the first or second angle, it cannot be in between exclusively
	if (second_angle == middle_angle || first_angle == middle_angle) {
		return false;
	}
	//assign a larger and smaller angle after the 360 range conversion
	if (first_angle < second_angle) {
		smaller_angle = first_angle;
		larger_angle = second_angle;
	}
	else if (first_angle > second_angle) {
		smaller_angle = second_angle;
		larger_angle = first_angle;
	}
	//if the angles are equal, return false
	else {
		return false;
	}

	//if both angles between the two angles are the same, the middle angle will be between 
	//regardless where it is
	if ((larger_angle - smaller_angle) == 180) {
		return true;
	}

	//find which side the smaller angle is on
	bool withinNums = (larger_angle - smaller_angle) < (360 - (larger_angle - smaller_angle));
	//find which side the middle angle is on
	bool outsideNums = (middle_angle < larger_angle && middle_angle > smaller_angle);

	//if the side of the smaller angle and middle angle are the same, return true
	//otherwise, return false
	if ((withinNums && outsideNums) || (!withinNums && !outsideNums)) {
		return true;
	}
	else {
		return false;
	}

}


