#pragma once
#include "IStateManager.h"
#include "IStateOperator.h"

///Base class for state managers 
class BaseStateManager : public IStateManager
{
protected:
	///shared pointer to the program's window
	shared_ptr<RenderWindow> Window; //shared_ptr is a class with memory automenagement (new and delete)
public:
	template <typename T>
	///@brief generic constructor for creating reusable state management classes
	///@param "window" program's window
	///@param "currentManger" generic state manager
	BaseStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<T>> currentManager) : Window(window) {}

	///@brief method responsible for handling events in given states
	///@param "evnt" parameter describing event type for event handling
	void HandleEvent(const Event& evnt) = 0;

	///@brief method calling layouts' show() method to draw contents to the window
	void DrawWindowContents() = 0;

	///@brief method responsible for handling mouse events in given states
	///@param "evnt" parameter describing event type for mouse handling
	void HandleMouseEvent(const Event& evnt) = 0;

	///@brief method performing starting actions of given state
	virtual void initialize() {};
};

