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
	
	BattleField battlefield = static_cast<BattleField>(getRand(static_cast<int>(BattleField::Count)));
	
	if (LowerEnemyBattleField->size() >= 7)
	{
		battlefield = BattleField::Upper;
	}

	if (UpperEnemyBattleField->size() >= 7)
	{
		battlefield = BattleField::Lower;
	}

	if (LowerEnemyBattleField->size() >= 7 && UpperEnemyBattleField->size() >= 7)
	{
		return;
	}
	
	vector<float> coefficients;
	for (auto element : *AiHandCards) 
	{
		auto card = static_pointer_cast<BaseCard>(element);
		auto coef = card->GetModel()->CalculatePlayCoefficient(element, battlefield, AiHandCards, LowerEnemyBattleField, UpperEnemyBattleField, LowerUserBattleField, UpperUserBattleField, EnemyHandCards);
		coefficients.push_back(coef);

		//cout << " card name: " << card->GetModel()->GetName() << " coef: " << coef << endl; for debbuging purposes
	}
	//cout << endl;
	
	auto maxCoefficient = max_element(begin(coefficients), end(coefficients)); // c++11
	int cardIndex = maxCoefficient - coefficients.begin();
	auto currentSelectedCard = (*AiHandCards)[cardIndex];
	AiHandCards->erase(AiHandCards->begin() + cardIndex);
	auto card = static_pointer_cast<BaseCard>(currentSelectedCard);
	card->GetModel()->CardSpecialAbility(currentSelectedCard, battlefield, AiHandCards, LowerEnemyBattleField, UpperEnemyBattleField, LowerUserBattleField, UpperUserBattleField, EnemyHandCards);
}


Opponent::~Opponent()
{
}

