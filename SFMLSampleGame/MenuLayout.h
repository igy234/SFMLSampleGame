#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
#include "ButtonObject.h"
/// Class managing the layout of window in the Menu state
class MenuLayout : public BaseLayout
{
public:
	///@brief method drawing background sprite and buttons in vector of gui elements
	void Show() override; 

	///@brief constructor loading the texture and setting it for sprite, ascribing window
	///@param "window" representing program's window
	MenuLayout(shared_ptr<RenderWindow> window); 
	~MenuLayout();

	///@brief gets the vecor of gui elements, sets it using columnmaker and holds it in GuiElements vector
	///@param "V" vector representing gui elements
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override; 
};

