#pragma once
#include "BaseGuiElement.h"
///Class representing buttons and managing their creation. 
class ButtonObject : public BaseGuiElement, public ConvexShape
{
protected:
	///holding hardcoded outlinethickness of implemented convexshapes
	const int Thickness = 2;

	///@brief setting points of convex shape, always depending on height and width of button
	void SetPoints(); 

	///holding text label for button
	Text ButtonLabel;
public:
	///@brief seting width of button, resetting points
	///@param "width" specifying width 
	virtual void SetWidth(float width) override;

	///@brief seting height of button, resetting points
	///@param "height" specifying height 
	virtual void SetHeight(float height) override; 

	///@brief seting position x of button and label
	///@param "x" specifying position x 
	virtual void SetPositionX(float x) override;  

	///@brief seting position y of button and label
	///@param "y" specifying position y 
	virtual void SetPositionY(float y) override;

	///@brief setter for button's pading
	///@param "padding" specifying padding
	virtual void SetPadding(float padding) override; 

	///@brief method changing laber color to red and changing Ishighlighted to true
	virtual void Highlight() override; 

	///@brief method changing laber color to white and changing Ishighlighted to false
	virtual void Unhighlight() override; 

	///@brief method drawing components of button and its text label
	///@param "window" program's window
	virtual void Draw(shared_ptr<RenderWindow> window) override; 

	///@brief getter for text 
	///@return text used in button label
	Text& GetText(); 
public:
	///@brief method setting background color of the button
	///@param "color" specifying the color
	void SetSpecialBackgroundColor(Color color);

	///@brief constructor setting label, button's opacity, convex shape position and dimensions, text centered in rectangle of the button. Marking that buttons are user interactive
	///@param "label" button's string
	///@param "positionX" button's position x
	///@param "positionY" button's position y
	///@param "objectWidth" button's width
	///@param "objectHeight" button's height
	///@param "callback" button's callback
	///@param "opacity" button's opacity
	ButtonObject(string label, int positionX, int positionY, float objectWidth, float objectHeight, shared_ptr<ICallback> callback = nullptr, int opacity = 50);
	~ButtonObject();
};

