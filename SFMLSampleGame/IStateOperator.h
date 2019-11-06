#pragma once
#include "stdafx.h"
//header holding 2 enum classes, one with game states, second with matchstates
//and template interface accepting any type of class as state parameter, and returning any type of class in getter
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

