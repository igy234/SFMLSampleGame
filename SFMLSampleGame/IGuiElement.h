#pragma once
#include "stdafx.h"
///Interface for management of GuiElements 
class IGuiElement
{
public:
	///@brief getter for width  of the object
	///@returns width 
	virtual float GetWidth() = 0;

	///@brief getter for height of the object
	///@returns height 
	virtual float GetHeight() = 0;

	///@brief getter for position x of the object
	///@returns position x 
	virtual float GetPositionX() = 0;

	///@brief getter for position y of the object
	///@returns position y 
	virtual float GetPositionY() = 0;

	///@brief getter for padding of the object
	///@returns padding 
	virtual float GetPadding() = 0;

	///@brief setter for width of the object
	///@param "width" used to specify width
	virtual void SetWidth(float width) = 0;

	///@brief setter for height of the object
	///@param "height" used to specify height
	virtual void SetHeight(float height) = 0;

	///@brief setter for position x of the object
	///@param "x" used to specify position x 
	virtual void SetPositionX(float x) = 0;

	///@brief setter for position y of the object
	///@param "y" used to specify position y
	virtual void SetPositionY(float y) = 0;

	///@brief setter for padding of the object
	///@param "padding" used to specify padding
	virtual void SetPadding(float padding) = 0;

	///@brief showing error if callback is nullptr and performing action of given callback
	virtual void action() = 0;

	///@brief Seting Ishighlighted as true
	virtual void Highlight() = 0;

	///@brief Seting Ishighlighted as false
	virtual void Unhighlight() = 0;

	///@brief method used to draw content to program's window
	///@param "window" program's window
	virtual void Draw(shared_ptr<RenderWindow> window) = 0;

	///@brief geter for texture
	///@return texture
	virtual Texture GetTexture() = 0;

	///@brief getter for IsHighlighted attribute
	///@return true if object is highlighted, false if it is not
	virtual bool GetIsHighlighted() = 0;

	///@brief getter for IsUserInteractive attribute
	///@return true if object is user interactive, false if it is not
	virtual bool GetIsUserInteractive() = 0;

	///@brief setter for IsUserInteractive attribute
	///@param "interactive" used to specify if object is user interactive. 
	virtual void SetIsUserInteractive(bool interactive) = 0;

};

