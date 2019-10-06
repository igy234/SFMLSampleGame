#pragma once
#include "BaseGuiElement.h"
class RectangleObject :	public BaseGuiElement, public RectangleShape
{
protected:
	Vector2f RectangleSize;
public:
	virtual void SetWidth(float width) override;
	virtual void SetHeight(float height) override;
	virtual void SetPositionX(float x) override;
	virtual void SetPositionY(float y) override;
	RectangleObject(int positionX, int positionY, float objectWidth, float objectHeight);
	~RectangleObject();
};

