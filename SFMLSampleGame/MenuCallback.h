#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
class MenuCallback : public ICallback
{
protected:
	shared_ptr<IStateOperator> CurrentManager;
public:
	MenuCallback(shared_ptr<IStateOperator> currentManager);
	MenuCallback();
	~MenuCallback();
	virtual void action() override;
};

