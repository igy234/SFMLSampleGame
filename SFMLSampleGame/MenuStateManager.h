#pragma once
#include "BaseStateManager.h"
#include "MenuLayout.h"

//Class holding Menu Layout and creating guielements passed to menu layout
//This class also manages events such as window close
class MenuStateManager : public BaseStateManager
{
protected:
	MenuLayout menuLayout;
public:
	// creation of buttons with appropriate callbacks and assigning them to vector of gui elements and to map with named strings
	MenuStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager); 
	~MenuStateManager();
	void HandleEvent(const Event& evnt) override; //handling al; types of events 
	void DrawWindowContents() override; //drawing contents of menulayout
	void HandleMouseEvent(const Event& evnt) override; //handling menulayout mouse events, and its own events.
};

