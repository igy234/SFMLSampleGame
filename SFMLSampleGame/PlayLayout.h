#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
#include "PreviewCard.h"
class PlayLayout : public BaseLayout
{
protected:
	const int ThicknessShift =  2;
	const int Thickness = 2;
	const float HalfScale = 0.5f;
	const int PreviewPadding = 55;
	Texture CardPreviewTexture;
	Sprite CardPreviewSprite;
	PreviewCard CardPreview;
	vector<RectangleObject> UiLines;
	vector<shared_ptr<IGuiElement>> UserHandCards;
	vector<shared_ptr<IGuiElement>> EnemyHandCards;
	vector<shared_ptr<IGuiElement>> TurnAndCardsInformationRectangles;
public:
	void Show() override;
	PlayLayout(shared_ptr<RenderWindow> window);
	~PlayLayout();
	void HandleMouseEvent(const Event& evnt) override;
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;
};

