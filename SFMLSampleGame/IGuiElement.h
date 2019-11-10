#pragma once
#include "stdafx.h"
//interface for GuiElements holding getters, setters, hihghlighters and drawers
class IGuiElement
{
public:
	virtual float GetWidth() = 0;
	virtual float GetHeight() = 0;
	virtual float GetPositionX() = 0;
	virtual float GetPositionY() = 0;
	virtual float GetPadding() = 0;
	virtual void SetWidth(float width) = 0;
	virtual void SetHeight(float height) = 0;
	virtual void SetPositionX(float x) = 0;
	virtual void SetPositionY(float y) = 0;
	virtual void SetPadding(float padding) = 0;
	virtual void action() = 0;
	virtual void Highlight() = 0;
	virtual void Unhighlight() = 0;
	virtual void Draw(shared_ptr<RenderWindow> window) = 0;
	virtual Texture GetTexture() = 0;
	virtual bool GetIsHighlighted() = 0;
	virtual void setVisibility(bool visible) = 0;
	virtual bool GetIsUserInteractive() = 0;
	virtual void SetIsUserInteractive(bool interactive) = 0;

};

