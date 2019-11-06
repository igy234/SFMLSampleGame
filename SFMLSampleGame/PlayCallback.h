#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
//class managing callback to the play state manager
class PlayCallback : public ICallback
{
protected:
	shared_ptr<IStateOperator<GameState>> CurrentManager; //used for holding the current manager
public:
	PlayCallback(shared_ptr<IStateOperator<GameState>> currentManager); // setting CurrentManager as currentManager
	~PlayCallback();
	virtual void action() override; // method seting Currentmanager state to play state 
};

