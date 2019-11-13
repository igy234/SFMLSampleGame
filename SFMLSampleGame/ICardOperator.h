#pragma once
#include "stdafx.h"
#include "BaseCard.h"
enum class BattleField
{
	Lower,
	Upper
};
class ICardOperator
{
public: 
	virtual void PerformCardOperation(shared_ptr<IGuiElement> card, Mouse::Button click) = 0;
	virtual void WhichBattlefield(BattleField battlfield) = 0;
};
