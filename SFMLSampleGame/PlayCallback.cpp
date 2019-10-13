#include "stdafx.h"
#include "PlayCallback.h"


PlayCallback::PlayCallback(shared_ptr<IStateOperator> currentManager)
	:CurrentManager(currentManager)
{
}


PlayCallback::~PlayCallback()
{
}

void PlayCallback::action()
{
	CurrentManager->SetNewState(GameState::Play);
}