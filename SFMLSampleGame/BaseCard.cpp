#include "stdafx.h"
#include "BaseCard.h"


BaseCard::BaseCard(int positionX, int positionY, float objectWidth, float objectHeight, Color color)
	: RectangleObject(positionX, positionY, objectWidth, objectHeight, color) 
{

	if (!this->CardTexture.loadFromFile("Resources/Images/test_card.jpg"))
	{
		cerr << "Error while loading Menu Texture" << endl; //error handling
		system("pause");
	}

	
	CardSprite.setTexture(CardTexture);
	CardSprite.setPosition(positionX, positionY);
	
	// below rescaling to ideal size
	CardSprite.setScale(
		objectWidth / CardSprite.getLocalBounds().width,
		objectHeight / CardSprite.getLocalBounds().height);
	
	CardTexture.setSmooth(true);
}


BaseCard::~BaseCard()
{
}

void BaseCard::SetWidth(float width) //1 is default
{
	RectangleObject::SetWidth(width);
	CardSprite.setScale(
		width / CardSprite.getLocalBounds().width,
		1);
}
void BaseCard::SetHeight(float height) //1 is default
{
	RectangleObject::SetHeight(height);
	CardSprite.setScale(
		1, height / CardSprite.getLocalBounds().height);
}
void BaseCard::SetPositionX(float x)
{
	RectangleObject::SetPositionX(x);
	CardSprite.setPosition(x, PositionY);
}

void BaseCard::SetPositionY(float y)
{
	RectangleObject::SetPositionY(y);
	CardSprite.setPosition(PositionX, y);
}

void BaseCard::Draw(shared_ptr<RenderWindow> window) 
{
	window->draw(*this);
	window->draw(CardSprite);
}