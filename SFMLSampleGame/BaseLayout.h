#pragma once
#include "ILayout.h"
#include "IGuiElement.h"

///Base class managing layout of the window.
class BaseLayout : public ILayout
{
protected:
	///holding shared pointer to window
	shared_ptr<RenderWindow> Window;

	///holding background texture
	Texture BackgroundTexture; 

	///holding spirte
	Sprite BackgroundSprite;

	///Vector holding GuiElements
	vector <shared_ptr<IGuiElement>> GuiElements;

	///vector holding gui elements used in current state
	vector <shared_ptr<IGuiElement>> GuiElemtnsForCurrentState;

public:
	///@brief method managing drawning of contents
	virtual void Show() = 0;

	///@biref constructor
	///@param "window" window of the program
	BaseLayout(shared_ptr<RenderWindow> window);

	///@brief obtains vector of gui elements
	///@param "V" vector of gui elements 
	virtual void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;

	///@brief method handling mouse movement, highlighting gui elements and calling callbacks for state managers
	///@param "evnt" parameter describing event type for mouse handling
	virtual void HandleMouseEvent(const Event& evnt) override; 

	///@brief setter for vector of gui elements for current state of the program
	///@param "V" vector of gui elements 
	virtual void SetGuiElementsForCurrentState(vector<shared_ptr<IGuiElement>> V) override;

	///@brief adding a single gui element to vector of elements for current state
	///@param "E" single gui element
	virtual void AddGuiElementToCurrentState(shared_ptr<IGuiElement> E) override; 
	~BaseLayout();
};

