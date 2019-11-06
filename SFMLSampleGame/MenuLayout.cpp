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
	for (auto element : ButtonObjectsMap)
	{
		element.second->Draw(Window);
	}
	/*Window->draw(*ButtonObjectsMap["Play"]); 
	Window->draw(*ButtonObjectsMap["Deck"]);
	Window->draw(*ButtonObjectsMap["Quit"]);
	Window->draw(ButtonObjectsMap["Play"]->GetText());
	Window->draw(ButtonObjectsMap["Deck"]->GetText());
	Window->draw(ButtonObjectsMap["Quit"]->GetText());*/
	
}

void MenuLayout::ObtainVector(vector<shared_ptr<IGuiElement>> V)
{
	BaseLayout::ObtainVector(V); //zapisuje sobie na pó¿niej (ewentualnie)
	ColumnMaker columnMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldSix, EnumScreenFields::FieldEight);
	columnMaker.OrganizePosition(V);
}