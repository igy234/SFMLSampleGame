#pragma once
#include "ICard.h"
#include "RectangleObject.h"
#include "ICardModel.h"
#include "ShuffleManager.h"


class BaseCard : public ICard, public RectangleObject
{
protected:
	Texture CardTexture; 
	Sprite CardSprite;

public:
	virtual void SetWidth(float width) override;
	virtual void SetHeight(float height) override;
	virtual void SetPositionX(float x) override;
	virtual void SetPositionY(float y) override;
	BaseCard(int positionX, int positionY, float objectWidth, float objectHeight, Color color = Color(0, 0, 0, 0));
	~BaseCard();
	void Draw(shared_ptr<RenderWindow> window) override;
};

