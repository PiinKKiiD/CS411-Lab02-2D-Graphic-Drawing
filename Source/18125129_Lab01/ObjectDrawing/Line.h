#pragma once
#include <iostream>
using namespace std;

#include "Point.h"
#include "MyVect.h"
#include "GlutWindow.h"
class Line {
private:
	Point bPoint;
	Point ePoint;
public:
	Line();
	Line(Point p);
	Line(Point b, Point e);
	Line(Point p, MyVect normal);
	void normalize();
	float *getFunction(); // return values of a,b,c in (d): aX+bY+c=0
	MyVect getDirVect();
	MyVect getNorVect();
	float distanceToPoint(Point m);
	/*bool isParallel(Line b);
	bool isRightConor(Line b);*/
	Point getBPoint();
	Point getEPoint();
	void drawByDDA();
	void drawByBresen();
	void setPoint(float x, float y, string point);
};