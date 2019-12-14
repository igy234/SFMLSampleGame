#include "stdafx.h"
#include "RectangleObject.h"


RectangleObject::RectangleObject(int positionX, int positionY, float objectWidth, float objectHeight, Color color, string text)
	:BaseGuiElement(positionX, positionY, objectWidth, objectHeight), RectangleSize(objectWidth, objectHeight)
{
	setPosition(positionX, positionY);
	//setOrigin(positionX / 2, positionY / 2);
	setFillColor(color);
	setSize(RectangleSize);
	
	if (text.length())
	{
		Text label;
		label.setFont(FontProvider::instance().GetFont());
		label.setString(text);
		label.setPosition(positionX, positionY);
		label.setFillColor(Color::White);

		setOrigin(objectWidth / 2, objectHeight / 2); //origin makes that the center of rectangle is in the starting cooridnates of ields net

		FloatRect textRect = label.getLocalBounds(); //make a rectangle around text
		label.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); //center the origin inside the rectangle

		Label = label; //label is optional
	}
}



RectangleObject::~RectangleObject()
{
}

void RectangleObject::SetWidth(float width)
{
	RectangleSize.x = width;
	setSize(RectangleSize);
	BaseGuiElement::SetWidth(width);
}
void RectangleObject::SetHeight(float height)
{
	RectangleSize.y = height;
	setSize(RectangleSize);
	BaseGuiElement::SetHeight(height);
}
void RectangleObject::SetPositionX(float x)
{
	setPosition(x, PositionY);
	if (Label.has_value())
	{
		Label.value().setPosition(x, PositionY);
	}
	BaseGuiElement::SetPositionX(x);
}
void RectangleObject::SetPositionY(float y)
{
	setPosition(PositionX, y);
	if (Label.has_value())
	{
	Label.value().setPosition(PositionX, y);
	}
	BaseGuiElement::SetPositionY(y);
}

void RectangleObject::Draw(shared_ptr<RenderWindow> window)
{
		window->draw(*this); //Object needed thats why *this(because this is a pointer)
		if (Label.has_value())
		{
			window->draw(Label.value());
		}
}

void RectangleObject::Highlight()
{
	BaseGuiElement::Highlight();
	setFillColor(Color(255, 216, 55, 50));
}

void RectangleObject::Unhighlight()
{
	BaseGuiElement::Unhighlight();
	setFillColor(Color(255, 216, 55, 0));
}

void RectangleObject::SetText(string txt)
{
	Label.value().setString(txt);
}
