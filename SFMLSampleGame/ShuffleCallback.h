#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
///Callback class managing callback to the shuffle state manager
class ShuffleCallback :	public ICallback
{
	///@brief Callback function used to set appropriate state of the match
	function<void()> CallbackFunction;
public:

	///@brief constructor ascribing callback
	///@param "callbackFunction" representing callback
	ShuffleCallback(function<void()> callbackFunction);
	~ShuffleCallback();

	///@brief method seting match state to shuffle state 
	void action() override;
};

