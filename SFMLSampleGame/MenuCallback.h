#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
//class managing callback to the menu state manager
class MenuCallback : public ICallback
{
protected:
	shared_ptr<IStateOperator<GameState>> CurrentManager; //used for holding the current manager
public:
	MenuCallback(shared_ptr<IStateOperator<GameState>> currentManager); // setting CurrentManager as currentManager
	~MenuCallback();
	virtual void action() override; // method seting Currentmanager state to menu state 
};

