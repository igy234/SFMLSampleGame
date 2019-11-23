#pragma once
#include "ILayout.h"
#include "IGuiElement.h"

// Base layout of window holding window, background texture and spirte. Vector of GuiElements and map of buttons
class BaseLayout : public ILayout
{
protected:
	shared_ptr<RenderWindow> Window;
	Texture BackgroundTexture; 
	Sprite BackgroundSprite;
	vector <shared_ptr<IGuiElement>> GuiElements;
	map<string, shared_ptr<ButtonObject>> ButtonObjectsMap;
	vector <shared_ptr<IGuiElement>> GuiElemtnsForCurrentState;
public:
	virtual void Show() = 0;
	BaseLayout(shared_ptr<RenderWindow> window);
	virtual void ObtainVector(vector<shared_ptr<IGuiElement>> V) override; // obtains vector of gui elements
	virtual void HandleMouseEvent(const Event& evnt) override; //handling mouse movement (highlighting gui elements and calling callbacks for state managers)
	virtual void SetGuiElementsForCurrentState(vector<shared_ptr<IGuiElement>> V) override;
	virtual void AddGuiElementToCurrentState(shared_ptr<IGuiElement> E) override;
	~BaseLayout();
};

