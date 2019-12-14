#pragma once
#include "stdafx.h"
#include "BaseCard.h"
#include "EnumBattlefield.h"
///Interface class used for managing operations performed by cards
class ICardOperator
{
public: 
	///@brief method used to perform card's operation
	///@param "card" card for which operation should be performed
	///@param "click" parameter for specifying mouse button click 
	virtual void PerformCardOperation(shared_ptr<IGuiElement> card, Mouse::Button click) = 0;

	///@brief method specyfing in wchich battlefield card should be put
	///@param "battlefield" representing values of EnumBattlefield class 
	virtual void WhichBattlefield(BattleField battlfield) = 0;
};
