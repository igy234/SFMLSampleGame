// SFMLWithKrisu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" // najlepiej żeby było na początku
#include "Game.h"


int main()
{


	Game game;
	game.Run();
	//int WindowSizeX = 1280; 
	//int WindowSizeY = 720;

	//Ball ball(WindowSizeX / 2, WindowSizeY / 2);
	//Button buttonPlay("Play", WindowSizeX / 2, (WindowSizeY / ScreenProportion) * OrderOfButtons); // z tym to jeszcze nie koniec zabawy trzeba bedzie wymyślić to lepiej
	//Button buttonDeck("Deck", WindowSizeX / 2, (WindowSizeY / ScreenProportion) * (OrderOfButtons - 10));
	//Button buttonExit("Quit", WindowSizeX / 2, (WindowSizeY / ScreenProportion) * (OrderOfButtons - 20));
	//
	//RenderWindow window(VideoMode(WindowSizeX, WindowSizeY), "Game development in progress...", Style::Titlebar | Style::Close);
	//Menu menu(WindowSizeX / 2, window.getSize().y);
	//

	//while (window.isOpen())
	//{
	//	Vector2i MousePosition = Mouse::getPosition(window);
	//	Event evnt;
	//	while (window.pollEvent(evnt))
	//	{
	//		switch (evnt.type)
	//		{
	//		case Event::Closed: //jeśli zamknij x to zamknij okno
	//				window.close();
	//				break;
	//		case Event::MouseButtonPressed:
	//		
	//			if (evnt.mouseButton.button == sf::Mouse::Right)
	//			{
	//				cout << "the right button was pressed" << endl;
	//				cout << "mouse x: " << evnt.mouseButton.x << endl;
	//				cout << "mouse y: " << evnt.mouseButton.y << endl;

	//			}
	//			if (evnt.mouseButton.button == sf::Mouse::Left)
	//			{
	//				switch (menu.MouseClickedInRange(MousePosition.x, MousePosition.y))
	//				{
	//				case 0:
	//					window.close();
	//					break;
	//				case 1:
	//					cout << "deck clicked" << endl;
	//					// tutaj pętla dla decku

	//					break;
	//				case 2:
	//					cout << "play clicked" << endl;
	//					//tutaj pętla dla gry

	//					break;
	//				}
	//			}
	//			break;
	//		case Event::KeyReleased:
	//			switch (evnt.key.code)
	//			{
	//			case Keyboard::Up:
	//				menu.MoveUp();
	//				break;
	//			case Keyboard::Down:
	//				menu.MoveDown();
	//				break;
	//			case Keyboard::Return: 
	//				switch (menu.GetPressedItem())
	//				{
	//				case 0:
	//					window.close();
	//					break;
	//				case 1:
	//					cout << "Deck button pressed" << endl;
	//					// tutaj pętla dla decku
	//					break;
	//				case 2:
	//					cout << "Play button pressed" << endl;
	//					//tutaj pętla dla gry
	//					break;
	//				}
	//				break;
	//			}
	//			break;
	//		case Event::TextEntered: // text input od gracza 
	//			if (evnt.text.unicode < 128)
	//			{
	//				printf("%c", evnt.text.unicode);
	//			}
	//			break;
	//		}
	//	}

	//	window.clear(); 
	//	
	//	menu.HighlightControl(MousePosition.x, MousePosition.y);
	//	if (menu.HighlightCtrl == false)
	//	{
	//		menu.HighlightButton(MousePosition.x, MousePosition.y);
	//	}
	//	menu.drawBackground(window); 
	//	window.draw(buttonPlay);
	//	window.draw(buttonDeck);
	//	window.draw(buttonExit);
	//	menu.drawTexts(window);
	//	ball.update(WindowSizeX, WindowSizeY);
	//	window.draw(ball);
	//	window.display();
	//	
	//}

	return 0;
}