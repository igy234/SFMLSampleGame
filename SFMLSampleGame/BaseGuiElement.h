#pragma once
#include "IGuiElement.h"
#include "FontProvider.h"
#include "ICallback.h"

///Base class for most gui elements holding their parameters setters and getters
class BaseGuiElement : public IGuiElement
{
protected:
	///x position in windows coordinate axis
	int PositionX;

	///y position in windows coordinate axis
	int PositionY;

	///width of gui element 
	float ObjectWidth;

	///height of gui element 
	float ObjectHeight;

	///default padding of gui element
	float Padding = 0;

	///Callback for state managers, at the beggining set to nullptr
	shared_ptr<ICallback> Callback = nullptr; 

	///atribute marking if object is highlithted, at the begining none of the objects is highlighted 
	bool IsHighlighted = false;;

public:
	///atribute marking if object is interactive for user
	bool IsUserInteractive = false; 
	///@brief getter for width  of the object
	///@returns width 
	virtual float GetWidth() override;

	///@brief getter for height of the object
	///@returns height 
	virtual float GetHeight() override;

	///@brief getter for position x of the object
	///@returns position x 
	virtual float GetPositionX() override;

	///@brief getter for position y of the object
	///@returns position y 
	virtual float GetPositionY() override;

	///@brief getter for padding of the object
	///@returns padding 
	virtual float GetPadding() override;

	///@brief setter for width of the object
	///@param "width" used to specify width
	virtual void SetWidth(float width) override;

	///@brief setter for height of the object
	///@param "height" used to specify height
	virtual void SetHeight(float height) override;

	///@brief setter for position x of the object
	///@param "x" used to specify position x 
	virtual void SetPositionX(float x) override;

	///@brief setter for position y of the object
	///@param "y" used to specify position y
	virtual void SetPositionY(float y) override;

	///@brief setter for padding of the object
	///@param "padding" used to specify padding
	virtual void SetPadding(float padding) override;

	///@brief showing error if callback is nullptr and performing action of given callback
	virtual void action() override;

	///@brief Seting Ishighlighted as true
	virtual void Highlight() override; 
	
	///@brief Seting Ishighlighted as false
	virtual void Unhighlight() override; 

	///@brief getter for IsHighlighted attribute
	///@return true if object is highlighted, false if it is not
	virtual bool GetIsHighlighted() override; 
	
	///@brief geter for texture - overrided for use in lower levels of inheritance
	///@return texture
	virtual Texture GetTexture() override { return {}; }; 

	///@brief getter for IsUserInteractive attribute
	///@return true if object is user interactive, false if it is not
	virtual bool GetIsUserInteractive() override;

	///@brief setter for IsUserInteractive attribute
	///@param "interactive" used to specify if object is user interactive. 
	virtual void SetIsUserInteractive(bool interactive) override;

	///@brief constructor with default callback set to nullptr
	///@param "positionX" x position of the object
	///@param "positionY" y position of the object
	///@param "objectWidth" width of the object
	///@param "objectHeight" height of the object
	///@param "callback" callback of the object
	BaseGuiElement(int positionX, int positionY, float objectWidth, float objectHeight, shared_ptr<ICallback> callback = nullptr); 
	~BaseGuiElement();
};

