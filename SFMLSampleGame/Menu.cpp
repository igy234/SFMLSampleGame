#include "stdafx.h"
#include "Menu(stare).h"

Menu::Menu(const float& width, const float& height)
{
	
	if (!this->MenuTexture.loadFromFile("Resources/Images/menu1.jpg"))
	{
		cerr << "Error while loading Menu Texture" << endl; //error handling
		system("pause");
	}

	MenuBackgorund.setTexture(MenuTexture);
	//MenuBackgorund.setColor(Color::Green); //color the texture

	
}

Menu::~Menu()
{
}

void Menu::drawBackground(RenderWindow &window)
{
	window.draw(MenuBackgorund);
}


