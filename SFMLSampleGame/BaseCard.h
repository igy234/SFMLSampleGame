#pragma once
#include "ICard.h"
#include "RectangleObject.h"
#include "ICardModel.h"


//base class for card entity, holding cards sprite, texture

class BaseCard : public RectangleObject 
{
protected:
	Texture CardTexture; 
	Sprite CardSprite;
	shared_ptr<ICardModel> Model;

public:
	virtual void SetWidth(float width) override; //seting width scale for sprite and width for rectangle
	virtual void SetHeight(float height) override; //seting height scale for sprite and height for rectangle
	virtual void SetPositionX(float x) override; //seting position for sprite and for rectangle
	virtual void SetPositionY(float y) override; //seting position for sprite and for rectangle
	virtual Texture GetTexture() override;  
	virtual void Highlight() override; // sets appropriate color of outlinethickness of card, and marks that base gui element is highlighted 
	virtual void Unhighlight() override; // removes outlinethickness of card, and marks that base gui element is unhighlighted

	// loading texture and setting it to sprite, rescalling it, default color implemented
	BaseCard(shared_ptr<ICardModel> model, int positionX = 0, int positionY = 0, float objectWidth = 163, float objectHeight = 185, Color color = Color(0, 0, 0, 0));
	~BaseCard();
	void Draw(shared_ptr<RenderWindow> window) override; // drawing appropriate components
};

