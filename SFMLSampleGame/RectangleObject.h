#pragma once
#include "BaseGuiElement.h"


///Class representing rectangles and managing their creation. 
class RectangleObject :	public BaseGuiElement, public RectangleShape
{
protected:
	///vector representing size of the rectangle
	Vector2f RectangleSize;

	///holding optional text label for button
	optional<Text> Label;
public:

	///@brief seting width of rectangle
	///@param "width" specifying width 
	virtual void SetWidth(float width) override;

	///@brief seting height of rectangle
	///@param "height" specifying height 
	virtual void SetHeight(float height) override;

	///@brief method setting posiution x of rectangle and label(if has value)
	///@param "x" specifying position x 
	virtual void SetPositionX(float x) override; 

	///@brief method setting posiution y of rectangle and label(if has value)
	///@param "y" specifying position y 
	virtual void SetPositionY(float y) override;

	///@brief method drawing components of class and label if has value
	///@param "window" representing program's window
	virtual void Draw(shared_ptr<RenderWindow> window) override; 

	///@brief filling the inside of rectangle with color and setting isHighlighted to true
	virtual void Highlight() override; 

	///@brief filling the inside of rectangle with deafult color and setting isHighlighted to false
	virtual void Unhighlight() override; 

	///@breif setting text for rectangles label
	///@param "txt" string to be set
	void SetText(string txt);

	///@brief constructor creating gui elements and managing optional label assigned to them
	///@param "positionX" specifying position x 
	///@param "positionY" specifying position y 
	///@param "objectWidth" specifying width 
	///@param "objectHeight" specifying height 
	///@param "color" specifying color, default none
	///@param "text" specifying text, default none
	RectangleObject(int positionX, int positionY, float objectWidth, float objectHeight, Color color = Color(0, 0, 0, 0), string text = "");
	
	///@brief default empty constructor used in play layout
	RectangleObject() : RectangleObject(0, 0, 0, 0) {};
	~RectangleObject();
};

