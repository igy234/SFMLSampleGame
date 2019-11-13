#include "stdafx.h"
#include "BaseCard.h"


BaseCard::BaseCard(shared_ptr<ICardModel> model, int positionX, int positionY, float objectWidth, float objectHeight, Color color)
	: RectangleObject(positionX, positionY, objectWidth, objectHeight, color),
	Model(model)
{

	if (!this->CardTexture.loadFromFile("Resources/Images/" + Model->GetName() + ".jpg"))
	{
		cerr << "Error while loading Menu Texture" << endl; //error handling
		system("pause");
	}

	CardTexture.setSmooth(true);
	CardSprite.setTexture(CardTexture);
	CardSprite.setPosition(positionX, positionY);
	
	 //below rescaling to ideal size
	CardSprite.setScale(
		objectWidth / CardSprite.getLocalBounds().width,
		objectHeight / CardSprite.getLocalBounds().height);
	
	
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
	CardSprite.setPosition(static_cast<int>(x), PositionY);
}

void BaseCard::SetPositionY(float y)
{
	RectangleObject::SetPositionY(y);
	CardSprite.setPosition(PositionX, static_cast<int>(y));
}

void BaseCard::Draw(shared_ptr<RenderWindow> window) 
{
	window->draw(*this);
	window->draw(CardSprite);
}

Texture BaseCard::GetTexture()
{
	return CardTexture;
}

void BaseCard::Highlight()
{
	BaseGuiElement::Highlight();
	setOutlineThickness(2);
	setOutlineColor(Color(255, 216, 55));
}

void BaseCard::Unhighlight()
{
	BaseGuiElement::Unhighlight();
	setOutlineThickness(0);
}

shared_ptr<ICardModel> BaseCard::GetModel()
{
	return Model;
}
