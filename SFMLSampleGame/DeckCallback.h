#pragma once
#include "ICallback.h"
#include "IStateOperator.h"

//class managing callback to the deck state manager
class DeckCallback : public ICallback
{
protected:
	shared_ptr<IStateOperator<GameState>> CurrentManager; 
public:
	DeckCallback(shared_ptr<IStateOperator<GameState>> currentManager); //assigning current manager to the atribute of the class
	~DeckCallback();
	virtual void action() override; //assigning deck gamestate to the CurrentManager attribute
};

