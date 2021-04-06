#ifndef ELLIPSE_HEADER
#define ELLIPSE_HEADER
#include "Point.h"
#include "glutWindow.h"
class Ellipse {
private:
	Point center;
	int halfBigR;
	int halfSmallR;
	void setColor();
public:
	Ellipse();
	Ellipse(Point c, int big, int small);
	void drawByMidPoint();
	Point getCenter();
	int getBigR();
	int getSmallR();
	void setCenter(float x, float y);
	void setRadiuses(int rx, int ry);
	void test();
};

#endif