#include "Circle.h"

void Circle::setColor()
{
	glColor3f(1, 0.5f, 0.5f);
}

Circle::Circle()
{
	center = Point();
	radius = 1;
}

Circle::Circle(Point c, int r)
{
	center = c;
	radius = r;
}

void Circle::drawByMidPoint()
{
	glPointSize(3);
	glBegin(GL_POINTS);
	setColor();
	float yCenter = this->center.getY();
	float xCenter = this->center.getX();
	int r = this->radius;
	int x = 0;
	int y = r;
	float decision = (5 / 4) - r;
	putPixelAt(x+xCenter, y+yCenter);
	while (y > x)
	{
		if (decision < 0)
		{
			x++;
			decision += 2 * x + 1;
		}
		else
		{
			y--;
			x++;
			decision += 2 * (x - y) + 1;
		}
		putPixelAt(x+xCenter, y+yCenter);
		putPixelAt(x + xCenter, -y + yCenter);
		putPixelAt(-x + xCenter, y + yCenter);
		putPixelAt(-x + xCenter, -y + yCenter);
		putPixelAt(y + xCenter, x + yCenter);
		putPixelAt(-y + xCenter, x + yCenter);
		putPixelAt(y + xCenter, -x + yCenter);
		putPixelAt(-y + xCenter, -x + yCenter);
	}
	//if (r > 0) {
	//	//Put pixel at 4 points;
	//	putPixelAt(xCenter, yCenter + r);
	//	putPixelAt(xCenter, yCenter - r);
	//	putPixelAt(xCenter+r, yCenter);
	//	putPixelAt(xCenter-r, yCenter);
	//	float decision = (5 / 4) - r;
	//}
	glEnd();
}

Point Circle::getCenter()
{
	return center;
}

int Circle::getRadius()
{
	return radius;
}

void Circle::setCenter(float x, float y)
{
	Point c(x, y);
	center = c;
}

void Circle::setRadius(int r)
{
	radius = r;
}
