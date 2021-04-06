#include "Line.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Parabola.h"
#include "Hyperbola.h"
#include "GlutWindow.h"
class LibPainter {
public:
	LibPainter();
	void drawTheLine(Line a);
	void drawTheCircle(Circle c);
	void drawTheEllipse(Ellipse el);
	void drawTheParabola(Parabolla pa);
	void drawTheHyperbola(Hyperbolla hy);
};
