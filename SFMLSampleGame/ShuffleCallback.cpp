#include "stdafx.h"
#include "ShuffleCallback.h"


ShuffleCallback::ShuffleCallback(function<void()> callbackFunction)
	:CallbackFunction(callbackFunction)
{
}


ShuffleCallback::~ShuffleCallback()
{
}

void ShuffleCallback::action()
{
	CallbackFunction();
}