#include "stdafx.h"
#include "StateOperator.h"


StateOperator::StateOperator()
{
}


StateOperator::~StateOperator()
{
}

void StateOperator::SetNewState(GameState state)
{
	CurrentState = state;
}
GameState StateOperator::GetCurrentState()
{
	return CurrentState;
}