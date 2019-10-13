#include "stdafx.h"
#include "BaseStateManager.h"


BaseStateManager::BaseStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator> currentManager)
	: Window(window)
{

}
