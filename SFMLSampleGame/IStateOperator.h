#pragma once
#include "stdafx.h"
enum class GameState
{
	Play,
	Deck,
	Menu

};

class IStateOperator
{
public:
	virtual void SetNewState(GameState state) = 0;
	virtual GameState GetCurrentState() = 0;

};

