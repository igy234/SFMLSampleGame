#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
///Callback class managing callback to the menu state manager
class MenuCallback : public ICallback
{
protected:
	///used for holding the current manager
	shared_ptr<IStateOperator<GameState>> CurrentManager; 
public:
	///@brief constructor setting CurrentManager attribute as currentManager
	///@param "currentManager" representing state of the program
	MenuCallback(shared_ptr<IStateOperator<GameState>> currentManager); 
	~MenuCallback();

	///@brief method seting Currentmanager's state to menu state 
	virtual void action() override; 
};

