#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
class PlayCallback : public ICallback
{
protected:
	shared_ptr<IStateOperator<GameState>> CurrentManager;
public:
	PlayCallback(shared_ptr<IStateOperator<GameState>> currentManager);
	~PlayCallback();
	virtual void action() override;
};

