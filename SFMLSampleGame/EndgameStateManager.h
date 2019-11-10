#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
class EndgameStateManager :
	public BaseStateManager
{
	shared_ptr<PlayLayout> Layout;
public:
	virtual void DrawWindowContents() override;
	EndgameStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout);
	~EndgameStateManager();
	virtual void HandleMouseEvent(const Event& evnt) override;
	virtual void HandleEvent(const Event& evnt) override;
};

