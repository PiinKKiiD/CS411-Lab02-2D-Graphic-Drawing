#include <math.h>
#include <iostream>
#include <conio.h>
#include "Line.h"

Line::Line()
{
	cout << "This is default initial!!" << endl;
	Point b(0, 0);
	Point e(0, 0);
	this->bPoint.setEqual(b);
	this->ePoint.setEqual(e);
}

Line::Line(Point p)
{
	ePoint.setCoor(0, 0);
	ePoint.setEqual(p);
}

Line::Line(Point b, Point e)
{
	bPoint.setEqual(b);
	ePoint.setEqual(e);
}

Line::Line(Point p, MyVect normal)
{

}

void Line::normalize()
{
	if (bPoint.getX() > ePoint.getX()) {
		Point temp = bPoint;
		bPoint = ePoint;
		ePoint = temp;
	}
}


float* Line::getFunction()
{
	float* ret = new float[3];
	ret[0] = getNorVect().getX();	//a
	ret[1] = getNorVect().getY();	//b
	ret[2] = 0;						//c
	ret[2] = -(ret[0] *bPoint.getX()  + ret[1] * bPoint.getY());
	return ret;		//after using variable array/pointer *, remember: "delete[]abc"
}

MyVect Line::getDirVect()
{
	return MyVect(this->bPoint, this->ePoint);
}

MyVect Line::getNorVect()
{
	MyVect dirVec = this->getDirVect();
	return dirVec.getNormal();
}

float Line::distanceToPoint(Point m)
{
	float* funct = getFunction();
	return (abs(funct[0]*m.getX() + funct[1]*m.getY() + funct[2]))/(getNorVect().getDim());
}

Point Line::getBPoint()
{
	normalize();
	return bPoint;
}

Point Line::getEPoint()
{
	normalize();
	return ePoint;
}

void Line::drawByDDA()
{
	normalize();
	glPointSize(3);
	glColor3f(1, 0.5f, 1);
	float dx = abs(this->ePoint.getX() - this->bPoint.getX());
	float dy = abs(this->ePoint.getX() - this->bPoint.getX());
	float d = 1.0;
	if (dx > dy)
		d = dx;		//step;
	else d = dy;

	dx = dx / d;
	dy = dy / d;
	float x = this->bPoint.getX()*1.0;
	float y = this->bPoint.getY()*1.0;
	int i = 1;
	glBegin(GL_POINTS);
	for (int k = 1; k <= d; k++)
	{
		x += dx;
		y += dy;
		putPixelAt(round(x), round(y));
	}
	glEnd();

}

void Line::drawByBresen()//Gan nao` hon thi` to^
{
	normalize();
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(0.5, 0.5f, 1);
	float bx = this->bPoint.getX();
	float by = this->bPoint.getY();
	float ex = this->ePoint.getX();
	float ey = this->ePoint.getY();

	float dx = ex - bx;
	float dy = ey - by;
	float inX = 1;
	float inY = 1;
	if (dx < 0) {
		inX = -1;
	}
	if (dy < 0) {
		inY = -1;
	}
	//P0
	float m = 2 * dy;
	float p = 2*dy - dx;

	while (bx < ex)
	{
		if (p >= 0) {
			putPixelAt(bx, by);
			by += inY;
			p += 2 * (dy - dx);
		}
		else {
			putPixelAt(bx, by);
			p += 2 * dy;
			
		}
		bx += 1;
	}
	//Tim` d1, d2.
	glEnd();
}

void Line::setPoint(float x, float y, string point)
{
	normalize();
	Point b(x, y);
	if (point == "begin") {
		this->bPoint = b;
	}
	else if (point == "end") {
		this->ePoint = b;
	}
	else return;
}

