// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "BasicInputBox.h"

#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <sstream>

// -----------------------------------------------------------------------------

int Blink::BasicInputBox::getInt()
{
	Fl_Input& inputWidget = referenceTo<Fl_Input>(mFlWidget);

	const char* value = inputWidget.value();
	if (!isdigit(value[0]) && value[0] != '-')
	{
		return -999999;
	}

	//if it's a negative number, make sure it correctly coverts it
	int convertedValue = atoi(value);
	return convertedValue;
}

// -----------------------------------------------------------------------------

float Blink::BasicInputBox::getFloat()
{
	Fl_Input& inputWidget = referenceTo<Fl_Input>(mFlWidget);

	const char* value = inputWidget.value();
	if (!isdigit(value[0]))
	{
		return -999999;
	}

	return static_cast<float>(atof(value));
}

// -----------------------------------------------------------------------------

std::string Blink::BasicInputBox::getString()
{
	Fl_Input& inputWidget = referenceTo<Fl_Input>(mFlWidget);
	return std::string(inputWidget.value());
}

// -----------------------------------------------------------------------------

char Blink::BasicInputBox::getChar()
{
	Fl_Input& inputWidget = referenceTo<Fl_Input>(mFlWidget);
	const char* value = inputWidget.value();
	return *value;
}

// -----------------------------------------------------------------------------

void Blink::BasicInputBox::put(const std::string& pText)
{
	Fl_Output& outputWidget = referenceTo<Fl_Output>(mFlWidget);
	std::stringstream stringstream;
	stringstream << pText;
	outputWidget.value(stringstream.str().c_str());
}

// -----------------------------------------------------------------------------

void Blink::BasicInputBox::attach(Window& pWindow)
{
	mFlWidget = new Fl_Input(int(mLocation.mX), int(mLocation.mY), mWidth, mHeight, mLabel.c_str());
	mFlWidget->callback(reinterpret_cast<Fl_Callback*>(mCallback), &pWindow);
	mWindow = &pWindow;
}


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------