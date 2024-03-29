#include "stdafx.h"
#include "MenuStateManager.h"
#include "CloseWindowCallback.h"
#include "PlayCallback.h"
#include "DeckCallback.h"

MenuStateManager::MenuStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager)
	:BaseStateManager(window, currentManager), 
	menuLayout(window)	
{
	shared_ptr<ButtonObject> b1 = make_shared<ButtonObject>("Play", 0, 0, 200, 50, make_shared<PlayCallback>(currentManager)); 
	shared_ptr<ButtonObject> b2 = make_shared<ButtonObject>("Gallery", 0, 0, 200, 50, make_shared<DeckCallback>(currentManager));
	shared_ptr<ButtonObject> b3 = make_shared<ButtonObject>("Quit", 0, 0, 200, 50, make_shared<CloseWindowCallback>(Window));
	b1->SetPadding(25);
	b2->SetPadding(25);
	b3->SetPadding(25);

	vector<shared_ptr<IGuiElement>> V;
	V.push_back(b1);
	V.push_back(b2);
	V.push_back(b3);
	menuLayout.ObtainVector(V);
}


MenuStateManager::~MenuStateManager()
{
}

void MenuStateManager::HandleEvent(const Event& evnt)
{
	switch (evnt.type)
	{
	case Event::Closed: 
		Window->close();
		break;
	}

	HandleMouseEvent(evnt);
}

void MenuStateManager::DrawWindowContents()
{
	menuLayout.Show();
}

void MenuStateManager::HandleMouseEvent(const Event& evnt)
{	
	menuLayout.HandleMouseEvent(evnt);
}