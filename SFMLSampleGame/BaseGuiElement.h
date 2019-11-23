#pragma once
#include "IGuiElement.h"
#include "FontProvider.h"
#include "ICallback.h"

// Base class for most gui elements holding its parameters setters and getters
class BaseGuiElement : public IGuiElement
{
protected:
	int PositionX, PositionY; 
	float ObjectWidth, ObjectHeight, Padding=0;
	bool Visible = true;
	shared_ptr<ICallback> Callback = nullptr;  // Callbacks for state managers, at the beggining set to nullptr
	bool IsHighlighted=false; //at the begining none of the objects is highlighted 

public:
	bool IsUserInteractive = false;
	virtual float GetWidth() override;
	virtual float GetHeight() override;
	virtual float GetPositionX() override;
	virtual float GetPositionY() override;
	virtual float GetPadding() override;
	virtual void SetWidth(float width) override;
	virtual void SetHeight(float height) override;
	virtual void SetPositionX(float x) override;
	virtual void SetPositionY(float y) override;
	virtual void SetPadding(float padding) override;
	virtual void action() override; // showing error if callback is nullptr and performing action of given callback
	virtual void Highlight() override; //Seting Ishighlighted as true
	virtual void Unhighlight() override; //Seting Ishighlighted as false
	virtual bool GetIsHighlighted() override; 
	virtual void setVisibility(bool visible) override;
	virtual Texture GetTexture() override { return {}; }; //overriding for use in lower levels of inheritance
	virtual bool GetIsUserInteractive() override;
	virtual void SetIsUserInteractive(bool interactive) override;
	BaseGuiElement(int positionX, int positionY, float objectWidth, float objectHeight, shared_ptr<ICallback> callback = nullptr); //constructor with default callback set to nullptr
	~BaseGuiElement();


};

