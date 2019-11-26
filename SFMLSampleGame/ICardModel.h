#pragma once
#include "stdafx.h"
#include "EnumBattlefield.h"
//interface for CardModel classes
class IGuiElement;
class ICardModel
{
	
public:
	using CardsVector = shared_ptr<vector<shared_ptr<IGuiElement>>>;
	virtual int GetStrength() = 0;
	virtual string GetName() = 0;
	virtual void SetStrength(int strength) = 0;
	virtual void SetName(string name) = 0;
	virtual void CardSpecialAbility(
		shared_ptr<IGuiElement> card,
		BattleField battlefield,
		CardsVector& userHandCards,
		CardsVector& userLowerBattlefieldCards,
		CardsVector& userUpperBattlefieldCards,
		CardsVector& enemyLowerBattlefieldCards,
		CardsVector& enemyUpperBattlefieldCards, 
		CardsVector& enemyHandCards
	) = 0;
};

