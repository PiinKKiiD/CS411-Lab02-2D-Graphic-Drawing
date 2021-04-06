#include "LibPainter.h"

LibPainter::LibPainter()
{

}

void LibPainter::drawTheLine(Line a)
{
	setLibColor();
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex3f(a.getBPoint().getX(), a.getBPoint().getY(), 0.0);
	glVertex3f(a.getEPoint().getX(), a.getEPoint().getY(), 0.0);
	glEnd();
}

void LibPainter::drawTheCircle(Circle c)
{
	Point center = c.getCenter();
	int r = c.getRadius();
	setLibColor();
	float theta;
	glPointSize(3);
	glBegin(GL_POINTS);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.1415 / 180;
		glVertex2f(center.getX()+r*cos(theta), center.getY() + r*sin(theta));
	}
	glEnd();
}

void LibPainter::drawTheEllipse(Ellipse el)
{
	setLibColor();
	float theta;
	Point center = el.getCenter();
	int bigR = el.getBigR();
	int smallR = el.getSmallR();
	glPointSize(3);
	glBegin(GL_POINTS);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.1415 / 180;
		glVertex2f(center.getX() + bigR * cos(theta), center.getY() + smallR * sin(theta));
	}
	glEnd();
}

void LibPainter::drawTheParabola(Parabolla pa)
{
	glPointSize(3);
	glBegin(GL_POINTS);
	setLibColor();
	//y =a* X^2;
	float x = 0.0;
	float y = 0.0;
	float xC = pa.getCenter().getX();
	float yC = pa.getCenter().getY();
	float a = pa.getA();
	while (x < 100/*pa.getLength()*/) {
		putPixelAt(x + xC, y + yC);
		putPixelAt(-x + xC, y + yC);
		x += 0.0001;
		y = a * x * x;
	}
	glEnd();
}

void LibPainter::drawTheHyperbola(Hyperbolla hy)
{
	glPointSize(3);
	setLibColor();
	float a = hy.getMa();
	float b = hy.getMi();
	float xC = hy.getCenter().getX();
	float yC = hy.getCenter().getY();
	float x = a;
	float y = 0 /*b / a * sqrt(x*x -a*a)*/;
	glBegin(GL_POINTS);
	putPixelAt(x+xC, y+yC);
	putPixelAt(-x + xC, y + yC);
	putPixelAt(x + xC, -y + yC);
	putPixelAt(-x + xC, -y + yC);
	while (x < 1000) {
		x += 0.1;
		y = b / a * sqrt(x * x - a * a);
		putPixelAt(x + xC, y + yC);
		putPixelAt(-x + xC, y + yC);
		putPixelAt(x + xC, -y + yC);
		putPixelAt(-x + xC, -y + yC);
	}
	glEnd();
}
