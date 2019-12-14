#pragma once
#include "ICallback.h"
#include "IStateOperator.h"

///Callback class managing callback to the deck state manager
class DeckCallback : public ICallback
{
protected:
	///shared pointer to IStateOperator managing the game state
	shared_ptr<IStateOperator<GameState>> CurrentManager; 
public:
	///@brief assigning current manager to the atribute of the class
	///@param "currentManager" representing state of the program
	DeckCallback(shared_ptr<IStateOperator<GameState>> currentManager); 
	~DeckCallback();
	///@brief assigning deck(gallery) game state to the CurrentManager attribute
	virtual void action() override; 
};

