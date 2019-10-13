#pragma once
#include "BaseStateManager.h"
#include "MenuLayout.h"

class MenuStateManager : public BaseStateManager
{
protected:
	MenuLayout menuLayout;
public:
	MenuStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager);
	~MenuStateManager();
	void HandleEvent(const Event& evnt) override;
	void DrawWindowContents() override;
	void HandleMouseEvent(const Event& evnt) override;
};

