#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
#include "ICardOperator.h"
#include "BaseCard.h"

class IngameStateManager : public BaseStateManager, public ICardOperator
{
	shared_ptr<vector<shared_ptr<IGuiElement>>> UserHandCards; //vector holding cards in user's hand
	shared_ptr<PlayLayout> Layout;
	shared_ptr<IGuiElement> CurrentSelectedCard = nullptr;
	shared_ptr<vector<shared_ptr<IGuiElement>>> LowerUserBattleField;
	shared_ptr<vector<shared_ptr<IGuiElement>>> UpperUserBattleField;
	shared_ptr<vector<shared_ptr<IGuiElement>>> LowerEnemyBattleField;
	shared_ptr<vector<shared_ptr<IGuiElement>>> UpperEnemyBattleField;
	shared_ptr<RectangleObject> UserPointsRec;
	shared_ptr<RectangleObject> EnemyPointsRec;
	void OrganizeCards();
	void PlayCard(BattleField battlefield);
public:
	virtual void DrawWindowContents() override;
	IngameStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout, shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards);
	~IngameStateManager();
	virtual void HandleMouseEvent(const Event& evnt) override;
	virtual void HandleEvent(const Event& evnt) override;

	void PerformCardOperation(shared_ptr<IGuiElement> card, Mouse::Button click) override;
	virtual void WhichBattlefield(BattleField battlfield) override;
	
};

