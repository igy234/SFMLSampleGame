#pragma once
#include "ICardModel.h"
///Base class for card's model operations 
class BaseCardModel :public ICardModel
{
protected: 
	///strength of the card
	int Strength;
	/// name of the card 
	string Name; 
	///expected value of card 
	float ExpectedValue; 

	///@brief method finding all dragons on the enemy battlefield
	///@param "LowerBattlefieldCards" representing the cards on lower battlefield
	///@param "UpperBattlefieldCards" representing the cards on upper battlefield
	///@return vector containing dragons
	vector<shared_ptr<IGuiElement>> FindAllDragons(ICardModel::CardsVector& LowerBattlefieldCards,
		ICardModel::CardsVector& UpperBattlefieldCards); 

public:
	///@brief getter for strength attribute
	///@returns strength of the card
	virtual int GetStrength() override;

	///@brief getter for name attribute
	///@returns name of the card
	virtual string GetName() override;

	///@brief setter for strength attribute
	///@param "strength" of the card
	virtual void SetStrength(int strength) override;

	///@brief setter for name attribute
	///@param "name" of the card
	virtual void SetName(string name) override;
	
	///@brief ascribing strength, name and expected value of the cards
	///@param "strength" of the card
	///@param "name" of the card
	///@param "expectedValue" of the card
	BaseCardModel(int strength, string name, float expectedValue);
	~BaseCardModel();
	
	///@brief method perfroming card's special ability, here just puting to correct battlefield
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
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

	///@brief method calcualting coeffitients of card, here for cards without special abilities
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
	///@return calculated play coefficient
	virtual float CalculatePlayCoefficient(shared_ptr<IGuiElement> card, 
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards) override;
};

