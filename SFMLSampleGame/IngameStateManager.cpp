#include "stdafx.h"
#include "InGameStateManager.h"


IngameStateManager::IngameStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout, shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards)
	:BaseStateManager(window, currentManager),
	UserHandCards(userHandCards),
	Layout(playLayout)
{
}


IngameStateManager::~IngameStateManager()
{
}

void IngameStateManager::DrawWindowContents()
{
	Layout->Show();
}

void IngameStateManager::HandleMouseEvent(const Event& evnt)
{
	Layout->HandleMouseEvent(evnt);
}


void IngameStateManager::HandleEvent(const Event& evnt)
{

}