#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
#include"ICardOperator.h"
#include "BaseCard.h"
class ShuffleStateManager :	public BaseStateManager, public ICardOperator
{
	shared_ptr<ICallback> ingameCallback;
	shared_ptr<PlayLayout> Layout;
	shared_ptr<vector<shared_ptr<IGuiElement>>> UserHandCards; //vector holding cards in user's hand
	shared_ptr<RectangleObject> ExchangeCardsInfo;
	shared_ptr<ButtonObject> b3;
	int ExchangeCount=5;
public:
	virtual void DrawWindowContents() override;
	ShuffleStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout, 
		shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards, shared_ptr<ICallback> ingameCall);
	~ShuffleStateManager();
	virtual void HandleMouseEvent(const Event& evnt) override;
	virtual void HandleEvent(const Event& evnt) override;
	void HandleExchangeCardsInformation(); //nothing yet

	void PerformCardOperation(shared_ptr<IGuiElement> card, Mouse::Button click) override;
	virtual void WhichBattlefield(BattleField battlfield) override {};
};

