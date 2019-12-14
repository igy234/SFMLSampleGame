#pragma once
#include "ICallback.h"
#include "IStateOperator.h"
///Callback class managing callback to the play state manager
class PlayCallback : public ICallback
{
protected:
	///used for holding the current manager
	shared_ptr<IStateOperator<GameState>> CurrentManager; 
public:
	///@brief constructor setting CurrentManager attribute as currentManager
	///@param "currentManager" representing state of the program
	PlayCallback(shared_ptr<IStateOperator<GameState>> currentManager); // setting CurrentManager as currentManager
	~PlayCallback();

	///@brief method seting Currentmanager's state to play state 
	virtual void action() override; 
};

