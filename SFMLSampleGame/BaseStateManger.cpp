#include "stdafx.h"
#include "BaseStateManager.h"


BaseStateManager::BaseStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager)
	: Window(window)
{

}
