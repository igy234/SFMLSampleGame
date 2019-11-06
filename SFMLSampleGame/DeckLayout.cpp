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

}

void DeckLayout::ObtainVector(vector<shared_ptr<IGuiElement>> V)
{
	BaseLayout::ObtainVector(V); //zapisuje sobie na pó¿niej (ewentualnie)
	ColumnMaker columnMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldThree, EnumScreenFields::FieldFour);
	columnMaker.OrganizePosition(V);

}