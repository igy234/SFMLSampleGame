#include "stdafx.h"
#include "ButtonObject.h"


ButtonObject::ButtonObject(string label, int positionX, int positionY, float objectWidth, float objectHeight, shared_ptr<ICallback> callback, int opacity)
	:BaseGuiElement(positionX, positionY, objectWidth, objectHeight, callback)
{
	this->IsUserInteractive = true;

	ButtonLabel.setFont(FontProvider::instance().GetFont()); //singleton fontProvider usesd to get font
	ButtonLabel.setString(label);
	ButtonLabel.setPosition(positionX, positionY);
	ButtonLabel.setFillColor(Color::White);
	
	setPosition(positionX, positionY); //sets the first point of convex
	setPointCount(6); // sets total number of oconvex points
	setFillColor(Color(255, 0, 0, opacity)); // color 
	setOrigin(objectWidth / 2, 0); 
	
	FloatRect textRect = ButtonLabel.getLocalBounds(); //make a rectangle around text
	ButtonLabel.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); //set the origin in rectangle
	
	setOutlineColor(Color::White);
	setOutlineThickness(Thickness); 
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
	setPoint(0, Vector2f(0.f, 0.f)); //left  
	setPoint(1, Vector2f(HalfButtonHeight, HalfButtonHeight)); //bottom left
	setPoint(2, Vector2f(ObjectWidth - HalfButtonHeight, HalfButtonHeight)); //bottom right
	setPoint(3, Vector2f(ObjectWidth, 0.f)); //right
	setPoint(4, Vector2f(ObjectWidth - HalfButtonHeight, -HalfButtonHeight)); //top right
	setPoint(5, Vector2f(HalfButtonHeight, -HalfButtonHeight)); //top left
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

void ButtonObject::Draw(shared_ptr<RenderWindow> window)
{
	window->draw(*this); //Object needed thats why *this(because this is a pointer)
	window->draw(ButtonLabel);
}

void ButtonObject::SetSpecialBackgroundColor(Color color)
{
	setFillColor(color);
}

