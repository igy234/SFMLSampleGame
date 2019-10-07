#pragma once
#include "stdafx.h"
#include "IGuiElement.h"
#include "ButtonObject.h"

class ILayout
{
public:
	virtual void Show() = 0;
	virtual void ObtainVector(vector<shared_ptr<IGuiElement>> V) = 0;
	virtual void ObtainButtonsMap(map<string, shared_ptr<ButtonObject>> M) = 0;
	virtual void HandleMouseEvent(const Event& evnt) = 0;
};

