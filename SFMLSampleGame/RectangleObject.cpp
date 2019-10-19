#include "stdafx.h"
#include "RectangleObject.h"


RectangleObject::RectangleObject(int positionX, int positionY, float objectWidth, float objectHeight, Color color)
	:BaseGuiElement(positionX, positionY, objectWidth, objectHeight), RectangleSize(objectWidth, objectHeight)
{
	setPosition(positionX, positionY);
	//setOrigin(positionX / 2, positionY / 2);
	setFillColor(color);
	setSize(RectangleSize);
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
	BaseGuiElement::SetPositionX(x);
}
void RectangleObject::SetPositionY(float y)
{
	setPosition(PositionX, y);
	BaseGuiElement::SetPositionY(y);
}