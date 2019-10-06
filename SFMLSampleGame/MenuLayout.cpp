#include "stdafx.h"
#include "MenuLayout.h"
#include "ColumnMaker.h"
#include "RowMaker.h"

MenuLayout::MenuLayout(shared_ptr<RenderWindow> window)
	:BaseLayout(window)
{
	if (!this->MenuTexture.loadFromFile("Resources/Images/menu1.jpg"))
	{
		cerr << "Error while loading Menu Texture" << endl; //error handling
		system("pause");
	}
	
	MenuBackgorund.setTexture(MenuTexture);
	
	
}


MenuLayout::~MenuLayout()
{
}

void MenuLayout::Show()
{
	Window->draw(MenuBackgorund);
	
}

void MenuLayout::ObtainVector(vector<reference_wrapper<BaseGuiElement>> V)
{
	ColumnMaker columnMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldThree, EnumScreenFields::FieldFour);
	columnMaker.OrganizePosition(V);
	/*RowMaker rowMaker(window->getSize().x, window->getSize().y, EnumScreenFields::FieldThree, EnumScreenFields::FieldFour);
	vector<reference_wrapper<BaseGuiElement>> Ve;
	Ve.push_back(b4);
	Ve.push_back(b5);
	Ve.push_back(b6);
	rowMaker.OrganizePosition(Ve);*/
}