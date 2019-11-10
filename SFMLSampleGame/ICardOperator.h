#pragma once
#include "stdafx.h"
#include "IGuiElement.h"
class ICardOperator
{
public: 
	virtual void PerformCardOperation(shared_ptr<IGuiElement> card) = 0;
};
