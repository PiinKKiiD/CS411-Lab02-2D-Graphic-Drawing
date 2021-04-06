#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER
#include "Point.h"
#include "GlutWindow.h"
class Circle {
private:
	Point center;
	int radius;
	void setColor();
public:
	Circle();
	Circle(Point c, int r);
	void drawByMidPoint();
	Point getCenter();
	int getRadius();
	void setCenter(float x, float y);
	void setRadius(int r);

};
#endif // !CIRCLE_HEADER