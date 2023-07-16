// -----------------------------------------------------------------------------
#ifndef Circle_H
#define Circle_H
// -----------------------------------------------------------------------------
// 
/*
	Circle is a Shape.

*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Point.h"
#include "Shape.h"

// -----------------------------------------------------------------------------

namespace Blink
{
	class Circle : public Shape 
	{
	public:
		Circle(Point pPoint, int pRadius)	// center and radius
			: mRadius{ pRadius }
			, mDiameter(pRadius * 2)
		{
			addPoint(Point{ pPoint.mX - pRadius, pPoint.mY - pRadius });
		}

		// Shape interface
		virtual void draw() override;
		// ~ Shape interface

		Point center() const { return { atPoint(0).mX + mRadius, atPoint(0).mY + mRadius }; }
		Point getPointOnCircle(double pAngle) const;

		Point getPointDirection(Directions d);

		void setRadius(int pRadius) { mRadius = pRadius; }
		int radius() const { return mRadius; }
		int diam() const { return mDiameter; }
	private:
		int mRadius;
		int mDiameter;
	};
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !Circle_H