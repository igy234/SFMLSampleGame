#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
#include "IStateOperator.h"
#include "IngameStateManager.h"
#include "ShuffleStateManager.h"
///Class managing the play state of the game
class PlayStateManager :public BaseStateManager
{
private:
	///shared pointer to Play Layout object managing the layout in this state
	shared_ptr<PlayLayout> playLayout;

	///shared pointer to IStateOperator holding and ascribing states of the match
	shared_ptr<IStateOperator<MatchState>> StateHandler;

	///one of two match state managers
	shared_ptr<ShuffleStateManager> ShuffleManager;

	///one of two match state managers 
	shared_ptr<IngameStateManager> IngameManager;

	///attribute holding current state manager
	shared_ptr<IStateManager> CurrentManager;

	///vector holding cards in user's hand
	shared_ptr<vector<shared_ptr<IGuiElement>>> UserHandCards; 

	///vector holding cards in AI's hand
	shared_ptr<vector<shared_ptr<IGuiElement>>> EnemyHandCards; 

	///rectangle responsible for showing information about win/lost rounds in the game
	shared_ptr<RectangleObject> RoundsRectangle;
public:

	///@brief method switching current match manager to appropriate one
	void StateSwitch();

	///@brief method handling all types of events
	///@param "evnt" parameter describing event type for event handling
	void HandleEvent(const Event& evnt) override; 

	///@brief method calling layout to draw window's contents for current state
	void DrawWindowContents() override; 

	///@brief method calling layout to handle its mouse events
	///@param "evnt" parameter describing event type for mouse handling
	void HandleMouseEvent(const Event& evnt) override; 

	///@brief constructor creating buttons with appropriate callbacks and assigning them to vector of gui elements, managing callback handling, creating cards for AI and user, initial state switching, creating match state managers
	///@param "window" representing program's window
	///@param "currentManager" representing state of the program
	PlayStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager);
	~PlayStateManager();

	///@brief getter for current manager
	///@returns CurrentManager attribute of the class
	shared_ptr<IStateManager> getManager() { return CurrentManager; }
};

