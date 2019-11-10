#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
class ShuffleStateManager :	public BaseStateManager
{
	shared_ptr<PlayLayout> Layout;
public:
	virtual void DrawWindowContents() override;
	ShuffleStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout);
	~ShuffleStateManager();
	virtual void HandleMouseEvent(const Event& evnt) override;
	virtual void HandleEvent(const Event& evnt) override;
};

