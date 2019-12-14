#pragma once
///Interface for callback classes 
class ICallback
{
public:
	///@brief method used to perform action's of given callbacks 
	virtual void action() = 0;
};

