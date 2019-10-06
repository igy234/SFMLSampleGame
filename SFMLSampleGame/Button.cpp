#include "stdafx.h"
#include "Button.h"


Button::Button(string description, float t_x, float t_y)
{
	if (!this->BtnTexture.loadFromFile("Resources/Images/Hell.png"))
	{
		cout << "Error while loading Button Texture" << endl; //error handling
		system("pause"); 
	}
	if (!this->font.loadFromFile("Resources/Fonts/GWINT_Font.ttf")) //mo¿e byæ bez this
	{
		cout << "Error while loading font" << endl; //error handling
		system("pause");

	}

	convex.setPosition(t_x, t_y); //stawia point 0 na œrodku
	convex.setPointCount(6);
	convex.setFillColor(Color(255,0,0,50)); // ostatnie to przezroczystosc 
	//convex.setTexture(&BtnTexture);
	convex.setOrigin(ButtonWidth/2, 0); //ustawiamy origin na œrodek kszta³tu czyliii 137.5 w prawo od point 0
	convex.setOutlineColor(Color::White);
	convex.setOutlineThickness(Thickness);
	// anty-clockwise!!!!!
	int HalfButtonHeight = ButtonHeight / 2; // we want 25px so half/2
	convex.setPoint(0, Vector2f(0.f, 0.f)); //lewy skrajny 
	convex.setPoint(1, Vector2f(HalfButtonHeight, HalfButtonHeight)); //lewy dolny
	convex.setPoint(2, Vector2f(ButtonWidth- HalfButtonHeight, HalfButtonHeight)); //prawy dolny
	convex.setPoint(3, Vector2f(ButtonWidth, 0.f)); //prawy skrajny
	convex.setPoint(4, Vector2f(ButtonWidth - HalfButtonHeight, -HalfButtonHeight)); //prawy górny
	convex.setPoint(5, Vector2f(HalfButtonHeight, -HalfButtonHeight)); //lewy górny

	menuTexts[0].setFont(font);
	menuTexts[0].setFillColor(Color::White);
	menuTexts[0].setString(description);
	//menuTexts[0].setPosition(t_x, (t_y / ScrProp) * BtnOrdr);
	menuTexts[0].setOrigin(27, 35); //trzeba to bedzie jeszcze dostosowaæ

	menuTexts[1].setFont(font);
	menuTexts[1].setFillColor(Color::White);
	menuTexts[1].setString("Deck");
	//menuTexts[1].setPosition(t_x, (t_y / ScrProp) * (BtnOrdr - 10));
	menuTexts[1].setOrigin(27, 30); //trzeba to bedzie jeszcze dostosowaæ

	menuTexts[2].setFont(font);
	menuTexts[2].setFillColor(Color::White);
	menuTexts[2].setString("Play");
	//menuTexts[2].setPosition(t_x, (t_y / ScrProp) * (BtnOrdr - 20));
	menuTexts[2].setOrigin(27, 30); //trzeba to bedzie jeszcze dostosowaæ
	selectedItemIndex = 0;
}

void Button::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->convex, state);
}

void Button::drawTexts(RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i)
	{
		window.draw(menuTexts[i]);
	}
}

void Button::MoveUp() //trzeba nad tym jeszcze popracowaæ 
{
	HighlightCtrl = true;
	if (selectedItemIndex == 2)
	{
		menuTexts[selectedItemIndex].setFillColor(Color::Red);
	}
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menuTexts[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menuTexts[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Button::MoveDown()
{
	HighlightCtrl = true;
	if (selectedItemIndex == 0)
	{
		menuTexts[selectedItemIndex].setFillColor(Color::Red);
	}
	if (selectedItemIndex - 1 >= 0)
	{
		menuTexts[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menuTexts[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Button::HighlightButton(int x, int y)
{
	menuTexts[0].setFillColor(Color::White); //reset the colors after controling with keyboard
	menuTexts[1].setFillColor(Color::White);
	menuTexts[2].setFillColor(Color::White);

	if (x >= 525 && x <= 750 && y >= 325 && y <= 375) //play
	{
		selectedItemIndex = 2;
		menuTexts[selectedItemIndex].setFillColor(Color::Red);
	}
	else if (x >= 525 && x <= 750 && y >= 395 && y <= 445) //deck
	{
		selectedItemIndex = 1;
		menuTexts[selectedItemIndex].setFillColor(Color::Red);
	}
	else if (x >= 525 && x <= 750 && y >= 465 && y <= 505) //quit
	{
		selectedItemIndex = 0;
		menuTexts[selectedItemIndex].setFillColor(Color::Red);
	}
	else
	{
		menuTexts[selectedItemIndex].setFillColor(Color::White);
	}
}

void Button::HighlightControl(int x, int y)
{
	if (x >= 525 && x <= 750 && y >= 325 && y <= 375) //play
	{
		HighlightCtrl = false;
	}
	else if (x >= 525 && x <= 750 && y >= 395 && y <= 445) //deck
	{
		HighlightCtrl = false;
	}
	else if (x >= 525 && x <= 750 && y >= 465 && y <= 505) //quit
	{
		HighlightCtrl = false;
	}

}

int Button::MouseClickedInRange(int x, int y)
{
	if (x >= 525 && x <= 750 && y >= 325 && y <= 375) //play
	{
		return 2;
	}
	else if (x >= 525 && x <= 750 && y >= 395 && y <= 445) //deck
	{
		return 1;
	}
	else if (x >= 525 && x <= 750 && y >= 465 && y <= 505) //quit
	{
		return 0;
	}
}
