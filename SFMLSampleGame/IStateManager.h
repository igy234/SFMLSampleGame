#pragma once
#include "stdafx.h"
///Interface for state managers
class IStateManager 
{
public:
	///@brief method responsible for handling events in given states
	///@param "evnt" parameter describing event type for event handling
	virtual void HandleEvent(const Event& evnt) = 0; 

	///@brief method calling layouts' show() method to draw contents to the window
	virtual void DrawWindowContents() = 0;

	///@brief method responsible for handling mouse events in given states
	///@param "evnt" parameter describing event type for mouse handling
	virtual void HandleMouseEvent(const Event& evnt) = 0;

	///@brief method performing starting actions of given state
	virtual void initialize() = 0;
};

