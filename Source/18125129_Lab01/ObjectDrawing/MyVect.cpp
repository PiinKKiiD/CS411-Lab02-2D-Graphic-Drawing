#include "math.h"

#include "MyVect.h"

MyVect::MyVect()
{
	this->x = 0;
	this->y = 0;
}

MyVect::MyVect(Point e)
{
	this->x = e.getX();
	this->y = e.getY();
}

MyVect::MyVect(Point b, Point e)
{
	this->x = e.getX() - b.getX();
	this->y = e.getY() - b.getY();
}

float MyVect::getDim()
{
	return sqrt(double(this->x) * double(this->x) + double(this->y) * double(this->y));
}

MyVect MyVect::multiBy(float k)
{
	MyVect ret;
	ret.x = k * this->x;
	ret.y = k * this->y;
	return ret;
}

void MyVect::setEqualVect(MyVect B)
{
	this->x = B.x;
	this->y = B.y;
}

float MyVect::getX()
{
	return this->x;
}

float MyVect::getY()
{
	return this->y;
}

void MyVect::setX(float xx)
{
	this->x = xx;
}

void MyVect::setY(float yy)
{
	this->y = yy;
}

bool MyVect::isDimEqual(MyVect b)
{
	float dif = this->getDim() - b.getDim();
	if (dif > -0.000005 && dif < 0.000005) // Error difference due to float rounding.
		return true;
	return false;
}

bool MyVect::isSameDir(MyVect b)
{
	float kx = this->x / b.x;
	float ky = this->y / b.y;
	float k = kx - ky;
	if (k > -0.000005 && k < 0.000005) // Error difference due to float rounding.
		return true;
	return false;
}

float MyVect::makeCosine(MyVect b)
{
	float dot = this->dotProduct(b);
	float cos = dot / (this->getDim() * b.getDim());
	return cos;
}

float MyVect::dotProduct(MyVect b)
{
	return this->x*b.x + this->y*b.y;
}


MyVect MyVect::getNormal()
{
	MyVect ret;
	ret.setX(this->getY());
	ret.setY(-this->getX());
	return ret;
}
