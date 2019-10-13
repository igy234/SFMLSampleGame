#include "stdafx.h"
#include "MenuCallback.h"


MenuCallback::MenuCallback(shared_ptr<IStateOperator> currentManager)
:CurrentManager(currentManager)
{
}


MenuCallback::~MenuCallback()
{
}

void MenuCallback::action()
{
	CurrentManager->SetNewState(GameState::Menu);
}