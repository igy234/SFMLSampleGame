#pragma once
#include "stdafx.h"
#include "EnumCardName.h"

///Class responsible for generation of random enum names for cards
class GenerateCards 
{
protected:

public:
	///@brief method generating random number in range 0-25
	///@return appropriate enum value for generated number
	EnumCardName GenerateRandomCardNameEnum();

	GenerateCards();
	~GenerateCards();
	
};

