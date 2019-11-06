#pragma once
#include "stdafx.h"
#include "ICallback.h"
//Callback class fot window closing
class CloseWindowCallback : public ICallback 
{
private:
	shared_ptr<RenderWindow> Window; 
public:
	void action() override;  //method performing closing of the window
	CloseWindowCallback(shared_ptr<RenderWindow> window);
	
};

