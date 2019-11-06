#include "stdafx.h"
#include "ShuffleManager.h"


ShuffleManager::ShuffleManager()
{
	srand(time(NULL));
}


ShuffleManager::~ShuffleManager()
{
}

EnumCardName ShuffleManager::GenerateRandomCardNameEnum()
{
	return EnumCardName(rand() % static_cast<int>(EnumCardName::COUNT));
}