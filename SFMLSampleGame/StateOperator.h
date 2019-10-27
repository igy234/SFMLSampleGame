#pragma once
#include "IStateOperator.h"


template<typename T> //dowolna klasa
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

