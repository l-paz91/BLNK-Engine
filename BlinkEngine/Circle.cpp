// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Circle.h"

#include "DebugFunctions.h"

#include <numbers>

// -----------------------------------------------------------------------------

void Blink::Circle::draw()
{
	if (fillColour().visibility())
	{	
		// fill
		fl_color(fillColour().as_int());
		fl_pie(atPoint(0).mX, atPoint(0).mY, mRadius + mRadius - 1, mRadius + mRadius - 1, 0, 360);
		fl_color(Colour::eBLACK);	// reset fl_color
	}

	if (lineColour().visibility())
	{
		fl_color(lineColour().as_int());
		fl_arc(atPoint(0).mX, atPoint(0).mY, mRadius + mRadius, mRadius + mRadius, 0, 360);
	}
}

// -----------------------------------------------------------------------------

Blink::Point Blink::Circle::getPointOnCircle(double pAngle) const
{
	Point p;
	double rad = pAngle * (std::numbers::pi / 180.0f);
	p.mX = mRadius * cos(rad) + center().mX;
	p.mY = mRadius * sin(rad) + center().mY;
	return p;
}

// -----------------------------------------------------------------------------

Blink::Point Blink::Circle::getPointDirection(Directions d)
{
	Point c = center();
	switch (d)
	{
	case Directions::NW:
		return getPointOnCircle(135);
	case Directions::N:
		return Point(c.mX, c.mY - mRadius);
	case Directions::NE:
		return getPointOnCircle(45);
	case Directions::E:
		return Point(c.mX + mRadius, c.mY);
	case Directions::SE:
		return getPointOnCircle(315);
	case Directions::S:
		return Point(c.mX, c.mY + mRadius);
	case Directions::SW:
		return getPointOnCircle(225);
	case Directions::W:
		return Point(c.mX - mRadius, c.mY);
	case Directions::CENTER:
		return center();
	default:
		error("That's an odd direction");
		return Point(0, 0);
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------