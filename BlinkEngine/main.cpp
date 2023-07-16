// -----------------------------------------------------------------------------
// https://lptcp.blogspot.com/
// 
/*
	Blink Engine
	
	Basically a wrapper around FLTK.

*/
// https://github.com/l-paz91/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "BasicInputBox.h"
#include "Window.h"

// -----------------------------------------------------------------------------

int main()
{
	using namespace Blink;

	// console commands:
	// r.drawCircle xValue yValue Radius
	// r.drawImage  xValue yValue filename.encoding

	Blink::Window window(Point(0, 0), 650, 600, "Blink Engine");
	
	return Fl::run();
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------