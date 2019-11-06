#pragma once
#include "IStateManager.h"
#include "IStateOperator.h"

// CBase state manager class, parent for other state managers 
class BaseStateManager : public IStateManager
{
protected:
	shared_ptr<RenderWindow> Window; //shared_ptr is a class with memory automenagement (new and delete)
public:
	BaseStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager);
	void HandleEvent(const Event& evnt) = 0;
	void DrawWindowContents() = 0;
	void HandleMouseEvent(const Event& evnt) = 0;
};

