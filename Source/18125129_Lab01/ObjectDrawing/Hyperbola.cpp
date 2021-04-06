#include "Hyperbola.h"

void Hyperbolla::setColor()
{
	glColor3f(1, 1, 0.5f);
}

Hyperbolla::Hyperbolla()
{
	center = Point();
	majorLength = 3;
	minorLength = 1;
}

Hyperbolla::Hyperbolla(Point c, int major, int minor)
{
	center = c;
	majorLength = major;
	minorLength = minor;
}

void Hyperbolla::drawByMidPoint()
{
	setColor();
	glPointSize(3);
	glBegin(GL_POINTS);
	float xC = this->center.getX();
	float yC = this->center.getY();
	float x = majorLength;
	float y = 0;
	float aSqure = majorLength * majorLength;
	float bSqure = minorLength * minorLength;
	float h = 2 * bSqure * majorLength - 3 * aSqure + 2 * bSqure;
	float k = -3 * aSqure;

	float f = bSqure * majorLength + (bSqure) / 4 - aSqure;

	//putPixelAt(x + xC, y + yC);
	while (x < (aSqure) / sqrt(aSqure - bSqure)) {
		if (f < 0) {
			h += 2 * bSqure - 2 * aSqure;
			k -= 2 * aSqure;
			f += h;
			x += 1;
		}
		else {
			h -= 2 * aSqure;
			k -= 2 * aSqure;
			f += k;
		}
		y += 0.1;
		putPixelAt(x+xC, y+yC);
		putPixelAt(x + xC, -y + yC);
		putPixelAt(-x + xC, y + yC);
		putPixelAt(-x + xC, -y + yC);
	}
	x = aSqure / sqrt(bSqure - aSqure);
	y = bSqure / sqrt(bSqure - aSqure);
	h = -3 * aSqure + 2 * bSqure;
	k = -3 * aSqure - 2 * aSqure * bSqure / sqrt(bSqure - aSqure);
	f = -(aSqure * bSqure / sqrt(bSqure - aSqure)) + (bSqure / 4) - aSqure;
	putPixelAt(x + xC, y + yC);
	while (x < 1000) {
		if (f < 0) {
			h += 2 * bSqure;
			k -= 2 * bSqure;
			f += h;
		}
		else {
			h += 2 * bSqure;
			k += 2 * bSqure - 2*aSqure;
			f += k;
			y += 1;
		}
		x+= 1;
		putPixelAt(x + xC, y + yC);
		putPixelAt(x + xC, -y + yC);
		putPixelAt(-x + xC, y + yC);
		putPixelAt(-x + xC, -y + yC);
	}
	glEnd();
}

void Hyperbolla::setCenter(float x, float y)
{
	Point c(x, y);
	center = c;
}

void Hyperbolla::setMaMi(int ma, int mi)
{
	majorLength = ma;
	minorLength = mi;
}

int Hyperbolla::getMa()
{
	return majorLength;
}

int Hyperbolla::getMi()
{
	return minorLength;
}

Point Hyperbolla::getCenter()
{
	return center;
}


