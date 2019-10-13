#pragma once
#include "IStateOperator.h"
class StateOperator : public IStateOperator
{
protected:
	GameState CurrentState = GameState::Menu;
public:
	StateOperator();
	~StateOperator();
	virtual void SetNewState(GameState state) override;
	virtual GameState GetCurrentState() override;
};

