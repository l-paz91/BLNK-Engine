// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Widget.h"
#include "Shape.h"
#include "Window.h"

// -----------------------------------------------------------------------------

Blink::Window::Window(int pX, int pY, const char* pLabel)
	: Fl_Window(pX, pY, pLabel)
	, mWidth(pX)
	, mHeight(pY)
{
	init();
}

// -----------------------------------------------------------------------------

Blink::Window::Window(const Point& pPoint, int pWidth, int pHeight, const char* pLabel)
	: Fl_Window(int(pPoint.mX), int(pPoint.mY), pWidth, pHeight, pLabel)
	, mWidth(pWidth)
	, mHeight(pHeight)
{
	init();
}

// -----------------------------------------------------------------------------

void Blink::Window::attach(Widget& pWidget)
{
	Fl_Window::begin();			// FLTK: Begin attaching new Fl_Widgets to this window
	pWidget.attach(*this);		// let the widget create its own Fl_Widgets
	Fl_Window::end();			// FLTK: Stop attaching new Fl_Widgets to this window
}

// -----------------------------------------------------------------------------

void Blink::Window::detach(Widget& pWidget)
{
	pWidget.hide();
}

// -----------------------------------------------------------------------------

void Blink::Window::attach(Shape& pShape)
{
	mShapes.push_back(&pShape);
}

// -----------------------------------------------------------------------------

void Blink::Window::detach(Shape& pShape)
{
	for (unsigned int i = mShapes.size(); 0 < i; --i)	//last attached will be first released
		if (mShapes[i - 1] == &pShape)
		{
			mShapes.erase(mShapes.begin() + (i - 1));
		}

}

// -----------------------------------------------------------------------------

void Blink::Window::draw()
{
	Fl_Window::draw();
	for (unsigned int i = 0; i < mShapes.size(); ++i)
	{
		mShapes[i]->draw();
	}
}

// -----------------------------------------------------------------------------

void Blink::Window::init()
{
	Fl_Window::resizable(this);
	Fl_Window::show();
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------