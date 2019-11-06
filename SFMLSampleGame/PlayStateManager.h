#pragma once
#include "BaseStateManager.h"
#include "PlayLayout.h"
#include "IStateOperator.h"
//Class managing the play state of the game
//holding PlayLayout object
class PlayStateManager :public BaseStateManager
{
private:
	PlayLayout playLayout;
public:
	void HandleEvent(const Event& evnt) override; //handling all types of events ie close window
	void DrawWindowContents() override; //drawing playLayout contents to the window
	void HandleMouseEvent(const Event& evnt) override; //handling playLayout mouse events

	// creation of buttons with appropriate callbacks and assigning them to vector of gui elements and to map with named strings
	PlayStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager);
	~PlayStateManager();
};

