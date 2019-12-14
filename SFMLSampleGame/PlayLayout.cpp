#include "stdafx.h"
#include "PlayLayout.h"
#include "ColumnMaker.h"
#include "RowMaker.h"
#include "RectangleObject.h"
#include "Utils.h"
#include "BaseCard.h"
#include "CardFactory.h"
#include "ICardOperator.h"
#include "Opponent.h"
#include "IngameStateManager.h"

PlayLayout::PlayLayout(shared_ptr<RenderWindow> window, shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards, shared_ptr<IStateManager>& currentManager) //vector holding cards in user's hand)
	:BaseLayout(window),	
	CardPreview(0,0,0,0),
	UserHandCards(userHandCards),
	CurrentManager(currentManager),
	DrawOnlyVector(make_shared<vector<shared_ptr<IGuiElement>>>())
{

	int FieldX, FieldY, WidthFactor, HeightFactor, WindowSizeX, WindowSizeY;
	WindowSizeX = Window->getSize().x;
	WindowSizeY = Window->getSize().y;

	if (!this->BackgroundTexture.loadFromFile("Resources/Images/rain.png"))
	{
		cerr << "Error while loading Menu Texture" << endl; //error handling
		system("pause");
	}

	BackgroundSprite.setTexture(BackgroundTexture);

	RectangleObject BackDrop(0, 0, Window->getSize().x, Window->getSize().y);
	BackDrop.setOrigin(0, 0);
	BackDrop.setFillColor(Color(0, 0, 0, 175));
	BackDrop.setOutlineThickness(Thickness);
	UiLines.push_back(BackDrop);
	
	RowMaker rowMakerUserHandCards(window->getSize().x, window->getSize().y, EnumScreenFields::FieldTwo, EnumScreenFields::FieldNine);
	rowMakerUserHandCards.SetStarterWidthPadding(10);
	rowMakerUserHandCards.SetStarterHeightPadding(4);
	rowMakerUserHandCards.OrganizePosition(*UserHandCards);

	//region UiLines
	#pragma region GridLayout
	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldOne, EnumScreenFields::FieldOne);
	RectangleObject ScoreRectangle;
	ScoreRectangle.setPosition(0,0);
	ScoreRectangle.setOutlineThickness(Thickness);
	ScoreRectangle.SetWidth(FieldX + WidthFactor);
	ScoreRectangle.SetHeight(WindowSizeY);
	UiLines.push_back(ScoreRectangle);

	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldTwo, EnumScreenFields::FieldNine);
	RectangleObject HandRectangle;
	HandRectangle.setPosition(FieldX+ThicknessShift, FieldY - ThicknessShift);
	HandRectangle.setOutlineThickness(Thickness);
	HandRectangle.SetWidth(FieldX + WidthFactor * (static_cast<int>(EnumScreenFields::FieldSix) + 1));
	HandRectangle.SetHeight(10+HeightFactor*(static_cast<int>(EnumScreenFields::FieldThree) + 1) - ThicknessShift);
	UiLines.push_back(HandRectangle);

	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldTwo, EnumScreenFields::FieldSeven);
	RectangleObject LowerPlayerRectangle;
	LowerPlayerRectangle.setPosition(FieldX + ThicknessShift, FieldY - ThicknessShift);
	LowerPlayerRectangle.setOutlineThickness(Thickness);
	LowerPlayerRectangle.SetWidth(FieldX + WidthFactor * (static_cast<int>(EnumScreenFields::FieldSix) + 1));
	LowerPlayerRectangle.SetHeight(HeightFactor*(static_cast<int>(EnumScreenFields::FieldTwo) + 1) - ThicknessShift);
	UiLines.push_back(LowerPlayerRectangle);

	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldTwo, EnumScreenFields::FieldFive);
	RectangleObject UpperPlayerRectangle;
	UpperPlayerRectangle.setPosition(FieldX + ThicknessShift, FieldY);
	UpperPlayerRectangle.setOutlineThickness(Thickness);
	UpperPlayerRectangle.SetWidth(FieldX + WidthFactor * (static_cast<int>(EnumScreenFields::FieldSix) + 1));
	UpperPlayerRectangle.SetHeight(HeightFactor*(static_cast<int>(EnumScreenFields::FieldTwo) + 1) - ThicknessShift * ThicknessShift);
	UiLines.push_back(UpperPlayerRectangle);

	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldTwo, EnumScreenFields::FieldThree);
	RectangleObject LowerOponentRectangle;
	LowerOponentRectangle.setPosition(FieldX + ThicknessShift, FieldY - ThicknessShift);
	LowerOponentRectangle.setOutlineThickness(Thickness);
	LowerOponentRectangle.SetWidth(FieldX + WidthFactor * (static_cast<int>(EnumScreenFields::FieldSix) + 1));
	LowerOponentRectangle.SetHeight(HeightFactor*(static_cast<int>(EnumScreenFields::FieldTwo) + 1) - ThicknessShift);
	UiLines.push_back(LowerOponentRectangle);

	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldTwo, EnumScreenFields::FieldOne);
	RectangleObject UpperOponentRectangle;
	UpperOponentRectangle.setPosition(FieldX + ThicknessShift, FieldY - ThicknessShift);
	UpperOponentRectangle.setOutlineThickness(Thickness);
	UpperOponentRectangle.SetWidth(FieldX + WidthFactor * (static_cast<int>(EnumScreenFields::FieldSix) + 1));
	UpperOponentRectangle.SetHeight(HeightFactor*(static_cast<int>(EnumScreenFields::FieldTwo) + 1) - ThicknessShift);
	UiLines.push_back(UpperOponentRectangle);
	#pragma endregion GridLayout 
	
	//starting x, starting y, width and heightfor given field of net
	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldNine, EnumScreenFields::FieldThree);
	CardPreview.SetPositionX(FieldX + PreviewPadding);
	CardPreview.SetPositionY(FieldY);
}

PlayLayout::~PlayLayout()
{
}

void PlayLayout::Show()
{
	Window->draw(BackgroundSprite);
	for (auto element : UiLines)
	{
		element.Draw(Window);
	}
	
	for (auto element : GuiElements)
	{
		element->Draw(Window);
	}

	for (auto element : *UserHandCards)
	{
		element->Draw(Window);
	}
	
	for (auto element : GuiElemtnsForCurrentState)
	{
		element->Draw(Window);
	}
	
	for (auto element : *DrawOnlyVector)
	{
		element->Draw(Window);
	}
	
	CardPreview.Draw(Window);

}

void PlayLayout::ObtainVector(vector<shared_ptr<IGuiElement>> V)
{
	BaseLayout::ObtainVector(V); //saved for later (eventually)
}

shared_ptr<vector<shared_ptr<IGuiElement>>> PlayLayout::GetDrawOnlyContents()
{
	return DrawOnlyVector;
}

void PlayLayout::HandleMouseEvent(const Event& evnt)
{
	BaseLayout::HandleMouseEvent(evnt);
	switch (evnt.type)
	{
	case Event::MouseButtonPressed:
		if (evnt.mouseButton.button == sf::Mouse::Left)
		{
			bool WasCardHighlighted = false;
			float GuiElementWidth, GuiElementHeight, GuiElementPositionX, GuiElementPositionY;
			for (auto element : *UserHandCards)
			{
				GuiElementPositionX = element->GetPositionX();
				GuiElementPositionY = element->GetPositionY();
				GuiElementWidth = element->GetWidth();
				GuiElementHeight = element->GetHeight();
				if ((evnt.mouseButton.x >= GuiElementPositionX && evnt.mouseButton.x < (GuiElementPositionX + GuiElementWidth)) && // quick maths
					(evnt.mouseButton.y >= GuiElementPositionY && evnt.mouseButton.y <= (GuiElementPositionY + GuiElementHeight)))
				{
					CardPreview.SetTexture(element->GetTexture());
					element->Highlight();
					WasCardHighlighted = true;
					if (auto cardOperator = dynamic_pointer_cast<ICardOperator>(CurrentManager))
					{
						cardOperator->PerformCardOperation(element, evnt.mouseButton.button);
					}
				}
				else
				{
					element->Unhighlight();
				}
			}


			vector<shared_ptr<IGuiElement>> vectAllBattlefields = *UserLowerBattlefieldCards;
			vectAllBattlefields.insert(vectAllBattlefields.begin(), UserUpperBattlefieldCards->begin(), UserUpperBattlefieldCards->end());
			vectAllBattlefields.insert(vectAllBattlefields.begin(), EnemyLowerBattlefieldCards->begin(), EnemyLowerBattlefieldCards->end());
			vectAllBattlefields.insert(vectAllBattlefields.begin(), EnemyUpperBattlefieldCards->begin(), EnemyUpperBattlefieldCards->end());
			for (auto element : vectAllBattlefields)
			{
				GuiElementPositionX = element->GetPositionX();
				GuiElementPositionY = element->GetPositionY();
				GuiElementWidth = element->GetWidth();
				GuiElementHeight = element->GetHeight();
				if ((evnt.mouseButton.x >= GuiElementPositionX && evnt.mouseButton.x < (GuiElementPositionX + GuiElementWidth)) && // quick maths
					(evnt.mouseButton.y >= GuiElementPositionY && evnt.mouseButton.y <= (GuiElementPositionY + GuiElementHeight)))
				{
					CardPreview.SetTexture(element->GetTexture());
					element->Highlight();
					WasCardHighlighted = true;
				}
				else
				{
					element->Unhighlight();
				}
			}

			vector<reference_wrapper<RectangleObject>> TwoFieldRectangles; //zwyk³y wektor tworzy kopie obiektów, dlatego potrzebuje reference wrappera który bierze referencje na dane obiekty
			TwoFieldRectangles.push_back(UiLines[3]);
			TwoFieldRectangles.push_back(UiLines[4]);
			
			for (int i = 0; i < TwoFieldRectangles.size(); ++i)
			{
				auto Battlefield = TwoFieldRectangles[i];
				GuiElementPositionX = Battlefield.get().getPosition().x;
				GuiElementPositionY = Battlefield.get().getPosition().y;
				GuiElementWidth = Battlefield.get().getSize().x;
				GuiElementHeight = Battlefield.get().getSize().y;
				if ((evnt.mouseButton.x >= (GuiElementPositionX) && evnt.mouseButton.x < (GuiElementPositionX + GuiElementWidth)) && // quick maths
					(evnt.mouseButton.y >= (GuiElementPositionY) && evnt.mouseButton.y <= (GuiElementPositionY + GuiElementHeight)))
				{
					if (auto cardOperator = dynamic_pointer_cast<ICardOperator>(CurrentManager))
					{
						cardOperator->WhichBattlefield(static_cast<BattleField>(i));
					}
				}
			}

			if (!WasCardHighlighted)
			{
				if (auto cardOperator = dynamic_pointer_cast<ICardOperator>(CurrentManager))
				{
					cardOperator->PerformCardOperation(nullptr, evnt.mouseButton.button);
				}
			}
		}

		if (evnt.mouseButton.button == sf::Mouse::Right)
		{
			for (auto element : *UserHandCards)
			{
				float GuiElementWidth, GuiElementHeight, GuiElementPositionX, GuiElementPositionY;
				GuiElementPositionX = element->GetPositionX();
				GuiElementPositionY = element->GetPositionY();
				GuiElementWidth = element->GetWidth();
				GuiElementHeight = element->GetHeight();
				if ((evnt.mouseButton.x >= GuiElementPositionX && evnt.mouseButton.x < (GuiElementPositionX + GuiElementWidth)) && // quick maths
					(evnt.mouseButton.y >= GuiElementPositionY && evnt.mouseButton.y <= (GuiElementPositionY + GuiElementHeight)))
				{
					if (auto cardOperator = dynamic_pointer_cast<ICardOperator>(CurrentManager))
					{
						cardOperator->PerformCardOperation(element, evnt.mouseButton.button);
					}
				}

			}

		}
		break;

	case Event::MouseMoved:
		bool NoCardsHighlighted = true;
		float GuiElementWidth, GuiElementHeight, GuiElementPositionX, GuiElementPositionY;
		vector<reference_wrapper<RectangleObject>> TwoFieldRectangles; //zwyk³y wektor tworzy kopie obiektów, dlatego potrzebuje reference wrappera który bierze referencje na dane obiekty
		TwoFieldRectangles.push_back(UiLines[3]);
		TwoFieldRectangles.push_back(UiLines[4]);
		if (auto whichState = dynamic_pointer_cast<IngameStateManager>(CurrentManager))
		{
			for (auto card : *UserHandCards)
			{

				if (card->GetIsHighlighted())
				{
					NoCardsHighlighted = false;
					for (auto element : TwoFieldRectangles)
					{
						GuiElementPositionX = element.get().getPosition().x;
						GuiElementPositionY = element.get().getPosition().y;
						GuiElementWidth = element.get().getSize().x;
						GuiElementHeight = element.get().getSize().y;
						if ((evnt.mouseMove.x >= (GuiElementPositionX) && evnt.mouseMove.x < (GuiElementPositionX + GuiElementWidth)) && // quick maths
							(evnt.mouseMove.y >= (GuiElementPositionY) && evnt.mouseMove.y <= (GuiElementPositionY + GuiElementHeight)))
						{

							element.get().Highlight();
						}
						else
						{
							element.get().Unhighlight();
						}
					}
				}
			}
		}
		if (NoCardsHighlighted)
		{
			for (auto element : TwoFieldRectangles)
			{
				element.get().Unhighlight();
			}
		}

		break;
	}
}


void PlayLayout::SetLowerUserBattlefieldCards(shared_ptr<vector<shared_ptr<IGuiElement>>> cards)
{
	UserLowerBattlefieldCards = cards;
}

void PlayLayout::SetUpperUserBattlefieldCards(shared_ptr<vector<shared_ptr<IGuiElement>>> cards)
{
	UserUpperBattlefieldCards = cards;
}

void PlayLayout::SetLowerEnemyBattlefieldCards(shared_ptr<vector<shared_ptr<IGuiElement>>> cards)
{
	EnemyLowerBattlefieldCards = cards;
}

void PlayLayout::SetUpperEnemyBattlefieldCards(shared_ptr<vector<shared_ptr<IGuiElement>>> cards)
{
	EnemyUpperBattlefieldCards = cards;
}
