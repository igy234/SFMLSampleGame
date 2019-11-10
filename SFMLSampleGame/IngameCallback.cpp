#include "stdafx.h"
#include "IngameCallback.h"


IngameCallback::IngameCallback(function<void(MatchState)> callbackFunction)
	:CallbackFunction(callbackFunction)
{
}


IngameCallback::~IngameCallback()
{
}

void IngameCallback::action()
{
	CallbackFunction(MatchState::Ingame);
}
