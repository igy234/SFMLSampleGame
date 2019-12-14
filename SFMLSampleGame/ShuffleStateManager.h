#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
#include"ICardOperator.h"
#include "BaseCard.h"
///Class managing the Ingame state of the match
class ShuffleStateManager :	public BaseStateManager, public ICardOperator
{
	///Callback for ingame state manager
	shared_ptr<ICallback> ingameCallback;

	///object responsible for managing layout for Play state of the program
	shared_ptr<PlayLayout> Layout;

	///vector holding cards in user's hand
	shared_ptr<vector<shared_ptr<IGuiElement>>> UserHandCards; 

	///rectangle delivering info about card exchange
	shared_ptr<RectangleObject> ExchangeCardsInfo;

	///End exchange button
	shared_ptr<ButtonObject> b3;

	///attribute holding number of user's exchanges default set to 3
	int ExchangeCount=3;
public:

	///@brief method calling Play layout to draw window contents
	virtual void DrawWindowContents() override;

	///@brief constructor ascribing values to attributes of the class and calling initialize() method
	///@param "window" representing program's window
	///@param "currentManager" representing state manager 
	///@param "playLayout" representing play layout of the game
	///@param "userHandCards" vector representing cards in user's hand
	///@param "ingameCall" representing match state changing callback function
	ShuffleStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout, 
		shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards, shared_ptr<ICallback> ingameCall);
	~ShuffleStateManager();

	///@brief method handling mouse events via Play layout HandleMouseEvent method
	///@param "evnt" parameter describing event type for mouse handling
	virtual void HandleMouseEvent(const Event& evnt) override;

	///@brief method responsible for handling events in Shuffle state
	///@param "evnt" parameter describing event type for event handling
	virtual void HandleEvent(const Event& evnt) override;

	///@brief method used to exchange selected card on RMB
	///@param "card" card for which operation should be performed
	///@param "click" parameter for specifying mouse button click 
	void PerformCardOperation(shared_ptr<IGuiElement> card, Mouse::Button click) override;

	///@brief method specyfing in wchich battlefield card should be put, here no use
	///@param "battlefield" representing values of EnumBattlefield class 
	virtual void WhichBattlefield(BattleField battlfield) override {};

	///@brief method initializing shuffle state and card exchange for each new round, organizing exchenge info rectangle, and managing gui elements for current match state
	virtual void initialize() override;
};

