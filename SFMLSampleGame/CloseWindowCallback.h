#pragma once
#include "stdafx.h"
#include "ICallback.h"
///Callback class responsible for window closing
class CloseWindowCallback : public ICallback 
{
private:
	///shared pointer to program's window
	shared_ptr<RenderWindow> Window; 
public:
	///@brief method closing the window
	void action() override; 

	///@brief constructor ascribing window
	///@param "window" representing program's window
	CloseWindowCallback(shared_ptr<RenderWindow> window);
	
};

