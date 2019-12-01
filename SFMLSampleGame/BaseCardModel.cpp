#include "stdafx.h"
#include "BaseCardModel.h"
#include "Utils.h"
#include "BaseCard.h"

BaseCardModel::BaseCardModel(int strength, string name, float expectedValue)
	:Strength(strength), Name(name), ExpectedValue(expectedValue)
{
}


BaseCardModel::~BaseCardModel()
{

}

void BaseCardModel::CardSpecialAbility(shared_ptr<IGuiElement> card, BattleField battlefield, ICardModel::CardsVector & userHandCards, ICardModel::CardsVector & userLowerBattlefieldCards, ICardModel::CardsVector & userUpperBattlefieldCards, ICardModel::CardsVector & enemyLowerBattlefieldCards, ICardModel::CardsVector & enemyUpperBattlefieldCards, ICardModel::CardsVector & enemyHandCards)
{
	

	switch (battlefield)
	{
	case BattleField::Lower:
		userLowerBattlefieldCards->push_back(card);

		break;
	case BattleField::Upper:
		userUpperBattlefieldCards->push_back(card);
		break;
	}
}

float BaseCardModel::CalculatePlayCoefficient(shared_ptr<IGuiElement> card, BattleField battlefield, ICardModel::CardsVector & userHandCards, ICardModel::CardsVector & userLowerBattlefieldCards, ICardModel::CardsVector & userUpperBattlefieldCards, ICardModel::CardsVector & enemyLowerBattlefieldCards, ICardModel::CardsVector & enemyUpperBattlefieldCards, ICardModel::CardsVector & enemyHandCards)
{
	vector<shared_ptr<IGuiElement>> dragons = FindAllDragons(enemyLowerBattlefieldCards, enemyUpperBattlefieldCards);

	return (Strength + RiskAllCards[enemyHandCards->size()][Strength - 1] + RiskNormalCardsDependingOnDragons[Strength - 1][dragons.size()]) / ExpectedValue;
}

vector<shared_ptr<IGuiElement>> BaseCardModel::FindAllDragons(ICardModel::CardsVector & LowerBattlefieldCards, ICardModel::CardsVector & UpperBattlefieldCards)
{
	vector<shared_ptr<IGuiElement>> vect = *LowerBattlefieldCards;
	vect.insert(vect.begin(), UpperBattlefieldCards->begin(), UpperBattlefieldCards->end());
	vector<shared_ptr<IGuiElement>> dragons;

	copy_if(vect.begin(), vect.end(), back_inserter(dragons),
		[](auto element)
	{
		return (static_pointer_cast<BaseCard>(element)->GetModel()->GetName().find("Dragon") != string::npos);
	});
	return dragons;
}

int BaseCardModel::GetStrength()
{
	return Strength;
}
string BaseCardModel::GetName()
{
	return Name;
}
void BaseCardModel::SetStrength(int strength)
{
	Strength = strength;
}
void BaseCardModel::SetName(string name)
{
	Name = name;
}

