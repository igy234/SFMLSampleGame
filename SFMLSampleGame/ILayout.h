#pragma once
#include "stdafx.h"
#include "IGuiElement.h"
#include "ButtonObject.h"
///Interface for management of layout classes
class ILayout
{
public:
	///@brief method used to set some of gui elements for current state of the program
	///@param "V" representing vector of elements to set
	virtual void SetGuiElementsForCurrentState(vector<shared_ptr<IGuiElement>> V) = 0;

	///@brief adding a single gui element to vector of elements for current state of the program
	///@param "E" single gui element
	virtual void AddGuiElementToCurrentState(shared_ptr<IGuiElement> E) = 0;

	///@brief method managing drawning of contents
	virtual void Show() = 0;

	///@brief obtains vector of gui elements
	///@param "V" vector of gui elements 
	virtual void ObtainVector(vector<shared_ptr<IGuiElement>> V) = 0;

	///@brief method handling mouse movement, highlighting gui elements and calling callbacks for state managers
	///@param "evnt" parameter describing event type for mouse handling
	virtual void HandleMouseEvent(const Event& evnt) = 0;

};

