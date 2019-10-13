#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
class DeckCallback : public ICallback
{
protected:
	shared_ptr<IStateOperator> CurrentManager;
public:
	DeckCallback(shared_ptr<IStateOperator> currentManager);
	~DeckCallback();
	virtual void action() override;
};

