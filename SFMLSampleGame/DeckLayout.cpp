#include "stdafx.h"
#include "DeckLayout.h"
#include "ColumnMaker.h"
#include "RowMaker.h"


DeckLayout::DeckLayout(shared_ptr<RenderWindow> window)
 :BaseLayout(window)
{
	if (!this->BackgroundTexture.loadFromFile("Resources/Images/smisznysmok.png"))

	{
		cerr << "Error while loading Menu Texture" << endl; //error handling
		system("pause");
	}

	BackgroundSprite.setTexture(BackgroundTexture);

	UnderDevelopementRectangle = make_shared<RectangleObject>(0, 0, 750, 100, Color(255, 0, 0, 50), "This state of the game is under developement");
	UnderDevelopementRectangle->setOutlineThickness(2);
	UnderDevelopementRectangle->SetPadding(0);
	UnderDevelopementVector.push_back(UnderDevelopementRectangle);
	RowMaker rowMakerDevelopementInfo(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldSix, EnumScreenFields::FieldTwo);
	rowMakerDevelopementInfo.SetStarterWidthPadding(100);
    rowMakerDevelopementInfo.OrganizePosition(UnderDevelopementVector);

	
}


DeckLayout::~DeckLayout()
{
}

void DeckLayout::Show()
{
	Window->draw(BackgroundSprite);
	for (auto element : GuiElements)
	{
		element->Draw(Window);
	}

	for (auto element : UnderDevelopementVector)
	{
		element->Draw(Window);
	}
}

void DeckLayout::ObtainVector(vector<shared_ptr<IGuiElement>> V)
{
	BaseLayout::ObtainVector(V); //zapisuje sobie na pó¿niej (ewentualnie)
	ColumnMaker columnMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldSix, EnumScreenFields::FieldSix);
	columnMaker.OrganizePosition(V);

}