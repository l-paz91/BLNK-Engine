// -----------------------------------------------------------------------------

//--INCLUDES--//
#include "Widget.h"

// -----------------------------------------------------------------------------

Blink::Widget::Widget(Point pXY, int pWidth, int pHeight, const std::string& pLabel, Callback pCallback)
	: mWindow(nullptr)
	, mFlWidget(nullptr)
	, mLabel(pLabel)
	, mLocation(pXY)
	, mCallback(pCallback)
	, mWidth(pWidth)
	, mHeight(pHeight)
{

}

// -----------------------------------------------------------------------------

Blink::Widget::~Widget()
{
	if (mFlWidget)
	{
		delete mFlWidget;
		mFlWidget = nullptr;
	}
}

// -----------------------------------------------------------------------------

void Blink::Widget::move(int pNewX, int pNewY)
{
	hide();
	mLocation.mX = pNewX;
	mLocation.mY = pNewY;

	mFlWidget->position(mLocation.asIntX(), mLocation.asIntY());
	show();
}

// -----------------------------------------------------------------------------

void Blink::Widget::hide()
{
	mFlWidget->hide();
}

// -----------------------------------------------------------------------------

void Blink::Widget::show()
{
	mFlWidget->show();
}

// -----------------------------------------------------------------------------

int Blink::Widget::takeFocus()
{
	return mFlWidget->take_focus();
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------