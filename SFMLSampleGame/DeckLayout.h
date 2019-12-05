#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
#include "PreviewCard.h"
//class not used yet
class DeckLayout : public BaseLayout
{
protected:
	const int ThicknessShift = 2;
	const int Thickness = 2;
	const int PreviewPadding = 55;

	shared_ptr<RectangleObject> InfoRectangle;
	vector<shared_ptr<IGuiElement>> InfoVector; //holding rectangle with information about under developement info
	PreviewCard CardPreview; //holding  object of PreviewCard class responsible for managing card preview
	vector<RectangleObject> UiLines; //vecotr of rectangles creating UI lines

	vector<shared_ptr<IGuiElement>> FirstCardsVector;
	vector<shared_ptr<IGuiElement>> SecondCardsVector;
	vector<shared_ptr<IGuiElement>> ThirdCardsVector;
	vector<shared_ptr<IGuiElement>> FourthCardsVector;
public:
	void Show() override;
	DeckLayout(shared_ptr<RenderWindow> window);
	~DeckLayout();
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;
	//handling highlightning cardss, showing cardPreview if clicked
	void HandleMouseEvent(const Event& evnt) override;
};

