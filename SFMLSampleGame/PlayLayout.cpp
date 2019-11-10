#include "stdafx.h"
#include "PlayLayout.h"
#include "ColumnMaker.h"
#include "RowMaker.h"
#include "RectangleObject.h"
#include "Utils.h"
#include "BaseCard.h"
#include "CardFactory.h"
#include "ICardOperator.h"

PlayLayout::PlayLayout(shared_ptr<RenderWindow> window, shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards, shared_ptr<IStateManager>& currentManager, shared_ptr<RectangleObject> exchangeCardsInfo) //vector holding cards in user's hand)
	:BaseLayout(window),	
	CardPreview(0,0,0,0),
	UserHandCards(userHandCards),
	CurrentManager(currentManager)
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
	


	/*for (int i = 0; i <7; ++i)
	{
		auto card = factory.CreateCard(shuffle.GenerateRandomCardNameEnum());
		UserHandCards.push_back(card);
		UserHandCards[i]->SetPadding(10);
	}*/

	/*for (int i = 0; i < 7; ++i)
	{
		EnemyHandCards.push_back(make_shared<BaseCard>(0, 0, 163, 185));
		EnemyHandCards[i]->SetPadding(10);
	}*/

	RowMaker rowMakerUserHandCards(window->getSize().x, window->getSize().y, EnumScreenFields::FieldTwo, EnumScreenFields::FieldNine);
	rowMakerUserHandCards.SetStarterWidthPadding(10);
	rowMakerUserHandCards.SetStarterHeightPadding(4);
	rowMakerUserHandCards.OrganizePosition(*UserHandCards);

	//region information rectangles
	#pragma region InfoRectangles
	int i = 10;
	shared_ptr<RectangleObject> EnemyCardsCounter = make_shared<RectangleObject>(0, 0, 260, 60, Color(255, 0, 0, 50), "Enemy has " + to_string(i) + " cards");
	EnemyCardsCounter->SetPadding(10);
	EnemyCardsCounter->setOutlineThickness(Thickness);
	TurnAndCardsInformationRectangles.push_back(EnemyCardsCounter);


	string s = "your";
	string s2 = "Enemy's";
	shared_ptr<RectangleObject> TurnDisplayer = make_shared<RectangleObject>(0, 0, 230, 60, Color(255, 0, 0, 50), s +" turn");
	TurnDisplayer->SetPadding(10);
	TurnDisplayer->setOutlineThickness(Thickness);
	TurnAndCardsInformationRectangles.push_back(TurnDisplayer);
	
	ColumnMaker columnMakerTurnAndCards(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldTen, EnumScreenFields::FieldOne);
	columnMakerTurnAndCards.SetStarterHeightPadding(30);
	columnMakerTurnAndCards.OrganizePosition(TurnAndCardsInformationRectangles);
	
	
#pragma endregion InfoRectangles 

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
	HandRectangle.SetHeight(HeightFactor*(static_cast<int>(EnumScreenFields::FieldThree) + 1) - ThicknessShift);
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

	for (auto element : TurnAndCardsInformationRectangles)
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
	//Window->draw(CardPreviewSprite);
	CardPreview.Draw(Window);
}

void PlayLayout::ObtainVector(vector<shared_ptr<IGuiElement>> V)
{
	//auto vect = GuiElements;
	BaseLayout::ObtainVector(V); //saved for later (eventually)
	ColumnMaker columnMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldTen, EnumScreenFields::FieldNine);
	columnMaker.OrganizePosition(V);

	//GuiElements.insert(GuiElements.end(), vect.begin(), vect.end());
}

void PlayLayout::HandleMouseEvent(const Event& evnt)
{
	BaseLayout::HandleMouseEvent(evnt);
	switch (evnt.type)
	{
	case Event::MouseButtonPressed:
		if (evnt.mouseButton.button == sf::Mouse::Left)
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
					CardPreview.SetTexture(element->GetTexture());
					element->Highlight();
				}
				else
				{
					element->Unhighlight();
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
						cardOperator->PerformCardOperation(element);
					}
				}

			}

		}
		break;
	case Event::MouseMoved:
		bool NoCardsHighlighted = true;
		float GuiElementWidth, GuiElementHeight, GuiElementPositionX, GuiElementPositionY;
		vector<reference_wrapper<RectangleObject>> TwoFieldRectangles; //zwyk�y wektor tworzy kopie obiekt�w, dlatego potrzebuje reference wrappera kt�ry bierze referencje na dane obiekty
		TwoFieldRectangles.push_back(UiLines[3]);
		TwoFieldRectangles.push_back(UiLines[4]);
		
		for (auto card : *UserHandCards) {
				
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

