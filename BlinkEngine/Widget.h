// -----------------------------------------------------------------------------
#ifndef Widget_H
#define Widget_H
// -----------------------------------------------------------------------------
// 
/*
	Widget is a handle to an Fl_Widget - it is *NOT* an Fl_Widget
	We try to keep our interface classes at arms length from FLTK

*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "BlinkCallback.h"
#include "Point.h"
#include "Window.h"

#include <Fl/Fl_Widget.H>
#include <string>

// -----------------------------------------------------------------------------

namespace Blink
{
	// -----------------------------------------------------------------------------

	class Widget
	{
	public:
		Widget(Point pXY, int pWidth, int pHeight, const std::string& pLabel, Callback pCallback);
		~Widget();

		// Fl_Widget interface
		virtual void move(int pNewX, int pNewY);
		virtual void hide();
		virtual void show();
		virtual void attach(Window& pWindow) = 0;
		int takeFocus();
		// ~Fl_Widget Interface

	protected:
		Window* mWindow;		// every Widget belongs to a Window
		Fl_Widget* mFlWidget;	// connection to a FLTK Widget

		std::string mLabel;
		Callback mCallback;
		Point mLocation;
		int mWidth;
		int mHeight;

	private:
		Widget& operator=(const Widget&);	// disable copying of Widget
		Widget(const Widget&);
	};
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !Widget_H