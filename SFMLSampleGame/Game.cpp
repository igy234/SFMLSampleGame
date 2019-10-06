#include "stdafx.h"
#include "Game.h"


Game::Game()
	: Window(make_shared<RenderWindow>(VideoMode(WindowSizeX, WindowSizeY), "Game development in progress...", Style::Titlebar | Style::Close)), //lista inicjalizacyjna "doklejenie konstruktora"
	  MenuManager(Window)
{
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
			MenuManager.HandleEvent(evnt);
			
		}
		Window->clear();
		MenuManager.DrawWindowContents();
		Window->display();
	}
}