#include "stdafx.h"
#include "MenuStateManager.h"
#include "CloseWindowCallback.h"
#include "PlayCallback.h"
#include "DeckCallback.h"

MenuStateManager::MenuStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager)
	:BaseStateManager(window, currentManager), 
	menuLayout(window)	
{
	shared_ptr<ButtonObject> b1 = make_shared<ButtonObject>("Play", 0, 0, 200, 50, make_shared<PlayCallback>(currentManager)); // taki nowy konstruktor
	shared_ptr<ButtonObject> b2 = make_shared<ButtonObject>("Deck", 0, 0, 200, 50, make_shared<DeckCallback>(currentManager));
	shared_ptr<ButtonObject> b3 = make_shared<ButtonObject>("Quit", 0, 0, 200, 50, make_shared<CloseWindowCallback>(Window));
	b1->SetPadding(25);
	b2->SetPadding(25);
	b3->SetPadding(25);

	vector<shared_ptr<IGuiElement>> V;
	V.push_back(b1);
	V.push_back(b2);
	V.push_back(b3);
	menuLayout.ObtainVector(V);
	
	map<string, shared_ptr<ButtonObject>> M;
	M["Play"] = b1;
	M["Deck"] = b2;
	M["Quit"] = b3;
	menuLayout.ObtainButtonsMap(M);
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
	case Event::KeyReleased:
		switch (evnt.key.code)
		{

		case Keyboard::Return:
			break;
		}
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

	HandleMouseEvent(evnt);
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
	menuLayout.Show();
	
}

void MenuStateManager::HandleMouseEvent(const Event& evnt)
{
	if (evnt.mouseButton.button == sf::Mouse::Right)
	{
				cout << "the right button was pressed" << endl;
				cout << "mouse x: " << evnt.mouseButton.x << endl;
				cout << "mouse y: " << evnt.mouseButton.y << endl;
	}
	
	
	if (evnt.mouseButton.button == sf::Mouse::Left)
	{
		//switch (menu.MouseClickedInRange(MousePosition.x, MousePosition.y))
		//{
		//case 0:
		//	Window->close();
		//	break;
		//case 1:
		//	cout << "deck clicked" << endl;
		//	// tutaj pêtla dla decku

		//	break;
		//case 2:
		//	cout << "play clicked" << endl;
		//	//tutaj pêtla dla gry

		//	break;
		//}
	}

	menuLayout.HandleMouseEvent(evnt);
}