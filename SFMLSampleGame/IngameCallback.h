#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
class IngameCallback :	public ICallback
{
	function<void(MatchState)> CallbackFunction;
public:
	IngameCallback(function<void(MatchState)> callbackFunction);
	~IngameCallback();
	virtual void action() override; // method seting Currentmanager state to ingame state 
};

