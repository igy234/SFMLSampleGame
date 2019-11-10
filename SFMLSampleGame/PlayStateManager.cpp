#include "stdafx.h"
#include "PlayStateManager.h"
#include "MenuCallback.h"
#include "CloseWindowCallback.h"
#include "DeckCallback.h"
#include "StateOperator.h"
#include "GenerateCards.h"
#include "CardFactory.h"

PlayStateManager::PlayStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager)
	:BaseStateManager(window, currentManager),
	StateHandler(make_shared<StateOperator<MatchState>>())
{

	shared_ptr<ButtonObject> b1 = make_shared<ButtonObject>("Menu", 0, 0, 200, 50, make_shared<MenuCallback>(currentManager));
	shared_ptr<ButtonObject> b2 = make_shared<ButtonObject>("Pass", 0, 0, 200, 50, make_shared<MenuCallback>(currentManager));
	shared_ptr<ButtonObject> b3 = make_shared<ButtonObject>("End Exchange", 0, 0, 250, 50, make_shared<MenuCallback>(currentManager));

	GenerateCards generate;
	CardFactory factory;
	for (int i = 0; i < 7; ++i)
	{
		auto card = factory.CreateCard(generate.GenerateRandomCardNameEnum());
		UserHandCards.push_back(card);
		UserHandCards[i]->SetPadding(10);
	}


	b1->SetPadding(25);
	b2->SetPadding(25);
	b3->SetPadding(25);

	playLayout = make_shared<PlayLayout>(window, UserHandCards);
		
	ShuffleManager = make_shared<ShuffleStateManager>(Window, StateHandler, playLayout);
	IngameManager = make_shared<IngameStateManager>(Window, StateHandler, playLayout);
	EndgameManager = make_shared<EndgameStateManager>(Window, StateHandler, playLayout);

	vector<shared_ptr<IGuiElement>> V;
	V.push_back(b1);
	V.push_back(b2);
	V.push_back(b3);
	playLayout->ObtainVector(V);

	StateHandler->SetNewState(MatchState::Shuffle); //default state is menu
	StateSwitch();
}


PlayStateManager::~PlayStateManager()
{
}

void PlayStateManager::HandleEvent(const Event& evnt)
{
	switch (evnt.type)
	{
	case Event::Closed: //jeœli zamknij x to zamknij okno
		Window->close();
		break;
	}

	HandleMouseEvent(evnt);

}

void PlayStateManager::DrawWindowContents()
{
	//playLayout.Show();
	CurrentManager->DrawWindowContents();
}

void PlayStateManager::HandleMouseEvent(const Event& evnt)
{
	if (evnt.mouseButton.button == sf::Mouse::Right)
	{
		cout << "the right button was pressed" << endl;
		cout << "mouse x: " << evnt.mouseButton.x << endl;
		cout << "mouse y: " << evnt.mouseButton.y << endl;
	}
	
	//playLayout.HandleMouseEvent(evnt);
	CurrentManager->HandleMouseEvent(evnt);
}

void PlayStateManager::StateSwitch()
{
	switch (StateHandler->GetCurrentState())
	{
	case MatchState::Shuffle:
		CurrentManager = ShuffleManager;
		break;
	case MatchState::Ingame:
		CurrentManager = IngameManager;
		break;
	case MatchState::Endgame:
		CurrentManager = EndgameManager;
		break;
	}
}