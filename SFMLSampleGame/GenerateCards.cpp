#include "stdafx.h"
#include "GenerateCards.h"


GenerateCards::GenerateCards()
{
}


GenerateCards::~GenerateCards()
{
}

EnumCardName GenerateCards::GenerateRandomCardNameEnum()
{
	using namespace std::chrono;
	chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(system_clock::now().time_since_epoch());
	unsigned int msNumber = ms.count();
	unsigned int result = msNumber % static_cast<int>(EnumCardName::COUNT);

	return EnumCardName(result);
}