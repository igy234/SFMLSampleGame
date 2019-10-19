#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
class MenuCallback : public ICallback
{
protected:
	shared_ptr<IStateOperator<GameState>> CurrentManager;
public:
	MenuCallback(shared_ptr<IStateOperator<GameState>> currentManager);
	~MenuCallback();
	virtual void action() override;
};

