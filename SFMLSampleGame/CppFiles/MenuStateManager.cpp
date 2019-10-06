#include "stdafx.h"
#include "MenuStateManager.h"



MenuStateManager::MenuStateManager(shared_ptr<RenderWindow> window)
	:BaseStateManager(window) //przekazujemy wspólny window z Game'a 
{
	if (!this->MenuTexture.loadFromFile("Resources/Images/menu1.jpg"))
	{
		cout << "Error while loading Menu Texture" << endl; //error handling
		system("pause");
	}

	MenuBackgorund.setTexture(MenuTexture);
}


MenuStateManager::~MenuStateManager()
{
}

void MenuStateManager::HandleEvent(const Event& evnt)
{
	switch (evnt.type)
	{
	case Event::Closed: //jeœli zamknij x to zamknij okno
		Window->close();
		break;
	//case Event::MouseButtonPressed:

	//	if (evnt.mouseButton.button == sf::Mouse::Right)
	//	{
	//		cout << "the right button was pressed" << endl;
	//		cout << "mouse x: " << evnt.mouseButton.x << endl;
	//		cout << "mouse y: " << evnt.mouseButton.y << endl;

	//	}
	//	if (evnt.mouseButton.button == sf::Mouse::Left)
	//	{
	//		switch (menu.MouseClickedInRange(MousePosition.x, MousePosition.y))
	//		{
	//		case 0:
	//			Window->close();
	//			break;
	//		case 1:
	//			cout << "deck clicked" << endl;
	//			// tutaj pêtla dla decku

	//			break;
	//		case 2:
	//			cout << "play clicked" << endl;
	//			//tutaj pêtla dla gry

	//			break;
	//		}
	//	}
	//	break;
	//case Event::KeyReleased:
	//	switch (evnt.key.code)
	//	{
	//	case Keyboard::Up:
	//		menu.MoveUp();
	//		break;
	//	case Keyboard::Down:
	//		menu.MoveDown();
	//		break;
	//	case Keyboard::Return:
	//		switch (menu.GetPressedItem())
	//		{
	//		case 0:
	//			window.close();
	//			break;
	//		case 1:
	//			cout << "Deck button pressed" << endl;
	//			// tutaj pêtla dla decku
	//			break;
	//		case 2:
	//			cout << "Play button pressed" << endl;
	//			//tutaj pêtla dla gry
	//			break;
	//		}
	//		break;
	//	}
	//	break;
	//case Event::TextEntered: // text input od gracza 
	//	if (evnt.text.unicode < 128)
	//	{
	//		printf("%c", evnt.text.unicode);
	//	}
	//	break;
	}
}

void MenuStateManager::DrawWindowContents()
{
	
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
	Window->draw(MenuBackgorund);
}