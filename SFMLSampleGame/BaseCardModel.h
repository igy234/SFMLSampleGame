#pragma once
#include "ICardModel.h"

class BaseCardModel :public ICardModel
{
protected: 
	int Strength;
	string Name;
	float ExpectedValue;

	vector<shared_ptr<IGuiElement>> FindAllDragons(ICardModel::CardsVector& LowerBattlefieldCards,
		ICardModel::CardsVector& UpperBattlefieldCards);
public:
	virtual int GetStrength() override;
	virtual string GetName() override;
	virtual void SetStrength(int strength) override;
	virtual void SetName(string name) override;
	BaseCardModel(int strength, string name, float expectedValue);
	~BaseCardModel();
	virtual void CardSpecialAbility(
		shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;

	virtual float CalculatePlayCoefficient(shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards) override;

};

