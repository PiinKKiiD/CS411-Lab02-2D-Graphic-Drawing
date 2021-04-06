#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

#include "glut.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Hyperbola.h"
#include "Line.h"
#include "MyVect.h"
#include "Parabola.h"
#include "Point.h"
#include "GlutWindow.h"
#include "LibPainter.h"

string path = "input.txt"; //path to the file txt containing the input

bool getInputFromTxt(Line* lineDDA, Line* lineBre, Circle* circle, Ellipse* elip, Parabolla* parabol, Hyperbolla* hyper, string path) {
	ifstream infile;
	infile.open(path);
	if (infile.fail())
	{
		return false;
	}
	int id;
	float cur, nextCur , r;
	infile >> id;
	while (id <6) {
		if (id == 0) {
			infile >> cur;
			infile >> nextCur;
			lineDDA->setPoint(cur, nextCur, "begin");
			infile >> cur;
			infile >> nextCur;
			lineDDA->setPoint(cur, nextCur, "end");
			infile >> id;
		}
		else if (id == 1) {
			infile >> cur;
			infile >> nextCur;
			lineBre->setPoint(cur, nextCur, "begin");
			infile >> cur;
			infile >> nextCur;
			lineBre->setPoint(cur, nextCur, "end");

			infile >> id;
		}
		else if (id == 2) {
			infile >> cur;
			infile >> nextCur;
			circle->setCenter(cur, nextCur);
			infile >> cur;
			circle->setRadius(cur);
			infile >> id;
		}
		else if (id == 3) {
			infile >> cur;
			infile >> nextCur;
			elip->setCenter(cur, nextCur);
			infile >> cur;
			infile >> nextCur;
			elip->setRadiuses(cur, nextCur);
			infile >> id;
		}
		else if (id == 4) {
			infile >> cur;
			infile >> nextCur;
			parabol->setCenter(cur, nextCur);
			infile >> cur;
			parabol->setFocalLen(cur);

			infile >> id;
		}
		else if (id == 5) {
			infile >> cur;
			infile >> nextCur;
			hyper->setCenter(cur, nextCur);
			infile >> cur;
			infile >> nextCur;
			hyper->setMaMi(cur, nextCur);
			infile >> id;
			return true;
		}
		else return false;
	}
	return false;
}

void display(void)
{
	LibPainter LibPter; //Create a painter drawing shapes from opengl library.
	glClear(GL_COLOR_BUFFER_BIT);

	//getting input...
	Line liDDA, liBresen;
	Circle cir;
	Ellipse elipse;
	Parabolla para;
	Hyperbolla hyp;
	bool canOpen = getInputFromTxt(&liDDA, &liBresen, &cir, &elipse, &para, &hyp, path);
	if (canOpen == false) {
		return;
	}
		

	setMyColor();

	time_t begin, end;
	double difference1, difference2;
	//----------------------
	time(&begin);
	liBresen.drawByBresen();
	time(&end);
	difference1 = difftime(end, begin);
	cout << "@@Drawing The Line By Bresenham costs :"<< difference1*1000 << " miliseconds" << endl;

	time(&begin);
	LibPter.drawTheLine(liBresen);
	time(&end);
	difference2 = difftime(end, begin);
	cout << "@@Drawing The Line By OpenGL costs    :" << difference2*1000 << " miliseconds" << endl;
	cout << "--------------------------------------------" << endl;


	time(&begin);
	liDDA.drawByDDA();
	time(&end);
	difference1 = difftime(end, begin);
	cout << "@@Drawing The Line By DDA costs       :" << difference1 * 1000 << " miliseconds" << endl;

	time(&begin);
	LibPter.drawTheLine(liDDA);
	time(&end);
	difference2 = difftime(end, begin);
	cout << "@@Drawing The Line By OpenGL costs    :" << difference2 * 1000 << " miliseconds" << endl;
	cout << "--------------------------------------------" << endl;



	time(&begin);
	elipse.drawByMidPoint();
	time(&end);
	difference1 = difftime(end, begin);
	cout << "@@Drawing The Ellipse By MidPoint costs:" << difference1 * 1000 << " miliseconds" << endl;

	time(&begin);
	LibPter.drawTheEllipse(elipse);
	time(&end);
	difference2 = difftime(end, begin);
	cout << "@@Drawing The Ellipse From Equation costs:" << difference2 * 1000 << " miliseconds" << endl;
	cout << "--------------------------------------------" << endl;


	time(&begin);
	para.drawByMidPoint();
	time(&end);
	difference1 = difftime(end, begin);
	cout << "@@Drawing The Parabola By MidPoint costs:" << difference1 * 1000 << " miliseconds" << endl;
	
	time(&begin);
	LibPter.drawTheParabola(para);
	time(&end);
	difference2 = difftime(end, begin);
	cout << "@@Drawing The Parabola By Equation costs:" << difference2 * 1000 << " miliseconds" << endl;
	cout << "--------------------------------------------" << endl;


	time(&begin);
	hyp.drawByMidPoint();
	time(&end);
	difference1 = difftime(end, begin);
	cout << "@@Drawing The Hyperbola By Midpoint costs:" << difference1 * 1000 << " miliseconds" << endl;

	time(&begin);
	LibPter.drawTheHyperbola(hyp);
	time(&end);
	difference2 = difftime(end, begin);
	cout << "@@Drawing The Hyperbola Equation costs:" << difference2 * 1000 << " miliseconds" << endl;
	cout << "--------------------------------------------" << endl;


	time(&begin);
	cir.drawByMidPoint();
	time(&end);
	difference1 = difftime(end, begin);
	cout << "@@Drawing The Circle By Midpoint costs:" << difference1 * 1000 << " miliseconds" << endl;

	time(&begin);
	LibPter.drawTheCircle(cir);
	time(&end);
	difference2 = difftime(end, begin);
	cout << "@@Drawing The Circle By Equation costs:" << difference2 * 1000 << " miliseconds" << endl;
	cout << "--------------------------------------------" << endl;
	
	glFlush();
}
void init(void)
{
	
	glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("18125129 - Nguyen Trung Hau");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}