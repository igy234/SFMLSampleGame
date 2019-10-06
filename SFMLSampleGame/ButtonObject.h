#pragma once
#include "BaseGuiElement.h"
class ButtonObject : public BaseGuiElement, public ConvexShape
{
protected:
	const int Thickness = 2;
	void SetPoints();
	Text ButtonLabel;
public:
	virtual void SetWidth(float width) override;
	virtual void SetHeight(float height) override;
	virtual void SetPositionX(float x) override;
	virtual void SetPositionY(float y) override;
	virtual void SetPadding(float padding) override;
	Text& GetText();
public:
	ButtonObject(string label, int positionX, int positionY, float objectWidth, float objectHeight, shared_ptr<ICallback> callback = nullptr);
	~ButtonObject();
};

