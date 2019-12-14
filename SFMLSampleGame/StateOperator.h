#pragma once
#include "IStateOperator.h"

///Template class accepting any type of class as state parameter
template<typename T> //any class
class StateOperator : public IStateOperator<T>
{
protected:
	///holding any kind of State class as CurrentState atribute
	T CurrentState;
public:
	///@brief method setting new state 
	///@param "state" representing generic state of the program
	virtual void SetNewState(T state) override 
	{
		CurrentState = state;
	}
	///@brief method getting current state 
	///@returns generic state of the program
	virtual T GetCurrentState() override
	{
		return CurrentState;
	}
};

