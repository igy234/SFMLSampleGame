#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
///Callback class managing callback to the Ingame state manager
class IngameCallback :	public ICallback
{
	///Callback function used to set appropriate state of the match
	function<void(MatchState)> CallbackFunction;
public:
	///@brief constructor ascribing callback
	///@param "callbackFunction" representing callback
	IngameCallback(function<void(MatchState)> callbackFunction);
	~IngameCallback();

	///@brief method seting match state to ingame state 
	virtual void action() override; 
};

