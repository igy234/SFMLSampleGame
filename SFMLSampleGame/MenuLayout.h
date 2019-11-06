#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
#include "ButtonObject.h"
// Class managing the layout of window in the Menu state
class MenuLayout : public BaseLayout
{
protected: 
	
public:
	void Show() override; //method drawing background sprite and map of buttons
	MenuLayout(shared_ptr<RenderWindow> window); //loading the texture and setting it for sprite
	~MenuLayout();
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override; //gets the vecor of gui elements, sets it using columnmaker and holds it in GuiElements vector
};

