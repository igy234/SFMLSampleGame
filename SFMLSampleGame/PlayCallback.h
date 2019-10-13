#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
class PlayCallback : public ICallback
{
protected:
	shared_ptr<IStateOperator> CurrentManager;
public:
	PlayCallback(shared_ptr<IStateOperator> currentManager);
	~PlayCallback();
	virtual void action() override;
};

