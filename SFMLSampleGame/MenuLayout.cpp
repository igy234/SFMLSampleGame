#include "stdafx.h"
#include "MenuLayout.h"
#include "ColumnMaker.h"
#include "RowMaker.h"

MenuLayout::MenuLayout(shared_ptr<RenderWindow> window)
	:BaseLayout(window)
{
	if (!this->BackgroundTexture.loadFromFile("Resources/Images/menu.jpg"))
	{
		cerr << "Error while loading Menu Texture" << endl; //error handling
		system("pause");
	}
	
	BackgroundSprite.setTexture(BackgroundTexture);
}


MenuLayout::~MenuLayout()
{
}

void MenuLayout::Show()
{
	Window->draw(BackgroundSprite);
	for (auto element : GuiElements)
	{
		element->Draw(Window);
	}
}

void MenuLayout::ObtainVector(vector<shared_ptr<IGuiElement>> V)
{
	BaseLayout::ObtainVector(V); //saves for later eventually
	ColumnMaker columnMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldSix, EnumScreenFields::FieldEight);
	columnMaker.OrganizePosition(V);
}