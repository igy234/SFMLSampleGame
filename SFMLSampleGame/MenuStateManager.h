#pragma once
#include "BaseStateManager.h"
#include "MenuLayout.h"

class MenuStateManager : public BaseStateManager
{
protected:
	MenuLayout menuLayout;
	ButtonObject b1, b2, b3;
public:
	MenuStateManager(shared_ptr<RenderWindow> window);
	~MenuStateManager();
	void HandleEvent(const Event& evnt) override;
	void DrawWindowContents() override;
	void HandleMouseEvent(const Event& evnt) override;
};

