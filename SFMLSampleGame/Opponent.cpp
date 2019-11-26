#include "stdafx.h"
#include "Opponent.h"
#include "Utils.h"
#include "EnumBattlefield.h"
#include "BaseCard.h"

Opponent::Opponent(shared_ptr<vector<shared_ptr<IGuiElement>>> handCards, shared_ptr<vector<shared_ptr<IGuiElement>>> lowerUserBattleField, 
	shared_ptr<vector<shared_ptr<IGuiElement>>> upperUserBattleField, shared_ptr<vector<shared_ptr<IGuiElement>>> lowerEnemyBattleField, 
	shared_ptr<vector<shared_ptr<IGuiElement>>> upperEnemyBattleField, shared_ptr<vector<shared_ptr<IGuiElement>>> enemyHandCards)
	: AiHandCards(handCards), 
	LowerUserBattleField(lowerUserBattleField),
	UpperUserBattleField(upperUserBattleField),
	LowerEnemyBattleField(lowerEnemyBattleField),
	UpperEnemyBattleField(upperEnemyBattleField),
	EnemyHandCards(enemyHandCards)
{
}

int Opponent::GetNumberOfCards()
{
	return AiHandCards->size();
}

void Opponent::MakeMove()
{
	if (!AiHandCards->size())
		return;
	int cardIndex = getRand(AiHandCards->size()-1);
	BattleField battlefield = static_cast<BattleField>(getRand(static_cast<int>(BattleField::Count)));
	auto currentSelectedCard = (*AiHandCards)[cardIndex];
	AiHandCards->erase(AiHandCards->begin() + cardIndex);
	auto card = static_pointer_cast<BaseCard>(currentSelectedCard);
	card->GetModel()->CardSpecialAbility(currentSelectedCard, battlefield, AiHandCards, LowerEnemyBattleField, UpperEnemyBattleField, LowerUserBattleField, UpperUserBattleField, EnemyHandCards);
}


Opponent::~Opponent()
{
}

