#pragma once
#include "stdafx.h"
#include "IGuiElement.h"
#include "ButtonObject.h"
// interface for layout classes, holding display methods, and methods obtaining gui elements, also handling of mouse events
class ILayout
{
public:
	virtual void SetGuiElementsForCurrentState(vector<shared_ptr<IGuiElement>> V) = 0;
	virtual void AddGuiElementToCurrentState(shared_ptr<IGuiElement> E) = 0;
	virtual void Show() = 0;
	virtual void ObtainVector(vector<shared_ptr<IGuiElement>> V) = 0;
	virtual void HandleMouseEvent(const Event& evnt) = 0;

};

