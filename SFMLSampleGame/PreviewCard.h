#pragma once
#include "BaseGuiElement.h"
class PreviewCard :	public BaseGuiElement
{
protected:
	const float HalfScale = 0.5f;
	const int PreviewPadding = 55;
	Texture CardPreviewTexture;
	Sprite CardPreviewSprite;

public:
	PreviewCard(int positionX, int positionY, float objectWidth, float objectHeight);
	~PreviewCard();
	virtual void Draw(shared_ptr<RenderWindow> window) override;
	virtual Texture GetTexture() override;
	virtual void SetPositionX(float x) override;
	virtual void SetPositionY(float y) override;
	void SetTexture(Texture PreviewTexture);
};

