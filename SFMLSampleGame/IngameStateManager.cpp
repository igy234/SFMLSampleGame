#include "stdafx.h"
#include "InGameStateManager.h"
#include "RowMaker.h"
#include "ColumnMaker.h"
#include "Opponent.h"
#include "Utils.h"
#include "GenerateCards.h"
#include "CardFactory.h"
#include <thread>
#include <mutex>
#include "ShuffleCallback.h"

IngameStateManager::IngameStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager,
	shared_ptr<PlayLayout> playLayout, shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards,
	shared_ptr<vector<shared_ptr<IGuiElement>>> enemyHandCards, function<void(MatchState)> callbackFunction, shared_ptr<RectangleObject> roundsRectangle)
	:BaseStateManager(window, currentManager),
	UserHandCards(userHandCards),
	EnemyHandCards(enemyHandCards),
	Layout(playLayout),
	LowerUserBattleField(make_shared<vector<shared_ptr<IGuiElement>>>()),
	UpperUserBattleField(make_shared<vector<shared_ptr<IGuiElement>>>()),
	LowerEnemyBattleField(make_shared<vector<shared_ptr<IGuiElement>>>()),
	UpperEnemyBattleField(make_shared<vector<shared_ptr<IGuiElement>>>()),
	shuffleCallback(callbackFunction),
	RoundsRectangle(roundsRectangle)
{

	UserPointsRec = make_shared<RectangleObject>(0, 0, 100, 70, Color(255, 0, 0, 50), "99");
	EnemyPointsRec = make_shared<RectangleObject>(0, 0, 100, 70, Color(255, 0, 0, 50), "88");
	UserPointsRec->SetPadding(320);
	EnemyPointsRec->SetPadding(0);
	UserPointsRec->setOutlineThickness(2);
	EnemyPointsRec->setOutlineThickness(2);

	

	TurnDisplayer = make_shared<RectangleObject>(0, 0, 230, 60, Color(255, 0, 0, 50), "shuffling");
	TurnDisplayer->SetPadding(10);
	TurnDisplayer->setOutlineThickness(2);

	opponent = make_shared<Opponent>(EnemyHandCards, LowerUserBattleField, UpperUserBattleField, LowerEnemyBattleField, UpperEnemyBattleField);
	IsPlayerTurn = static_cast<bool>(getRand(1));
	if (!IsPlayerTurn)
	{
		opponent->MakeMove();
		IsPlayerTurn = true;
		//TurnDisplayer->SetText("Enemy turn");
	}
	
	EnemyCardsCounter = make_shared<RectangleObject>(0, 0, 260, 60, Color(255, 0, 0, 50), "Enemy has " + to_string(opponent->GetNumberOfCards()) + " cards");
	EnemyCardsCounter->SetPadding(10);
	EnemyCardsCounter->setOutlineThickness(2);
}


IngameStateManager::~IngameStateManager()
{
}

void IngameStateManager::DrawWindowContents()
{

	Layout->Show();
}

void IngameStateManager::HandleMouseEvent(const Event& evnt)
{
	Layout->HandleMouseEvent(evnt);
}


void IngameStateManager::HandleEvent(const Event& evnt)
{

}

void IngameStateManager::PerformCardOperation(shared_ptr<IGuiElement> card, Mouse::Button click)
{
	if (click == Mouse::Button::Left)
	{
		CurrentSelectedCard = card;
		//cout << CurrentSelectedCard << endl;
	}
}

void IngameStateManager::WhichBattlefield(BattleField battlefield)
{
	if (CurrentSelectedCard!=nullptr)
	{
		auto it = find(UserHandCards->begin(), UserHandCards->end(), CurrentSelectedCard);
		//if(it != UserHandCards->end())
			UserHandCards->erase(it);

		bool end = PlayCard(battlefield);

		//if (!end)
			//OrganizeCards();
	}
}

void IngameStateManager::OrganizeCards()
{
	UserSumOfPoints = 0;
	EnemySumOfPoints = 0;
	UserSumOfPoints += CalculateSumOfPoints(LowerUserBattleField);
	UserSumOfPoints += CalculateSumOfPoints(UpperUserBattleField);
	EnemySumOfPoints += CalculateSumOfPoints(LowerEnemyBattleField);
	EnemySumOfPoints += CalculateSumOfPoints(UpperEnemyBattleField);

	UserPointsRec->SetText(to_string(UserSumOfPoints));
	EnemyPointsRec->SetText(to_string(EnemySumOfPoints));
	if (IsPlayerTurn) 
		TurnDisplayer->SetText("your turn");
	else
		TurnDisplayer->SetText("Enemy turn");

	EnemyCardsCounter->SetText("Enemy has " + to_string(opponent->GetNumberOfCards()) + " cards");
	

	ArrangeCards(LowerUserBattleField, EnumScreenFields::FieldTwo, EnumScreenFields::FieldSeven);
	ArrangeCards(UpperUserBattleField, EnumScreenFields::FieldTwo, EnumScreenFields::FieldFive);
	ArrangeCards(LowerEnemyBattleField, EnumScreenFields::FieldTwo, EnumScreenFields::FieldThree);
	ArrangeCards(UpperEnemyBattleField, EnumScreenFields::FieldTwo, EnumScreenFields::FieldOne);
	
	auto vect = *UpperUserBattleField;
	vect.insert(vect.end(), LowerUserBattleField->begin(), LowerUserBattleField->end());
	vect.push_back(UserPointsRec);
	vect.push_back(EnemyPointsRec);
	vect.push_back(EnemyCardsCounter);
	vect.push_back(TurnDisplayer);

	vect.insert(vect.end(), LowerEnemyBattleField->begin(), LowerEnemyBattleField->end());
	vect.insert(vect.end(), UpperEnemyBattleField->begin(), UpperEnemyBattleField->end());

	ColumnMaker columnMakerSumOfPoints(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldOne, EnumScreenFields::FieldThree);
	columnMakerSumOfPoints.OrganizePosition({ EnemyPointsRec, UserPointsRec });
	Layout->SetGuiElementsForCurrentState(vect);

	ColumnMaker columnMakerTurnAndCards(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldTen, EnumScreenFields::FieldOne);
	columnMakerTurnAndCards.SetStarterHeightPadding(30);
	columnMakerTurnAndCards.OrganizePosition({TurnDisplayer, EnemyCardsCounter });
}

void IngameStateManager::initialize()
{
	CurrentSelectedCard = nullptr;
	OrganizeCards();
}

void IngameStateManager::ResetRoundsScore()
{
	RoundsLost = 0;
	RoundsWon = 0;
}

void IngameStateManager::UpdateRoundsRectangleText()
{
	RoundsRectangle->SetText("Won rounds: " + to_string(RoundsWon) + " Lost Rounds: " + to_string(RoundsLost) + " Win Ratio: " + to_string(RoundsWon) + "/" + to_string(RoundsLost + RoundsWon));
}

bool IngameStateManager::PlayCard(BattleField battlefield)
{
	
	auto card = static_pointer_cast<BaseCard>(CurrentSelectedCard);
	card->GetModel()->CardSpecialAbility(CurrentSelectedCard, battlefield, UserHandCards, LowerUserBattleField, UpperUserBattleField, LowerEnemyBattleField, UpperEnemyBattleField);

	opponent->MakeMove();
	if (EnemyHandCards->size() && !UserHandCards->size())
	{
		while (EnemyHandCards->size())
		{
			opponent->MakeMove();
		}
	}

	OrganizeCards();

	if (!opponent->GetNumberOfCards() && !UserHandCards->size())
	{
		//shuffleCallback(MatchState::Shuffle);
		if (UserSumOfPoints > EnemySumOfPoints)
			RoundsWon++;
		else if(UserSumOfPoints == EnemySumOfPoints)
		{
			RoundsLost++;
			RoundsWon++;
		}
		else
			RoundsLost++;

		UpdateRoundsRectangleText();

		if (RoundsLost + RoundsWon >= 3)
		{
			auto finishRound = [this]()
			{
				InitNewRound();
				ResetRoundsScore();
				UpdateRoundsRectangleText();
				shuffleCallback(MatchState::Shuffle);
			};

			shared_ptr<ButtonObject> NextRoundButton = make_shared<ButtonObject>("Restart Game", 800, 500, 220, 50, make_shared<ShuffleCallback>(finishRound), 200);
			NextRoundButton->SetSpecialBackgroundColor(Color(80, 33, 40));
			Layout->AddGuiElementToCurrentState(NextRoundButton);
			// runda ++
		}
		else
		{
			auto finishRound = [this]()
			{
				InitNewRound();
				shuffleCallback(MatchState::Shuffle);
			};

			shared_ptr<ButtonObject> NextRoundButton = make_shared<ButtonObject>("Next Round", 800, 500, 200, 50, make_shared<ShuffleCallback>(finishRound), 200);
			NextRoundButton->SetSpecialBackgroundColor(Color(80, 33, 40));
			Layout->AddGuiElementToCurrentState(NextRoundButton);
			// runda ++
		}
			
		return true;
	}

	return false;
}

int IngameStateManager::CalculateSumOfPoints(shared_ptr<vector<shared_ptr<IGuiElement>>> currentBattleField)
{
	int SumOfPoints = 0;
	for (auto element : *currentBattleField)
	{
		auto card = static_pointer_cast<BaseCard>(element);
		SumOfPoints += card->GetModel()->GetStrength();
	}
	return SumOfPoints;
}

void IngameStateManager::ArrangeCards(shared_ptr<vector<shared_ptr<IGuiElement>>> currentBattleField, EnumScreenFields fieldX, EnumScreenFields fieldY)
{
	RowMaker rowMakerLowerUserBattleField(Window->getSize().x, Window->getSize().y, fieldX, fieldY);
	rowMakerLowerUserBattleField.SetStarterWidthPadding(10);
	rowMakerLowerUserBattleField.SetStarterHeightPadding(4);
	rowMakerLowerUserBattleField.OrganizePosition(*currentBattleField);
}

void IngameStateManager::InitNewRound() //with multithreads
{
	//clearing decks
	LowerUserBattleField->clear();
	UpperUserBattleField->clear();
	LowerEnemyBattleField->clear();
	UpperEnemyBattleField->clear();

	GenerateCards generate;
	CardFactory factory;

	mutex mtx;
	vector<thread> threadspoll;
	for (int i = 0; i < 7; ++i)
	{
		threadspoll.push_back(thread(
			[&]()
		{
			auto card = factory.CreateCard(generate.GenerateRandomCardNameEnum());
			card->SetPadding(10);
			lock_guard<mutex> guard(mtx);
			UserHandCards->push_back(card);
		})
		);
	}

	for (int i = 0; i < 7; ++i)
	{
		threadspoll.push_back(thread(
			[&]()
		{
			auto card = factory.CreateCard(generate.GenerateRandomCardNameEnum());
			card->SetPadding(10);
			lock_guard<mutex> guard(mtx);
			EnemyHandCards->push_back(card);
		})
		);
	}

	for (int i=0; i < threadspoll.size(); i++)
	{
		threadspoll[i].join();
	}

	RowMaker rowMakerUserHandCards(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldTwo, EnumScreenFields::FieldNine);
	rowMakerUserHandCards.SetStarterWidthPadding(10);
	rowMakerUserHandCards.SetStarterHeightPadding(4);
	rowMakerUserHandCards.OrganizePosition(*UserHandCards);
}