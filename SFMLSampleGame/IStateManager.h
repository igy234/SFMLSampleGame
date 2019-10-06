#pragma once
#include "stdafx.h"

class IStateManager // to je interface 
{
public:
	virtual void HandleEvent(const Event& evnt) = 0; //virtual - do nadpisywania przez klasê która bedzie dziedziczyæ, 
													 //=0 poniewa¿ nie posiada cia³a, bo to interface 
	virtual void DrawWindowContents() = 0;
	virtual void HandleMouseEvent(const Event& evnt) = 0;
};

