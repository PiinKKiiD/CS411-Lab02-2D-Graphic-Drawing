#ifndef HYPERBOLA_HEADER
#define HYPERBOLA_HEADER
#include "Point.h"
#include "GlutWindow.h"
#include <math.h>

class Hyperbolla {
private:
	Point center;
	int majorLength;
	int minorLength;
	void setColor();
public:
	Hyperbolla();
	Hyperbolla(Point c, int major, int minor);
	void drawByMidPoint();
	void setCenter(float x, float y);
	void setMaMi(int ma, int mi);
	int getMa();
	int getMi();
	Point getCenter();
};
#endif