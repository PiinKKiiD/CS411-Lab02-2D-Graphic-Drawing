#ifndef PARABOLA_HEADER
#define PARABOLA_HEADER
#include "Point.h"
#include "GlutWindow.h"
class Parabolla {
private:
	Point center;
	float focalLength;
	void setColor();
	float a;
public:
	Parabolla();
	Parabolla(Point c, float l);
	void drawByMidPoint();
	void setCenter(float x, float y);
	void setFocalLen(float len);
	Point getCenter();
	float getLength();
	float getA();
};

#endif // !PARABOLLA_HEADER