#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
#include "IStateOperator.h"
class PlayStateManager :	public BaseStateManager
{
	PlayLayout playLayout;
public:
	void HandleEvent(const Event& evnt) override;
	void DrawWindowContents() override;
	void HandleMouseEvent(const Event& evnt) override;
	PlayStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator> currentManager);
	~PlayStateManager();
};

