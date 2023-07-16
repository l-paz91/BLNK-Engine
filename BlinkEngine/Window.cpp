// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Window.h"

#include "BasicInputBox.h"
#include "Circle.h"
#include "Image.h"
#include "Widget.h"
#include "Shape.h"

#include <sstream>

// -----------------------------------------------------------------------------

Blink::Window::Window(int pX, int pY, const char* pLabel)
	: Fl_Window(pX, pY, pLabel)
	, mShapes()
	, mCommandConsole(new BasicInputBox{ Point(100, 10), 300, 30, "Command:", 0 })
	, mWidth(pX)
	, mHeight(pY)
{
	init();
}

// -----------------------------------------------------------------------------

Blink::Window::Window(const Point& pPoint, int pWidth, int pHeight, const char* pLabel)
	: Fl_Window(int(pPoint.mX), int(pPoint.mY), pWidth, pHeight, pLabel)
	, mShapes()
	, mCommandConsole(new BasicInputBox{ Point(100, 10), 300, 30, "Command:",
		[](Address, Address pAddress) { referenceTo<Window>(pAddress).onTextEnteredInCommanConsole(); } })
	, mWidth(pWidth)
	, mHeight(pHeight)
{
	init();
}

// -----------------------------------------------------------------------------

Blink::Window::~Window()
{
	if (!mShapes.empty())
	{
		for (uint32_t i = 0; i < mShapes.size(); ++i)
		{
			delete mShapes[i];
			mShapes[i] = nullptr;
		}
	}
}

// -----------------------------------------------------------------------------

int Blink::Window::handle(int pEvent)
{
	// return 1 == event was handled

	if (pEvent == FL_KEYBOARD)
	{
		switch (Fl::event_key())
		{
			case 223:	// back tick
			{
				// show the command console
				mCommandConsole->show();
				return 1;
			}
			case FL_Enter:
			{
				// close the command console
				// triggers callback on mCommandConsole
				mCommandConsole->hide();
				return 1;
			}
			default:
				break;
		}
	}

	return Fl_Window::handle(pEvent);
}

// -----------------------------------------------------------------------------

void Blink::Window::onTextEnteredInCommanConsole()
{
	using namespace std;
	// triggers when enter is pressed
	// grab whats in the box now
	const string grabString = mCommandConsole->getString();

	// break up into whitespace separated components
	stringstream ss;
	ss << grabString;

	// horribly hacky at the moment
	string temp;
	ss >> temp;

	// get the x value
	int x = 0;
	ss >> x;

	// get the y value
	int y = 0;
	ss >> y;

	if (temp == "r.drawCircle")
	{
		// get the radius
		int r = 0;
		ss >> r;

		// now draw the circle
		attach(new Blink::Circle(Point(x, y), r));
	}
	else if (temp == "r.drawImage")
	{
		// filename
		string filename;
		ss >> filename;
			
		// what image?
		attach(new Blink::Image(Point(x, y), filename));
	}
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

// don't worry, Window cleans up it's shape pointers. Make sure to pass new directly to this function
void Blink::Window::attach(Shape* pShape)
{
	mShapes.push_back(pShape);
}

// -----------------------------------------------------------------------------

void Blink::Window::attach(Shape& pShape)
{
	mShapes.push_back(&pShape);
}

// -----------------------------------------------------------------------------

void Blink::Window::detach(Shape& pShape)
{
	//last attached will be first released
	for (unsigned int i = mShapes.size(); 0 < i; --i)
	{
		if (mShapes[i - 1] == &pShape)
		{
			mShapes.erase(mShapes.begin() + (i - 1));
		}
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
	// set up the console command widget
	attach(*mCommandConsole);
	mCommandConsole->hide();

	Fl_Window::resizable(this);
	Fl_Window::show();
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------