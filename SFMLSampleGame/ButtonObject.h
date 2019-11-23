#pragma once
#include "BaseGuiElement.h"
// ButtonObject class holding hardcoded otlinethickness of implemented convexshapes, text labels for buttons, managing the creation of buttons.
// holds setters and getters for buttons
class ButtonObject : public BaseGuiElement, public ConvexShape
{
protected:
	const int Thickness = 2;
	void SetPoints(); // settign points of convex shape, always depending of height and width of button
	Text ButtonLabel;
public:
	virtual void SetWidth(float width) override; //seting width, resetting points
	virtual void SetHeight(float height) override; //seting height, resetting points
	virtual void SetPositionX(float x) override;  //seting position for label, and buttons
	virtual void SetPositionY(float y) override; //seting position for label, and buttons
	virtual void SetPadding(float padding) override; //seting paddign
	virtual void Highlight() override; //changing laber color to red and changing Ishighlighted to true
	virtual void Unhighlight() override; //changing laber color to white and changing Ishighlighted to false
	virtual void Draw(shared_ptr<RenderWindow> window) override; // drawing components of object and text label
	Text& GetText(); 
public:
	void SetSpecialBackgroundColor(Color color);
	//setting label, convex and text centered in rectangle 
	ButtonObject(string label, int positionX, int positionY, float objectWidth, float objectHeight, shared_ptr<ICallback> callback = nullptr, int opacity = 50);
	~ButtonObject();
};

