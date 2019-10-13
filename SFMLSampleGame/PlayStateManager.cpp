#include "stdafx.h"
#include "PlayStateManager.h"
#include "MenuCallback.h"
#include "CloseWindowCallback.h"
#include "DeckCallback.h"

PlayStateManager::PlayStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager)
	:BaseStateManager(window, currentManager),
	playLayout(window)
{
	shared_ptr<ButtonObject> b1 = make_shared<ButtonObject>("Play", 0, 0, 200, 50, make_shared<MenuCallback>(currentManager)); // taki nowy konstruktor
	shared_ptr<ButtonObject> b2 = make_shared<ButtonObject>("Deck", 0, 0, 200, 50, make_shared<DeckCallback>(currentManager));
	shared_ptr<ButtonObject> b3 = make_shared<ButtonObject>("Quit", 0, 0, 200, 50, make_shared<CloseWindowCallback>(Window));
	b1->SetPadding(25);
	b2->SetPadding(25);
	b3->SetPadding(25);

	vector<shared_ptr<IGuiElement>> V;
	V.push_back(b1);
	V.push_back(b2);
	V.push_back(b3);
	playLayout.ObtainVector(V);

	map<string, shared_ptr<ButtonObject>> M;
	M["Play"] = b1;
	M["Deck"] = b2;
	M["Quit"] = b3;
	playLayout.ObtainButtonsMap(M);
}


PlayStateManager::~PlayStateManager()
{
}

void PlayStateManager::HandleEvent(const Event& evnt)
{
	switch (evnt.type)
	{
	case Event::Closed: //je�li zamknij x to zamknij okno
		Window->close();
		break;
	case Event::KeyReleased:
		switch (evnt.key.code)
		{

		case Keyboard::Return:
			break;
		}
		break;
		
	}

	HandleMouseEvent(evnt);
}

void PlayStateManager::DrawWindowContents()
{

	
	playLayout.Show();

}

void PlayStateManager::HandleMouseEvent(const Event& evnt)
{
	if (evnt.mouseButton.button == sf::Mouse::Right)
	{
		cout << "the right button was pressed" << endl;
		cout << "mouse x: " << evnt.mouseButton.x << endl;
		cout << "mouse y: " << evnt.mouseButton.y << endl;
	}


	if (evnt.mouseButton.button == sf::Mouse::Left)
	{
		
	}

	playLayout.HandleMouseEvent(evnt);
}