#pragma once
#include "ICardModel.h"

class BaseCardModel :public ICardModel
{
private: 
	int Strength;
	string Name;
public:
	virtual int GetStrength() override;
	virtual string GetName() override;
	virtual void SetStrength(int strength) override;
	virtual void SetName(string name) override;
	BaseCardModel(int strength, string name);
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
	) override 	{
		switch (battlefield)
		{
		case BattleField::Lower:
			userLowerBattlefieldCards->push_back(card);

			break;
		case BattleField::Upper:
			userUpperBattlefieldCards->push_back(card);
			break;
		}
	};

};

