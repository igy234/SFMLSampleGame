#pragma once
#include "stdafx.h" // najlepiej ¿eby by³o na pocz¹tku
#include "MenuStateManager.h"
#include "FontProvider.h"
class Game
{
private:
	int WindowSizeX = 1280;
	int WindowSizeY = 720;
	shared_ptr<RenderWindow> Window; //shared ptr to klasa z auto managerowaniem pamiecia (new i delette)
	MenuStateManager MenuManager;

public:
	Game();
	~Game();
	void Run();

};

