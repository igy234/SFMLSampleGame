#include "stdafx.h"
#include "GenerateCards.h"


GenerateCards::GenerateCards()
{
	srand(time(NULL));
}


GenerateCards::~GenerateCards()
{
}

EnumCardName GenerateCards::GenerateRandomCardNameEnum()
{
	return EnumCardName(rand() % static_cast<int>(EnumCardName::COUNT));
}