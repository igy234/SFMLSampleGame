#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
#include "IStateOperator.h"
#include "IngameStateManager.h"
#include "ShuffleStateManager.h"
#include "EndgameStateManager.h"
//Class managing the play state of the game
//holding PlayLayout object
class PlayStateManager :public BaseStateManager
{
private:
	shared_ptr<PlayLayout> playLayout;
	shared_ptr<IStateOperator<MatchState>> StateHandler;
	shared_ptr<ShuffleStateManager> ShuffleManager;
	shared_ptr<IngameStateManager> IngameManager;
	shared_ptr<EndgameStateManager> EndgameManager;
	shared_ptr<IStateManager> CurrentManager;
	vector<shared_ptr<IGuiElement>> UserHandCards; //vector holding cards in user's hand
	vector<shared_ptr<IGuiElement>> EnemyHandCards; //vector holding cards in AI's hand
public:
	void StateSwitch();
	void HandleEvent(const Event& evnt) override; //handling all types of events ie close window
	void DrawWindowContents() override; //drawing playLayout contents to the window
	void HandleMouseEvent(const Event& evnt) override; //handling playLayout mouse events

	// creation of buttons with appropriate callbacks and assigning them to vector of gui elements and to map with named strings
	PlayStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager);
	~PlayStateManager();
};

