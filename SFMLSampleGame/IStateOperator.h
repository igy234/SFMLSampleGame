#pragma once
#include "stdafx.h"
///\file

///Enum class holding desrciptions for program's states
enum class GameState
{
	Play,
	Deck,
	Menu

};

///\file

///Enum class holding desrciptions for match states
enum class MatchState
{
	Shuffle,
	Ingame,
};

///Interface Class for state operator classes
template<typename T>
class IStateOperator
{
public:
	///@brief method setting new state 
	///@param "state" representing generic state of the program
	virtual void SetNewState(T state) = 0;

	///@brief method getting current state 
	///@returns generic state of the program
	virtual T GetCurrentState() = 0;
};

