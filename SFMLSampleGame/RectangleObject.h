#pragma once
#include "BaseGuiElement.h"

//Rectangle object holding its size, and labels
//has its own setters and getters along with highlightning and drawing.
class RectangleObject :	public BaseGuiElement, public RectangleShape
{
protected:
	Vector2f RectangleSize;
	optional<Text> Label;
public:
	virtual void SetWidth(float width) override;
	virtual void SetHeight(float height) override;
	virtual void SetPositionX(float x) override; //setting posiution of rectangle and label(if has value)
	virtual void SetPositionY(float y) override;  //setting posiution of rectangle and label(if has value)
	virtual void Draw(shared_ptr<RenderWindow> window) override; //drawing components of class and label if has value
	virtual void Highlight() override; //filling the inside of rectangle with color and setting isHighlighted to true
	virtual void Unhighlight() override; //deafult color and setting isHighlighted to false

	//creating gui elements and managing optional label assigned to them
	RectangleObject(int positionX, int positionY, float objectWidth, float objectHeight, Color color = Color(0, 0, 0, 0), string text = "");
	
	//default empty constructor used in play layout
	RectangleObject() : RectangleObject(0, 0, 0, 0) {};
	~RectangleObject();
};

