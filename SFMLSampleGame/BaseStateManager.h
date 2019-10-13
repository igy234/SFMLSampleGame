#pragma once
#include "IStateManager.h"
#include "IStateOperator.h"

class BaseStateManager : public IStateManager
{
protected:
	shared_ptr<RenderWindow> Window; //shared ptr to klasa z auto managerowaniem pamiecia (new i delette)
public:
	BaseStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager);
	void HandleEvent(const Event& evnt) = 0;
	void DrawWindowContents() = 0;
	void HandleMouseEvent(const Event& evnt) = 0;
};

