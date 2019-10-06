#include "stdafx.h"
#include "BaseGuiElement.h"


BaseGuiElement::BaseGuiElement(int positionX, int positionY, float objectWidth, float objectHeight, shared_ptr<ICallback> callback)
	:PositionX(positionX),PositionY(positionY),ObjectWidth(objectWidth),ObjectHeight(objectHeight), Callback(callback)
{
}


BaseGuiElement::~BaseGuiElement()
{
}

float BaseGuiElement::GetWidth()
{
	return ObjectWidth;
}
float BaseGuiElement::GetHeight()
{
	return ObjectHeight;
}
float BaseGuiElement::GetPositionX()
{
	return PositionX;
}
float BaseGuiElement::GetPoisitionY()
{
	return PositionY;
}
float BaseGuiElement::GetPadding()
{
	return Padding;
}
void BaseGuiElement::SetWidth(float width)
{
	this->ObjectWidth = width;
}
void BaseGuiElement::SetHeight(float height)
{
	this->ObjectHeight = height;
}
void BaseGuiElement::SetPositionX(float x)
{
	this->PositionX = x;
}
void BaseGuiElement::SetPositionY(float y)
{
	this->PositionY = y;
}
void BaseGuiElement::SetPadding(float padding)
{
	this->Padding = padding;
}

void BaseGuiElement::action()
{
	if (Callback == nullptr)
	{
		cerr << "callback is a null pointer!" << endl;
		return;
	}
	Callback->action();

}