#include "stdafx.h"
#include "PlayStateManager.h"
#include "MenuCallback.h"
#include "CloseWindowCallback.h"
#include "DeckCallback.h"
#include "StateOperator.h"
#include "GenerateCards.h"
#include "CardFactory.h"
#include "IngameCallback.h"
#include "ColumnMaker.h"

PlayStateManager::PlayStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager)
	:BaseStateManager(window, currentManager),
	StateHandler(make_shared<StateOperator<MatchState>>()),
	UserHandCards(make_shared<vector<shared_ptr<IGuiElement>>>()),
	EnemyHandCards(make_shared<vector<shared_ptr<IGuiElement>>>())
{
	auto changeInternalState = [this](MatchState state) //callback func
	{
		StateHandler->SetNewState(state);
		StateSwitch();
		playLayout->SetGuiElementsForCurrentState(vector<shared_ptr<IGuiElement>>());
		this->getManager()->initialize();
	};

	auto ingameCallback = make_shared<IngameCallback>(changeInternalState);

	shared_ptr<ButtonObject> b1 = make_shared<ButtonObject>("Menu", 0, 0, 200, 50, make_shared<MenuCallback>(currentManager));
	b1->SetPadding(25);
	ColumnMaker columnMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldTen, EnumScreenFields::FieldNine);
	columnMaker.OrganizePosition({ b1 });

	RoundsRectangle = make_shared<RectangleObject>(0, 0, 750, 60, Color(255, 0, 0, 50), "Won rounds: 0 Lost Rounds: 0 Win Ratio: 0/0");
	RoundsRectangle->setOutlineThickness(2);
	ColumnMaker columnMakerRounds(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldFive, EnumScreenFields::FieldEleven);
	columnMakerRounds.SetStarterHeightPadding(30);
	columnMakerRounds.OrganizePosition({ RoundsRectangle });

	GenerateCards generate;
	CardFactory factory;
	for (int i = 0; i < 7; ++i)
	{
		auto card = factory.CreateCard(generate.GenerateRandomCardNameEnum());
		UserHandCards->push_back(card);
		(*UserHandCards)[i]->SetPadding(10);
	}

	for (int i = 0; i < 7; ++i)
	{
		auto card = factory.CreateCard(generate.GenerateRandomCardNameEnum());
		EnemyHandCards->push_back(card);
		(*EnemyHandCards)[i]->SetPadding(10);
	}

	playLayout = make_shared<PlayLayout>(window, UserHandCards, CurrentManager);
		
	ShuffleManager = make_shared<ShuffleStateManager>(Window, StateHandler, playLayout, UserHandCards, ingameCallback);
	IngameManager = make_shared<IngameStateManager>(Window, StateHandler, playLayout, UserHandCards, EnemyHandCards, changeInternalState, RoundsRectangle);
	EndgameManager = make_shared<EndgameStateManager>(Window, StateHandler, playLayout);

	vector<shared_ptr<IGuiElement>> V;
	V.push_back(b1);
	playLayout->ObtainVector(V);

	playLayout->GetDrawOnlyContents()->push_back(RoundsRectangle);

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


