// -----------------------------------------------------------------------------
#ifndef BasicInputBox_H
#define BasicInputBox_H
// -----------------------------------------------------------------------------
// 
/*
	A basic input box is a Widget (which is an FL_Widget under the hood)
	

*/
// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Widget.h"

#include <string>

// -----------------------------------------------------------------------------

namespace Blink
{
	class BasicInputBox : public Widget
	{
	public:
		BasicInputBox(Point pPoint, int pWidth, int pHeight, const std::string& pLabel, Callback pCallback)
			: Widget(pPoint, pWidth, pHeight, pLabel, pCallback)
		{ }

		int getInt();
		float getFloat();
		std::string getString();
		char getChar();

		void put(const std::string& pText);	// put text into the input box

		void attach(Window& pWindow);
	};
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#endif // !BasicInputBox_H