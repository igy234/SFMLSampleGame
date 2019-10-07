#include "stdafx.h"
#include "ButtonObject.h"


ButtonObject::ButtonObject(string label, int positionX, int positionY, float objectWidth, float objectHeight, shared_ptr<ICallback> callback)
	:BaseGuiElement(positionX, positionY, objectWidth, objectHeight, callback)
{
	

	ButtonLabel.setFont(FontProvider::instance().GetFont());
	ButtonLabel.setString(label);
	ButtonLabel.setPosition(positionX, positionY);
	ButtonLabel.setFillColor(Color::White);
	
	setPosition(positionX, positionY); //ustawia pierwszy punkt convexu
	setPointCount(6); // ustawia ilosc punktów convexu
	setFillColor(Color(255, 0, 0, 50)); // kolor, ostatnie to przezroczystosc 
	//convex.setTexture(&BtnTexture);
	
	setOrigin(objectWidth / 2, 0); //origin sprawia ¿e œrodek buttona rysuje nam siê w koordynatach startowych pola naszej siatki
	
	FloatRect textRect = ButtonLabel.getLocalBounds(); //wyznacz kwadrat do oko³a textu
	ButtonLabel.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); //srodkuj origin w kwadracie
	
	setOutlineColor(Color::White);
	setOutlineThickness(Thickness); //grubosc krawedzi buttonu 
	SetPoints(); //anty-clockwise!!!!!
}


ButtonObject::~ButtonObject()
{
}

void ButtonObject::SetWidth(float width)
{
	BaseGuiElement::SetWidth(width);
	SetPoints();
}
void ButtonObject::SetHeight(float height)
{
	BaseGuiElement::SetHeight(height);
	SetPoints();
}
void ButtonObject::SetPositionX(float x)
{
	setPosition(x, PositionY);
	ButtonLabel.setPosition(x, PositionY);
	BaseGuiElement::SetPositionX(x);
	
}
void ButtonObject::SetPositionY(float y)
{
	setPosition(PositionX, y);
	ButtonLabel.setPosition(PositionX, y);
	BaseGuiElement::SetPositionY(y);
}

void ButtonObject::SetPadding(float padding)
{
	BaseGuiElement::SetPadding(padding);
}

void ButtonObject::SetPoints()
{
	int HalfButtonHeight = ObjectHeight / 2; 
	setPoint(0, Vector2f(0.f, 0.f)); //lewy skrajny 
	setPoint(1, Vector2f(HalfButtonHeight, HalfButtonHeight)); //lewy dolny
	setPoint(2, Vector2f(ObjectWidth - HalfButtonHeight, HalfButtonHeight)); //prawy dolny
	setPoint(3, Vector2f(ObjectWidth, 0.f)); //prawy skrajny
	setPoint(4, Vector2f(ObjectWidth - HalfButtonHeight, -HalfButtonHeight)); //prawy górny
	setPoint(5, Vector2f(HalfButtonHeight, -HalfButtonHeight)); //lewy górny
}
Text& ButtonObject::GetText()
{
	return ButtonLabel;
}

void ButtonObject::Highlight()
{
	BaseGuiElement::Highlight();
	ButtonLabel.setFillColor(Color::Red);
}

void ButtonObject::Unhighlight()
{
	BaseGuiElement::Unhighlight();
	ButtonLabel.setFillColor(Color::White);
}