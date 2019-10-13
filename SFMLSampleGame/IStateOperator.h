#pragma once
#include "stdafx.h"
enum class GameState
{
	Play,
	Deck,
	Menu

};

enum class MatchState
{
	Shuffle,
	Ingame
};

template<typename T>
class IStateOperator
{
public:
	virtual void SetNewState(T state) = 0;
	virtual T GetCurrentState() = 0;
};

