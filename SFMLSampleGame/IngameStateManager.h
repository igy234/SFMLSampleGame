#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
class IngameStateManager :
	public BaseStateManager
{
	shared_ptr<PlayLayout> Layout;
public:
	virtual void DrawWindowContents() override;
	IngameStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout);
	~IngameStateManager();
	virtual void HandleMouseEvent(const Event& evnt) override;
	virtual void HandleEvent(const Event& evnt) override;
};

