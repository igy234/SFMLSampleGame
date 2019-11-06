#pragma once
#include "stdafx.h" 
#include "MenuStateManager.h"
#include "FontProvider.h"
#include "PlayStateManager.h"
#include "IStateOperator.h"
#include "DeckStateManager.h"

//main class of the program, handling gamestates, holding window size parameters 
class Game
{
private:
	shared_ptr<IStateOperator<GameState>> StateHandler;
	int WindowSizeX = 1920;
	int WindowSizeY = 1080;
	shared_ptr<RenderWindow> Window; 
	shared_ptr<MenuStateManager> MenuManager;
	shared_ptr<DeckStateManager> DeckManager;
	shared_ptr<PlayStateManager> PlayManager;
	shared_ptr<IStateManager> CurrentManager;
	void StateSwitch(); // method switching current manager to appropriate one

public:
	Game(); //initializing StateHandler, window,  and appropriate managers 
	~Game();
	void Run(); //handling events of Currentmanager, clearing, drawing and displaying window contents. StateSwitching.  

};

