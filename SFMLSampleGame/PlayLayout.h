#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
class PlayLayout : public BaseLayout
{
protected:
	const int ThicknessShift =  2;
	const int Thickness = 2;
	void SetPoints() {};
	RectangleObject BackDrop;
	RectangleObject ScoreRectangle;
	RectangleObject HandRectangle;
	RectangleObject UpperOponentRectangle;
	RectangleObject LowerOponentRectangle;
	RectangleObject UpperPlayerRectangle;
	RectangleObject LowerPlayerRectangle;
	RectangleObject PreviewCardRectangle;
public:
	void Show() override;
	PlayLayout(shared_ptr<RenderWindow> window);
	~PlayLayout();
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;
};

