#pragma once
#include "BaseGuiElement.h"
class RectangleObject :	public BaseGuiElement, public RectangleShape
{
protected:
	Vector2f RectangleSize;
	optional<Text> Label;
public:
	virtual void SetWidth(float width) override;
	virtual void SetHeight(float height) override;
	virtual void SetPositionX(float x) override;
	virtual void SetPositionY(float y) override;
	virtual void Draw(shared_ptr<RenderWindow> window) override;
	RectangleObject(int positionX, int positionY, float objectWidth, float objectHeight, Color color = Color(0, 0, 0, 0), string text = "");
	RectangleObject() : RectangleObject(0, 0, 0, 0) {};
	~RectangleObject();
};

