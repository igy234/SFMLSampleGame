#pragma once
#include "stdafx.h"
class IOpponent
{
public:
	virtual void MakeMove() = 0;
	virtual int GetNumberOfCards() = 0;
};

