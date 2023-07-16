// -----------------------------------------------------------------------------
#ifndef Shape_H
#define Shape_H
// -----------------------------------------------------------------------------
// 
/*
	Shape is an interface class to allow drawing various Fl types to a window.

	A Shape can be attached to a FltkWrapper::Window.

	You must use FltkWrapper::Window::attach(Shape) in the constructor of your
	Window to add the Shape to the window.

	Use draw() to update the image.
*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Colour.h"
#include "Point.h"

#include <vector>

// -----------------------------------------------------------------------------

namespace Blink
{
	class Shape
	{
	public:
		Shape();
		virtual void draw() = 0;
		~Shape() {}

		Colour fillColour() const { return mFillColour; }
		Colour lineColour() const { return mLineColour; }

	protected:
		void addPoint(Point pPoint) { mPoints.push_back(pPoint); }
		const Point atPoint(int pIndex) const { return mPoints[pIndex]; }

		enum class Directions 
		{
			N, S, E, W, CENTER, NE, SE, SW, NW
		};
		virtual Point getPointDirection(Directions d);

	private:
		std::vector<Point> mPoints;	// not used by all shapes
		Colour mFillColour;
		Colour mLineColour;
	};
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !Shape_H