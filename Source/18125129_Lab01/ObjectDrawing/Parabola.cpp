#include "Parabola.h"


void Parabolla::setColor()
{
	glColor3f(1, 1, 1);
}

Parabolla::Parabolla()
{
	center = Point();
	focalLength = 10.0;
	a = 1/(4*focalLength);
}

Parabolla::Parabolla(Point c, float l)
{
	center = c;
	focalLength = l;
	a = 1 / (4 * focalLength);
}

void Parabolla::drawByMidPoint()
{
	glPointSize(3);
	glBegin(GL_POINTS);
	setColor();
	float x = 1 / (2 * this->a);
	float y = 1 / (4 * this->a);
	float f = ((this->a) / 4) - (1 / 2);
	putPixelAt(x + center.getX(), y + center.getY());
	while (x < 1000) {
		if (f < 0) {
			f += 2 * a * (x + 1) - 1;
			x += 1;
		}
		else f -= 1;
		y += 1;
		putPixelAt(x+center.getX(), y+center.getY());
		putPixelAt(-x+center.getX(), y+center.getY());
	}
	x = 0;
	y = 0;
	f = a - 1 / 2;
	putPixelAt(x + center.getX(), y + center.getY());
	while (x < (1 / (2 * a))) {
		if (f < 0)
			f += a * (2 * x + 3);
		else {
			f += a * (2 * x + 3) - 1;
			y += 1;
		}
		x += 1;
		putPixelAt(x + center.getX(), y + center.getY());
		putPixelAt(-x + center.getX(), y + center.getY());
	}
	glEnd();
}

void Parabolla::setCenter(float x, float y)
{
	Point c(x, y);
	center = c;
}

void Parabolla::setFocalLen(float len)
{
	focalLength = len;
	a = 1 / (4 * focalLength);
}

Point Parabolla::getCenter()
{
	return this->center;
}

float Parabolla::getLength()
{
	return focalLength;
}

float Parabolla::getA()
{
	return 1/(4*focalLength);
}
