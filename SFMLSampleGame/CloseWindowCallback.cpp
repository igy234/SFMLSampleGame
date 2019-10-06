#include "stdafx.h"
#include "CloseWindowCallback.h"


CloseWindowCallback::CloseWindowCallback(shared_ptr<RenderWindow> window)
	:Window(window)
{
}


void CloseWindowCallback::action()
{
	Window->close();
}
