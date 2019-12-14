#pragma once
#include "stdafx.h" 
#include "MenuStateManager.h"
#include "FontProvider.h"
#include "PlayStateManager.h"
#include "IStateOperator.h"
#include "DeckStateManager.h"

///Main class of the program, responsible for handling game states 
class Game
{
private:
	///shared pointer to IStateOperator holding and ascribing states of the program
	shared_ptr<IStateOperator<GameState>> StateHandler;

	///holding window width 
	int WindowSizeX = 1920;

	///holding window width
	int WindowSizeY = 1080;

	///Shared pointer to program's window
	shared_ptr<RenderWindow> Window; 

	///one of three main state managers of the game 
	shared_ptr<MenuStateManager> MenuManager;

	///one of three main state managers of the game 
	shared_ptr<DeckStateManager> DeckManager;

	///one of three main state managers of the game 
	shared_ptr<PlayStateManager> PlayManager;

	///attribute holding current state manager
	shared_ptr<IStateManager> CurrentManager;

	///@brief method switching current manager to appropriate one
	void StateSwitch(); 

public:
	///@brief constructor initializing StateHandler, window, music and appropriate managers 
	Game(); 
	~Game();
	///@brief method handling events of Currentmanager, clearing, drawing and displaying window contents. StateSwitching.  Management of game's music.
	void Run(); 

};

/*! \mainpage Cardogemu Fantasy technical documentation
 *
 * \section intro_sec Introduction
 *
 * This is the technical documantation to Cardogemu Fantasy game provided by Ignacy Grabski.
 */