#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
#include "ICardOperator.h"
#include "BaseCard.h"
#include "IOpponent.h"
#include "EnumScreenFields.h"
#include "ButtonObject.h"

class IngameStateManager : public BaseStateManager, public ICardOperator
{
	int UserSumOfPoints = 0;
	int EnemySumOfPoints = 0;
	int RoundsLost = 0;
	int RoundsWon = 0;
	bool IsPlayerTurn;
	function<void(MatchState)> shuffleCallback;
	shared_ptr<IOpponent> opponent;
	shared_ptr<vector<shared_ptr<IGuiElement>>> UserHandCards; //vector holding cards in user's hand
	shared_ptr<vector<shared_ptr<IGuiElement>>> EnemyHandCards;
	shared_ptr<PlayLayout> Layout;
	shared_ptr<IGuiElement> CurrentSelectedCard = nullptr;
	shared_ptr<vector<shared_ptr<IGuiElement>>> LowerUserBattleField;
	shared_ptr<vector<shared_ptr<IGuiElement>>> UpperUserBattleField;
	shared_ptr<vector<shared_ptr<IGuiElement>>> LowerEnemyBattleField;
	shared_ptr<vector<shared_ptr<IGuiElement>>> UpperEnemyBattleField;
	shared_ptr<RectangleObject> UserPointsRec;
	shared_ptr<RectangleObject> EnemyPointsRec;
	shared_ptr<RectangleObject> RoundsRectangle;

	shared_ptr<RectangleObject> EnemyCardsCounter;
	shared_ptr<RectangleObject> TurnDisplayer;

	bool PlayCard(BattleField battlefield);
	int CalculateSumOfPoints(shared_ptr<vector<shared_ptr<IGuiElement>>> currentBattleField);
	void ArrangeCards(shared_ptr<vector<shared_ptr<IGuiElement>>> currentBattleField, EnumScreenFields fieldX, EnumScreenFields fieldY);
	void InitNewRound();
public:
	virtual void DrawWindowContents() override;
	IngameStateManager(shared_ptr<RenderWindow> window, 
		shared_ptr<IStateOperator<MatchState>> currentManager,
		shared_ptr<PlayLayout> playLayout,
		shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards,
		shared_ptr<vector<shared_ptr<IGuiElement>>> enemyHandCards, function<void(MatchState)> callbackFunction,
		shared_ptr<RectangleObject> roundsRectangle);

	~IngameStateManager();
	virtual void HandleMouseEvent(const Event& evnt) override;
	virtual void HandleEvent(const Event& evnt) override;

	void PerformCardOperation(shared_ptr<IGuiElement> card, Mouse::Button click) override;
	virtual void WhichBattlefield(BattleField battlfield) override;
	
	void OrganizeCards();

	virtual void initialize() override;

	void ResetRoundsScore();
	void UpdateRoundsRectangleText();
};

