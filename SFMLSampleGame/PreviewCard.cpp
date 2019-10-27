#include "stdafx.h"
#include "PreviewCard.h"
#include "Utils.h"

PreviewCard::PreviewCard(int positionX, int positionY, float objectWidth, float objectHeight)
	:BaseGuiElement(positionX, positionY, objectWidth, objectHeight)
{
	CardPreviewSprite.setPosition(positionX, positionY);
	CardPreviewSprite.setScale(HalfScale, HalfScale);
}


PreviewCard::~PreviewCard()
{
}

void PreviewCard::Draw(shared_ptr<RenderWindow> window)
{
	window->draw(CardPreviewSprite);
}

Texture PreviewCard::GetTexture()
{
	return CardPreviewTexture;
}

void PreviewCard::SetTexture(Texture PreviewTexture)
{
	CardPreviewTexture = PreviewTexture;
	CardPreviewSprite.setTexture(CardPreviewTexture);
}

void PreviewCard::SetPositionX(float x)
{
	CardPreviewSprite.setPosition(x, PositionY);
	BaseGuiElement::SetPositionX(x);
}
void PreviewCard::SetPositionY(float y)
{
	CardPreviewSprite.setPosition(PositionX, y);
	BaseGuiElement::SetPositionY(y);
}