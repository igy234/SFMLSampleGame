#pragma once
#include "stdafx.h"
#include "IGuiElement.h"
#include "ButtonObject.h"
// interface for layout classes, holding display methods, and methods obtaining gui elements, also handling of mouse events
class ILayout
{
public:
	virtual void Show() = 0;
	virtual void ObtainVector(vector<shared_ptr<IGuiElement>> V) = 0;
	virtual void ObtainButtonsMap(map<string, shared_ptr<ButtonObject>> M) = 0;
	virtual void HandleMouseEvent(const Event& evnt) = 0;
};

