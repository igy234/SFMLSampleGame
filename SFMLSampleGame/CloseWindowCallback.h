#pragma once
#include "stdafx.h"
#include "ICallback.h"
class CloseWindowCallback : public ICallback 
{
private:
	shared_ptr<RenderWindow> Window; //shared ptr to klasa z auto managerowaniem pamiecia (new i delette)
public:
	void action() override;
	CloseWindowCallback(shared_ptr<RenderWindow> window);
	
};

