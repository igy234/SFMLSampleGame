#pragma once
#include "IGuiElement.h"
#include "FontProvider.h"
#include "ICallback.h"
class BaseGuiElement : public IGuiElement
{
protected:
	int PositionX, PositionY;
	float ObjectWidth, ObjectHeight, Padding;
	bool Visible = true;
	shared_ptr<ICallback> Callback = nullptr; // na dzieñ dobry wszystkie wynulowane
	bool IsHighlighted=false;

public:
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
	virtual void action() override;
	virtual void Highlight() override;
	virtual void Unhighlight() override;
	virtual bool GetIsHighlighted() override;
	virtual Texture GetTexture() override { return {}; };
	BaseGuiElement(int positionX, int positionY, float objectWidth, float objectHeight, shared_ptr<ICallback> callback = nullptr);
	~BaseGuiElement();


};

