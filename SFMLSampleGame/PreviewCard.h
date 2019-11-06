#pragma once
#include "BaseGuiElement.h"

//Class managing the preview card operations
//holding hardcoded scale coefficient
//holding preview texture and sprite
class PreviewCard :	public BaseGuiElement
{
protected:
	const float HalfScale = 0.5f;
	//const int PreviewPadding = 55;
	Texture CardPreviewTexture;
	Sprite CardPreviewSprite;

public:
	PreviewCard(int positionX, int positionY, float objectWidth, float objectHeight); //seting position of sprite and its scale
	~PreviewCard();
	virtual void Draw(shared_ptr<RenderWindow> window) override; //drawing card preview sprite
	virtual Texture GetTexture() override; 
	virtual void SetPositionX(float x) override;
	virtual void SetPositionY(float y) override;
	void SetTexture(Texture PreviewTexture);
};

