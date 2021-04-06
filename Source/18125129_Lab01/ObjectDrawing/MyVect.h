#pragma once
#include "Point.h"
class MyVect {
private:
	float x;
	float y;
public:
	MyVect();
	MyVect(Point e);
	MyVect(Point b, Point e);
	float getDim();
	MyVect multiBy(float k);
	void setEqualVect(MyVect B);
	float getX();
	float getY();
	void setX(float xx);
	void setY(float yy);
	bool isDimEqual(MyVect b);
	bool isSameDir(MyVect b);
	float makeCosine(MyVect b);
	float dotProduct(MyVect b);
	MyVect getNormal();
};