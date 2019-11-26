#pragma once
#include"IOpponent.h"
#include "IGuiElement.h"
class Opponent : public IOpponent
{
	shared_ptr<vector<shared_ptr<IGuiElement>>> AiHandCards; //cards held by ai
	shared_ptr<vector<shared_ptr<IGuiElement>>> LowerUserBattleField; //User battlefield 
	shared_ptr<vector<shared_ptr<IGuiElement>>> UpperUserBattleField; //User battlefield 
	shared_ptr<vector<shared_ptr<IGuiElement>>> LowerEnemyBattleField; //Enemy battlefield 
	shared_ptr<vector<shared_ptr<IGuiElement>>> UpperEnemyBattleField; //Enemy battlefield 
	shared_ptr<vector<shared_ptr<IGuiElement>>> EnemyHandCards; //cards held by user
public:
	Opponent(shared_ptr<vector<shared_ptr<IGuiElement>>> handCards, shared_ptr<vector<shared_ptr<IGuiElement>>> lowerUserBattleField,
		shared_ptr<vector<shared_ptr<IGuiElement>>> upperUserBattleField, shared_ptr<vector<shared_ptr<IGuiElement>>> lowerEnemyBattleField,
		shared_ptr<vector<shared_ptr<IGuiElement>>> upperEnemyBattleField, shared_ptr<vector<shared_ptr<IGuiElement>>> enemyHandCards);
	virtual int GetNumberOfCards() override;
	virtual void MakeMove() override;
	~Opponent();
};

