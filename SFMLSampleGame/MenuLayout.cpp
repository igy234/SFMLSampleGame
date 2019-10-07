#include "stdafx.h"
#include "MenuLayout.h"
#include "ColumnMaker.h"
#include "RowMaker.h"

MenuLayout::MenuLayout(shared_ptr<RenderWindow> window)
	:BaseLayout(window)
{
	if (!this->BackgroundTexture.loadFromFile("Resources/Images/menu1.jpg"))
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
	Window->draw(*ButtonObjectsMap["Play"]); // . get() nie dzia³a ale * bierze nam zwykly obiekt a nie shared_ptr, wywlekamy to na co ten shared ptr wskazuje
	Window->draw(*ButtonObjectsMap["Deck"]);
	Window->draw(*ButtonObjectsMap["Quit"]);
	Window->draw(ButtonObjectsMap["Play"]->GetText());
	Window->draw(ButtonObjectsMap["Deck"]->GetText());
	Window->draw(ButtonObjectsMap["Quit"]->GetText());
	
}

void MenuLayout::ObtainVector(vector<shared_ptr<IGuiElement>> V)
{
	BaseLayout::ObtainVector(V); //zapisuje sobie na pó¿niej (ewentualnie)
	ColumnMaker columnMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldThree, EnumScreenFields::FieldFour);
	columnMaker.OrganizePosition(V);
	/*RowMaker rowMaker(window->getSize().x, window->getSize().y, EnumScreenFields::FieldThree, EnumScreenFields::FieldFour);
	vector<reference_wrapper<BaseGuiElement>> Ve;
	Ve.push_back(b4);
	Ve.push_back(b5);
	Ve.push_back(b6);
	rowMaker.OrganizePosition(Ve);*/
}