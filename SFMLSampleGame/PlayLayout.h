#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
#include "PreviewCard.h"
#include "IStateManager.h"

//Class managing the play state layout
//holding OutlineThicnkess, and shif of the guielements resultig from mentioned thickness.

class PlayLayout : public BaseLayout
{
protected:
	const int ThicknessShift =  2;
	const int Thickness = 2;
	const int PreviewPadding = 55;

	PreviewCard CardPreview; //holding  object of PreviewCard class responsible for managing card preview
	vector<RectangleObject> UiLines; //vecotr of rectangles creating UI lines
	shared_ptr<vector<shared_ptr<IGuiElement>>> UserHandCards; //vector holding cards in user's hand
	//vector<shared_ptr<IGuiElement>> TurnAndCardsInformationRectangles; //vector holding rectangles with information about how many cards does an AI has and who's turn is durring match
	shared_ptr<IStateManager>& CurrentManager;
	shared_ptr<vector<shared_ptr<IGuiElement>>> DrawOnlyVector;
public:
	//method drawing all gui elements
	void Show() override;
	
	// loading background texture, creation of all gui elements used in play state and setting their postion
	PlayLayout(shared_ptr<RenderWindow> window, shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards, shared_ptr<IStateManager>& currentManager); //vector holding cards in user's hand);
	
	~PlayLayout();
	
	//handling highlightning cards and battlefields, showing cardPreview if clicked
	void HandleMouseEvent(const Event& evnt) override;

	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override; //obtaing vector of gui elements and puuting them below each other by using columnmaker
	shared_ptr<vector<shared_ptr<IGuiElement>>> GetDrawOnlyContents();
};

