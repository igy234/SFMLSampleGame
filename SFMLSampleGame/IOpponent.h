#pragma once
#include "stdafx.h"
///Interface for managing AI
class IOpponent
{
public:
	///@brief method responsible for Ai's decision and move making
	virtual void MakeMove() = 0;

	///@brief method responsible for calculating number of cards in AI's hand
	///@returns number of cards in AI's hand
	virtual int GetNumberOfCards() = 0;
};

