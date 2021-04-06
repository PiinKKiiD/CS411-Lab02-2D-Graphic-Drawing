#include "Ellipse.h"

void Ellipse::setColor()
{
	glColor3f(0.0f, 0.0f, 1);
}

Ellipse::Ellipse()
{
	center = Point();
	halfBigR = 5;
	halfSmallR = 2;
}

Ellipse::Ellipse(Point c, int big, int small)
{
	center = c;
	halfBigR = big;
	halfSmallR = small;
}

void Ellipse::drawByMidPoint()
{
	//setColor();
	//float xCenter = this->center.getX();
	//float yCenter = this->center.getY();
	//int big = this->halfBigR;
	//int small = this->halfSmallR;

	//int x = 0;
	//int y = small;

	//float fx = 0, fy = 2 * big * big * small;

	//float p1 = (small * small) - (big * big) * small + (big * big) * 0.25;

	//float dx = 2 * (small * small) * x;
	//float dy = 2 * (big * big) * y;
	//glPointSize(3);
	//glBegin(GL_POINTS);
	//while (dx < dy)
	//{
	//	putPixelAt(xCenter + x, yCenter + y);
	//	putPixelAt(xCenter - x, yCenter + y);
	//	putPixelAt(xCenter + x, yCenter - y);
	//	putPixelAt(xCenter - x, yCenter - y);
	//	if (p1 < 0) {
	//		x += 1;
	//		dx += 2 * (small * small) * x;
	//		p1 += (dx + (small * small));
	//	}
	//	else {
	//		x += 1;
	//		y -= 1;
	//		dx += 2 * (small * small) /** x*/;
	//		dy -= 2 * (big * big) /** y*/;
	//		p1 += dx - dy + (small * small);
	//	}
	//}
	//float p2 = (small * small) * (x + 0.5) * (x + 0.5) + ((big * big) * (y - 1) * (y - 1)) - ((small * small) * (big * big));
	//while (y > 0) {
	//	putPixelAt(xCenter + x, yCenter + y);
	//	putPixelAt(xCenter - x, yCenter + y);
	//	putPixelAt(xCenter + x, yCenter - y);
	//	putPixelAt(xCenter - x, yCenter - y);
	//	if (p2 > 0) {
	//		x = x;
	//		y -= 1;
	//		dy -= 2 * (big * big) /** y*/;
	//		p2 +=  (big * big) - dy;
	//	}
	//	else {
	//		x += 1;
	//		y -= 1;
	//		dy -= 2 * (big * big);
	//		dx += 2 * (small * small);
	//		p2 += (dx - dy + (big * big));
	//	}
	//}
	//glEnd();
	glPointSize(3);
	test();
}

void Ellipse::test() {
	float ra = this->halfBigR;
	float rb = this->halfSmallR;
	float xa = this->center.getX();
	float ya = this->center.getY();
	float aa = (ra * ra);
	float bb = (rb * rb);
	float aa2 = (aa * 2);
	float bb2 = (bb * 2);

	float x = 0;
	float y = rb;

	float fx = 0;
	float fy = (aa2 * rb);

	float p = (int)(bb - (aa * rb) + (0.25 * aa) + 0.5);
	glBegin(GL_POINTS);
	glVertex2f((xa + x), (ya + y));
	glVertex2f((xa + x), (ya - y));
	glVertex2f((xa - x), (ya - y));
	glVertex2f((xa - x), (ya + y));
	glEnd();

	while (fx < fy)
	{
		x++;
		fx += bb2;

		if (p < 0)
			p += (fx + bb);

		else
		{
			y--;
			fy -= aa2;
			p += (fx + bb - fy);
		}

		glBegin(GL_POINTS);
		glVertex2f((xa + x), (ya + y));
		glVertex2f((xa + x), (ya - y));
		glVertex2f((xa - x), (ya - y));
		glVertex2f((xa - x), (ya + y));
		glEnd();
	}

	p = (int)((bb * (x + 0.5) * (x + 0.5)) + (aa * (y - 1) * (y - 1)) - (aa * bb) + 0.5);

	while (y > 0)
	{
		y--;
		fy -= aa2;

		if (p >= 0)
			p += (aa - fy);

		else
		{
			x++;
			fx += bb2;
			p += (fx + aa - fy);
		}

		glBegin(GL_POINTS);
		glVertex2f((xa + x), (ya + y));
		glVertex2f((xa + x), (ya - y));
		glVertex2f((xa - x), (ya - y));
		glVertex2f((xa - x), (ya + y));
		glEnd();
	}
	glFlush();
}

Point Ellipse::getCenter()
{
	return center;
}

int Ellipse::getBigR()
{
	return halfBigR;
}

int Ellipse::getSmallR()
{
	return halfSmallR;
}

void Ellipse::setCenter(float x, float y)
{
	Point c(x, y);
	center = c;
}

void Ellipse::setRadiuses(int rx, int ry)
{
	halfBigR = rx;
	halfSmallR = ry;
}
