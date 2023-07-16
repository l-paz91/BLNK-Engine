// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Shape.h"

#include "DebugFunctions.h"

// -----------------------------------------------------------------------------

Blink::Shape::Shape()
	: mPoints()
	, mFillColour(Colour::eINVISIBLE)
	, mLineColour(Colour::eBLACK)
{

}

// -----------------------------------------------------------------------------

Blink::Point Blink::Shape::getPointDirection(Directions d)
{
	if (mPoints.size() == 0)
	{
		error("This shape has no points");
		return Point(0, 0);
	}
	else if (mPoints.size() == 1)
	{
		error("If the shape has more than 1 point, it should override this function with it's own code.");
		return Point(0, 0);
	}
	else
	{	
		return mPoints[0];
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------