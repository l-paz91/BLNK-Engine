// -----------------------------------------------------------------------------
#ifndef Window_H
#define Window_H
// -----------------------------------------------------------------------------
// 
/*
	Window is a simple wrapper around Fl_Window that you can attach widgets to.

	This wrapper is based off support code to "Programming -- Principles and
	Practice Using C++" by Bjarne Stroustrup

*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Point.h"

#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Widget.H>
#include <vector>

// -----------------------------------------------------------------------------

namespace Blink
{
	class BasicInputBox;
	class Widget;
	class Shape;

	// -----------------------------------------------------------------------------

	class Window : public Fl_Window
	{
	public:
		Window(int pX, int pY, const char* pLabel);	// let the system pick the location
		Window(const Point& pPoint, int pWidth, int pHeight, const char* pLabel);
		virtual ~Window();

		// Fl_Window Interface
		virtual int handle(int pEvent) override;
		// ~Fl_Window Interface

		// actions
		void onTextEnteredInCommandConsole();

		const int getWidth() const { return mWidth; }
		const int getHeight() const { return mHeight; }

		void resize(int pWidth, int pHeight)
		{
			mWidth = pWidth;
			mHeight = pHeight;
			Fl_Window::size(pWidth, pHeight);
		}

		void setLabel(const char* pLabel) { Fl_Window::label(pLabel); }

		void attach(Widget& pWidget);
		void detach(Widget& pWidget);

		void attach(Shape& pShape);
		void attach(Shape* pShape);
		void detach(Shape& pShape);

	protected:
		void draw();

	private:
		void init();

		std::vector<Shape*> mShapes;
		BasicInputBox* mCommandConsole;

		int mWidth;
		int mHeight;
	};

	inline int getScreenWidth() { return Fl::w(); }
	inline int getScreenHeight() { return Fl::h(); }
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !Window_H