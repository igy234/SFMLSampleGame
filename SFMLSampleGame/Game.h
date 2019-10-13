#pragma once
#include "stdafx.h" // najlepiej ¿eby by³o na pocz¹tku
#include "MenuStateManager.h"
#include "FontProvider.h"
#include "PlayStateManager.h"
#include "IStateOperator.h"
#include "DeckStateManager.h"

class Game
{
private:
	shared_ptr<IStateOperator> StateHandler;
	int WindowSizeX = 1920;
	int WindowSizeY = 1080;
	shared_ptr<RenderWindow> Window; //shared ptr to klasa z auto managerowaniem pamiecia (new i delette)
	shared_ptr<MenuStateManager> MenuManager;
	shared_ptr<DeckStateManager> DeckManager;
	shared_ptr<PlayStateManager> PlayManager;
	shared_ptr<IStateManager> CurrentManager;
	void StateSwitch();

public:
	Game();
	~Game();
	void Run();

};

