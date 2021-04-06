#include "GlutWindow.h"

void setLibColor()
{
	glColor3f(1, 0, 1);
}

void setMyColor()
{
	glColor3f(1.0f, 0.75f, 0.0f);
}

void putPixelAt(float x, float y)
{
	glVertex2i(x, y);
}
