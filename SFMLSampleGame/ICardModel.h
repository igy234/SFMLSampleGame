#pragma once
#include "stdafx.h"
#include "EnumBattlefield.h"

class IGuiElement; //include but in different way to avoid conflicts
///Interface for CardModel classes
class ICardModel
{
	
public:
	using CardsVector = shared_ptr<vector<shared_ptr<IGuiElement>>>;
	///@brief getter for strength attribute
	///@returns strength of the card
	virtual int GetStrength() = 0;

	///@brief getter for name attribute
	///@returns name of the card
	virtual string GetName() = 0;

	///@brief setter for strength attribute
	///@param "strength" of the card
	virtual void SetStrength(int strength) = 0;

	///@brief setter for name attribute
	///@param "name" of the card
	virtual void SetName(string name) = 0;

	///@brief method perfroming card's special ability
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
		CardsVector& userHandCards,
		CardsVector& userLowerBattlefieldCards,
		CardsVector& userUpperBattlefieldCards,
		CardsVector& enemyLowerBattlefieldCards,
		CardsVector& enemyUpperBattlefieldCards, 
		CardsVector& enemyHandCards
	) = 0;

	///@brief method calcualting coeffitients of card
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
		CardsVector& userHandCards,
		CardsVector& userLowerBattlefieldCards,
		CardsVector& userUpperBattlefieldCards,
		CardsVector& enemyLowerBattlefieldCards,
		CardsVector& enemyUpperBattlefieldCards,
		CardsVector& enemyHandCards) = 0;
};

