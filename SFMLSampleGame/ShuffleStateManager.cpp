#include "stdafx.h"
#include "ShuffleStateManager.h"


ShuffleStateManager::ShuffleStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout)
	:BaseStateManager(window, currentManager),
	Layout(playLayout)
{

}


ShuffleStateManager::~ShuffleStateManager()
{
}

void ShuffleStateManager::DrawWindowContents()
{
	Layout->Show();
}

void ShuffleStateManager::HandleMouseEvent(const Event& evnt)
{
	Layout->HandleMouseEvent(evnt);
}

void ShuffleStateManager::HandleEvent(const Event& evnt)
{

}