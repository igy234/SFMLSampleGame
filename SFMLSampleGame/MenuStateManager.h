#pragma once
#include "BaseStateManager.h"
#include "MenuLayout.h"


//manages Layout and creating guielements passed to menu layout
//This class also manages events such as window close
///Class managing the Menu state of the program
class MenuStateManager : public BaseStateManager
{
protected:
	///Menu Layout object managing the layout in this state
	MenuLayout menuLayout;
public:
	///@brief constructor creatiing buttons with appropriate callbacks and assigning them to vector of gui elements
	///@param "window" representing program's window
	///@param "currentManager" representing state of the program
	MenuStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager); 
	~MenuStateManager();

	///@brief handling all types of events in this state
	///@param "evnt" parameter describing event type for event handling
	void HandleEvent(const Event& evnt) override; 

	///@brief calling Menu Layout to draw contents to window
	void DrawWindowContents() override; 

	///@brief method calling layout to handle its mouse events
	///@param "evnt" parameter describing event type for mouse handling
	void HandleMouseEvent(const Event& evnt) override; 
};

