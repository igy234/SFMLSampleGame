#pragma once
#include "stdafx.h"
// interface for state managers, event handling, drawing contents of window, handling mouse events
class IStateManager 
{
public:
	virtual void HandleEvent(const Event& evnt) = 0; 
	virtual void DrawWindowContents() = 0;
	virtual void HandleMouseEvent(const Event& evnt) = 0;
	virtual void initialize() = 0;
};

