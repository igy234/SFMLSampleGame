#pragma once
#include"IOpponent.h"
#include "IGuiElement.h"
///Class for managing AI
class Opponent : public IOpponent
{
	///vector of cards held by AI
	shared_ptr<vector<shared_ptr<IGuiElement>>> AiHandCards; 

	///vector of cards in lower user's battlefield 
	shared_ptr<vector<shared_ptr<IGuiElement>>> LowerUserBattleField; 

	///vector of cards in upper user's battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> UpperUserBattleField; 

	///vector of cards in lower Ai's battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> LowerEnemyBattleField; 

	///vector of cards in upper Ai's battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> UpperEnemyBattleField; 

	///vector of cards held by user
	shared_ptr<vector<shared_ptr<IGuiElement>>> EnemyHandCards; 
public:

	///@brief constructor ascribing values to attributes
	///@param "handCards" vector of cards held by AI
	///@param "lowerUserBattleField" representing vector of cards in lower user's battlefield 
	///@param "upperUserBattleField" representing vector of cards in upper user's battlefield
	///@param "lowerEnemyBattleField" representing vector of cards in lower Ai's battlefield
	///@param "upperEnemyBattleField" representing vector of cards in upper Ai's battlefield
	///@param "enemyHandCards" representing vector of cards held by user
	Opponent(shared_ptr<vector<shared_ptr<IGuiElement>>> handCards, shared_ptr<vector<shared_ptr<IGuiElement>>> lowerUserBattleField,
		shared_ptr<vector<shared_ptr<IGuiElement>>> upperUserBattleField, shared_ptr<vector<shared_ptr<IGuiElement>>> lowerEnemyBattleField,
		shared_ptr<vector<shared_ptr<IGuiElement>>> upperEnemyBattleField, shared_ptr<vector<shared_ptr<IGuiElement>>> enemyHandCards);

	///@brief method responsible for calculating number of cards in AI's hand
	///@returns number of cards in AI's hand
	virtual int GetNumberOfCards() override;

	///@brief method responsible for Ai's decision and move making
	virtual void MakeMove() override;

	~Opponent();
};

