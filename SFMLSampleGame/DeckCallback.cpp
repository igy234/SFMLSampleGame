#include "stdafx.h"
#include "DeckCallback.h"


DeckCallback::DeckCallback(shared_ptr<IStateOperator<GameState>> currentManager)
	:CurrentManager(currentManager)
{
}


DeckCallback::~DeckCallback()
{
}

void DeckCallback::action()
{
	CurrentManager->SetNewState(GameState::Deck);
}