#include "stdafx.h"
#include "Game.h"
#include "StateOperator.h"
#include "MusicProvider.h"

Game::Game()
	: StateHandler(make_shared<StateOperator<GameState>>())
	, Window(make_shared<RenderWindow>(VideoMode(WindowSizeX, WindowSizeY), "Cardogemu Fantasy", Style::Titlebar | Style::Close | Style::Fullscreen)) 
	, MenuManager(make_shared<MenuStateManager>(Window, StateHandler))
	, DeckManager(make_shared<DeckStateManager>(Window, StateHandler))
	, PlayManager(make_shared<PlayStateManager>(Window, StateHandler))
{
	Window->setVerticalSyncEnabled(true); //frame limit set to refresh rate of the monitor
	//Window->setFramerateLimit(80);
	StateHandler->SetNewState(GameState::Menu); //default state is menu
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
		MusicProvider::instance().CheckMusicStatus();
	}
}

void Game::StateSwitch()
{
	auto CurrentState = StateHandler->GetCurrentState();
	switch (CurrentState)
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
	MusicProvider::instance().play(CurrentState);
}