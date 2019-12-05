#include "stdafx.h"
#include "DeckLayout.h"
#include "ColumnMaker.h"
#include "RowMaker.h"
#include "Utils.h"
#include "CardFactory.h"

DeckLayout::DeckLayout(shared_ptr<RenderWindow> window)
 :BaseLayout(window),
  CardPreview(0, 0, 0, 0)
{
	if (!this->BackgroundTexture.loadFromFile("Resources/Images/Forest.png"))
	{
		cerr << "Error while loading Menu Texture" << endl; //error handling
		system("pause");
	}
	BackgroundSprite.setTexture(BackgroundTexture);

	int FieldX, FieldY, WidthFactor, HeightFactor, WindowSizeX, WindowSizeY;
	WindowSizeX = Window->getSize().x;
	WindowSizeY = Window->getSize().y;

	RectangleObject BackDrop(0, 0, Window->getSize().x, Window->getSize().y);
	BackDrop.setOrigin(0, 0);
	BackDrop.setFillColor(Color(0, 0, 0, 175));
	BackDrop.setOutlineThickness(Thickness);
	UiLines.push_back(BackDrop);





	InfoRectangle = make_shared<RectangleObject>(0, 0, 750, 50, Color(255, 0, 0, 50), "Please Click the card you want to check out...");
	InfoRectangle->setOutlineThickness(2);
	InfoRectangle->SetPadding(0);
	InfoVector.push_back(InfoRectangle);
	RowMaker rowMakerInfo(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldSix, EnumScreenFields::FieldOne);
	rowMakerInfo.SetStarterWidthPadding(100);
	rowMakerInfo.SetStarterHeightPadding(50);
	rowMakerInfo.OrganizePosition(InfoVector);

	//starting x, starting y, width and heightfor given field of net
	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldEight, EnumScreenFields::FieldThree);
	CardPreview.SetPositionX(FieldX + PreviewPadding);
	CardPreview.SetPositionY(FieldY);

	CardFactory factory;
	for (int i = 0; i <= static_cast<int>(EnumCardName::COUNT); i++)
	{
		if (i < 5)
		{
			auto card = factory.CreateCard(static_cast<EnumCardName>(i));
			card->SetPadding(10);
			FirstCardsVector.push_back(card);
		}
		else if (i >= 5 && i < 10)
		{
			auto card = factory.CreateCard(static_cast<EnumCardName>(i));
			card->SetPadding(10);
			SecondCardsVector.push_back(card);
		}
		else if (i >= 10 && i < 15)
		{
			auto card = factory.CreateCard(static_cast<EnumCardName>(i));
			card->SetPadding(10);
			ThirdCardsVector.push_back(card);
		}
		/*else if (i >= 18 && i < 26)
		{
			auto card = factory.CreateCard(static_cast<EnumCardName>(i));
			card->SetPadding(10);
			FourthCardsVector.push_back(card);
		}*/

	}

	RowMaker rowMakerFirstCardsVector(window->getSize().x, window->getSize().y, EnumScreenFields::FieldTwo, EnumScreenFields::FieldThree);
	rowMakerFirstCardsVector.SetStarterWidthPadding(10);
	rowMakerFirstCardsVector.SetStarterHeightPadding(4);
	rowMakerFirstCardsVector.OrganizePosition(FirstCardsVector);

	RowMaker rowMakerSecondCardsVector(window->getSize().x, window->getSize().y, EnumScreenFields::FieldTwo, EnumScreenFields::FieldFive);
	rowMakerSecondCardsVector.SetStarterWidthPadding(10);
	rowMakerSecondCardsVector.SetStarterHeightPadding(4);
	rowMakerSecondCardsVector.OrganizePosition(SecondCardsVector);

	RowMaker rowMakerThirdCardsVector(window->getSize().x, window->getSize().y, EnumScreenFields::FieldTwo, EnumScreenFields::FieldSeven);
	rowMakerThirdCardsVector.SetStarterWidthPadding(10);
	rowMakerThirdCardsVector.SetStarterHeightPadding(4);
	rowMakerThirdCardsVector.OrganizePosition(ThirdCardsVector);

	RowMaker rowMakerFourthCardsVector(window->getSize().x, window->getSize().y, EnumScreenFields::FieldTwo, EnumScreenFields::FieldNine);
	rowMakerFourthCardsVector.SetStarterWidthPadding(10);
	rowMakerFourthCardsVector.SetStarterHeightPadding(4);
	rowMakerFourthCardsVector.OrganizePosition(FourthCardsVector);

}


DeckLayout::~DeckLayout()
{
}

void DeckLayout::Show()
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

	for (auto element : InfoVector)
	{
		element->Draw(Window);
	}

	for (auto element : FirstCardsVector)
	{
		element->Draw(Window);
	}

	for (auto element : SecondCardsVector)
	{
		element->Draw(Window);
	}

	for (auto element : ThirdCardsVector)
	{
		element->Draw(Window);
	}

	for (auto element : FourthCardsVector)
	{
		element->Draw(Window);
	}

	CardPreview.Draw(Window);

}

void DeckLayout::ObtainVector(vector<shared_ptr<IGuiElement>> V)
{
	BaseLayout::ObtainVector(V); //zapisuje sobie na pó¿niej (ewentualnie)
	RowMaker rowMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldFive, EnumScreenFields::FieldEleven);
	rowMaker.OrganizePosition(V);
}

void DeckLayout::HandleMouseEvent(const Event & evnt)
{
	BaseLayout::HandleMouseEvent(evnt);
	switch (evnt.type)
	{
	case Event::MouseButtonPressed:
		if (evnt.mouseButton.button == sf::Mouse::Left)
		{
			vector<shared_ptr<IGuiElement>> vectAllCards = FirstCardsVector;
			vectAllCards.insert(vectAllCards.begin(), SecondCardsVector.begin(), SecondCardsVector.end());
			vectAllCards.insert(vectAllCards.begin(), ThirdCardsVector.begin(), ThirdCardsVector.end());
			vectAllCards.insert(vectAllCards.begin(), FourthCardsVector.begin(), FourthCardsVector.end());


			float GuiElementWidth, GuiElementHeight, GuiElementPositionX, GuiElementPositionY;
			for (auto element : vectAllCards)
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
				}
				else
				{

					element->Unhighlight();
				}
			}
		}
	}
}
