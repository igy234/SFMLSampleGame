#include "stdafx.h"
#include "EndgameStateManager.h"
#

EndgameStateManager::EndgameStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout)
:BaseStateManager(window, currentManager),
Layout(playLayout)
{
}


EndgameStateManager::~EndgameStateManager()
{
}

void EndgameStateManager::DrawWindowContents()
{
	Layout->Show();
}

void EndgameStateManager::HandleMouseEvent(const Event& evnt)
{
	Layout->HandleMouseEvent(evnt);
}

void EndgameStateManager::HandleEvent(const Event& evnt)
{

}
