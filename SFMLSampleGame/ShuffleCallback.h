#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
class ShuffleCallback :	public ICallback
{
	function<void()> CallbackFunction;
public:
	ShuffleCallback(function<void()> callbackFunction);
	~ShuffleCallback();
	void action() override;
};

