#include <math.h>
#include "Point.h"

Point::Point(float xx, float yy)
{
	this->x = xx;
	this->y = yy;
}

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

float Point::distanceTo(Point B)
{
	float dx = this->x - B.x;
	float dy = this->y - B.y;
	float ret = dx * dx + dy * dy;
	return sqrt(ret);
}

void Point::setCoor(float xx, float yy)
{
	this->x = xx;
	this->y = yy;
	return;
}

void Point::setEqual(Point B)
{
	this->x = B.x;
	this->y = B.y;
}

float Point::getX()
{
	return this->x;
}

float Point::getY()
{
	return this->y;
}

void Point::operator=(Point b)
{
	this->x = b.x;
	this->y = b.y;
}
