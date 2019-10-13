#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
class DeckCallback : public ICallback
{
protected:
	shared_ptr<IStateOperator<GameState>> CurrentManager;
public:
	DeckCallback(shared_ptr<IStateOperator<GameState>> currentManager);
	~DeckCallback();
	virtual void action() override;
};

