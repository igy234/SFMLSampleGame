#include "stdafx.h"
#include "Opponent.h"
#include "Utils.h"
#include "EnumBattlefield.h"
#include "BaseCard.h"

Opponent::Opponent(shared_ptr<vector<shared_ptr<IGuiElement>>> handCards, shared_ptr<vector<shared_ptr<IGuiElement>>> lowerUserBattleField, 
	shared_ptr<vector<shared_ptr<IGuiElement>>> upperUserBattleField, shared_ptr<vector<shared_ptr<IGuiElement>>> lowerEnemyBattleField, 
	shared_ptr<vector<shared_ptr<IGuiElement>>> upperEnemyBattleField)
	: HandCards(handCards), 
	LowerUserBattleField(lowerUserBattleField),
	UpperUserBattleField(upperUserBattleField),
	LowerEnemyBattleField(lowerEnemyBattleField),
	UpperEnemyBattleField(upperEnemyBattleField)
{
}

int Opponent::GetNumberOfCards()
{
	return HandCards->size();
}

void Opponent::MakeMove()
{
	if (!HandCards->size())
		return;
	int cardIndex = getRand(HandCards->size()-1);
	BattleField battlefield = static_cast<BattleField>(getRand(static_cast<int>(BattleField::Count)));
	auto currentSelectedCard = (*HandCards)[cardIndex];
	HandCards->erase(HandCards->begin() + cardIndex);
	auto card = static_pointer_cast<BaseCard>(currentSelectedCard);
	card->GetModel()->CardSpecialAbility(currentSelectedCard, battlefield, HandCards, LowerEnemyBattleField, UpperEnemyBattleField, LowerUserBattleField, UpperUserBattleField);

}


Opponent::~Opponent()
{
}

