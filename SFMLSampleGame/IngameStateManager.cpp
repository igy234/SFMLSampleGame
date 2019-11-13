#include "stdafx.h"
#include "InGameStateManager.h"
#include "RowMaker.h"
#include "ColumnMaker.h"


IngameStateManager::IngameStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout, shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards)
	:BaseStateManager(window, currentManager),
	UserHandCards(userHandCards),
	Layout(playLayout),
	LowerUserBattleField(make_shared<vector<shared_ptr<IGuiElement>>>()),
	UpperUserBattleField(make_shared<vector<shared_ptr<IGuiElement>>>())
{

	UserPointsRec = make_shared<RectangleObject>(0, 0, 150, 100, Color(255, 0, 0, 50), "99");
	EnemyPointsRec = make_shared<RectangleObject>(0, 0, 150, 100, Color(255, 0, 0, 50), "88");
	UserPointsRec->SetPadding(290);
	EnemyPointsRec->SetPadding(0);
	UserPointsRec->setOutlineThickness(2);
	EnemyPointsRec->setOutlineThickness(2);
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

void IngameStateManager::WhichBattlefield(BattleField battlfield)
{
	if (CurrentSelectedCard!=nullptr)
	{
		auto it = find(UserHandCards->begin(), UserHandCards->end(), CurrentSelectedCard);
		UserHandCards->erase(it);

		switch (battlfield)
		{
		case BattleField::Lower:
			LowerUserBattleField->push_back(CurrentSelectedCard);

			break;
		case BattleField::Upper:
			UpperUserBattleField->push_back(CurrentSelectedCard);
			break;
		}
		OrganizeCards();
	}
}

void IngameStateManager::OrganizeCards()
{
	int UserSumOfPoints = 0;
	int EnemySumOfPoints = 0;
	for (auto element : *LowerUserBattleField)
	{
		auto card = static_pointer_cast<BaseCard>(element);
		UserSumOfPoints += card->GetModel()->GetStrength();
	}

	for (auto element : *UpperUserBattleField)
	{
		auto card = static_pointer_cast<BaseCard>(element);
		UserSumOfPoints += card->GetModel()->GetStrength();
	}

	UserPointsRec->SetText(to_string(UserSumOfPoints));
	EnemyPointsRec->SetText("@@");

	RowMaker rowMakerLowerUserBattleField(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldTwo, EnumScreenFields::FieldSeven);
	rowMakerLowerUserBattleField.SetStarterWidthPadding(10);
	rowMakerLowerUserBattleField.SetStarterHeightPadding(4);
	rowMakerLowerUserBattleField.OrganizePosition(*LowerUserBattleField);
	
	RowMaker rowMakerUpperUserBattleField(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldTwo, EnumScreenFields::FieldFive);
	rowMakerUpperUserBattleField.SetStarterWidthPadding(10);
	rowMakerUpperUserBattleField.SetStarterHeightPadding(4);
	rowMakerUpperUserBattleField.OrganizePosition(*UpperUserBattleField);

	auto vect = *UpperUserBattleField;
	vect.insert(vect.end(), LowerUserBattleField->begin(), LowerUserBattleField->end());
	vect.push_back(UserPointsRec);
	vect.push_back(EnemyPointsRec);
	ColumnMaker columnMakerSumOfPoints(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldOne, EnumScreenFields::FieldThree);
	columnMakerSumOfPoints.OrganizePosition({ EnemyPointsRec, UserPointsRec });
	Layout->SetGuiElementsForCurrentState(vect);
}
