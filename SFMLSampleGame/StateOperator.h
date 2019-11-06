#pragma once
#include "IStateOperator.h"

//template class accepting any type of class as state parameter, and returning any type of class in getter
//holding any kind of State class as CurrentState atribute
template<typename T> //any class
class StateOperator : public IStateOperator<T>
{
protected:
	T CurrentState;
public:
	virtual void SetNewState(T state) override 
	{
		CurrentState = state;
	}
	virtual T GetCurrentState() override
	{
		return CurrentState;
	}
};

