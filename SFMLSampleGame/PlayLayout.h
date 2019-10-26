#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
class PlayLayout : public BaseLayout
{
protected:
	const int ThicknessShift =  2;
	const int Thickness = 2;
	void SetPoints() {};
	vector<RectangleObject> UiLines;
	vector<shared_ptr<IGuiElement>> UserHandCards;
	vector<shared_ptr<IGuiElement>> EnemyHandCards;
	vector<shared_ptr<IGuiElement>> TurnAndCardsInformationRectangles;
public:
	void Show() override;
	PlayLayout(shared_ptr<RenderWindow> window);
	~PlayLayout();
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;
};

