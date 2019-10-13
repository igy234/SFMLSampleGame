#include "stdafx.h"
#include "Game.h"
#include "StateOperator.h"

Game::Game()
	: StateHandler(make_shared<StateOperator>())
	, Window(make_shared<RenderWindow>(VideoMode(WindowSizeX, WindowSizeY), "Game development in progress...", Style::Titlebar | Style::Close)) //lista inicjalizacyjna "doklejenie konstruktora"
	, MenuManager(make_shared<MenuStateManager>(Window, StateHandler))
	, DeckManager(make_shared<DeckStateManager>(Window, StateHandler))
	, PlayManager(make_shared<PlayStateManager>(Window, StateHandler))
	
	
{
	StateSwitch();
}


Game::~Game()
{
}

void Game::Run()
{
	while (Window->isOpen())
	{
		Event evnt;
		while (Window->pollEvent(evnt))
		{
			CurrentManager->HandleEvent(evnt);
			
		}
		Window->clear();
		CurrentManager->DrawWindowContents();
		Window->display();
		StateSwitch();
	}
}

void Game::StateSwitch()
{
	switch (StateHandler->GetCurrentState())
	{
	case GameState::Menu:
		CurrentManager = MenuManager;
		break;
	case GameState::Deck:
		CurrentManager = DeckManager;
		break;
	case GameState::Play:
		CurrentManager = PlayManager;
		break;
	}
}