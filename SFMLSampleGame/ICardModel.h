#pragma once
#include "stdafx.h"
//interface for CardModel classes
class ICardModel
{
public:
	virtual int GetStrength() = 0;
	virtual string GetName() = 0;
	virtual void SetStrength(int strength) = 0;
	virtual void SetName(string name) = 0;

	
};

