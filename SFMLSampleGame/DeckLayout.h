#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
#include "PreviewCard.h"
#include "EnumGalleryPages.h"
///Class representing the window's layout for Deck state of the game
class DeckLayout : public BaseLayout
{
protected:
	///hardcoded position shift resulting from outline thickness od gui elements
	const int ThicknessShift = 2;

	///outline thickness od gui elements
	const int Thickness = 2;

	///attribute representing padding for object of PreviewCard class 
	const int PreviewPadding = 55;
	
	///shared pointer to enum type representing two gallery pages
	shared_ptr<CardsPage> Page;

	///rectaangle providing information of what to do in this state of the game
	shared_ptr<RectangleObject> InfoRectangle;

	///vector holding InfoRectangle
	vector<shared_ptr<IGuiElement>> InfoVector; 

	///holding  object of PreviewCard class responsible for managing card preview
	PreviewCard CardPreview; 

	///vecotr of rectangles creating UI lines
	vector<RectangleObject> UiLines; 

	///vector holding first 5 cards in the gallery
	vector<shared_ptr<IGuiElement>> FirstCardsVector;

	///vector holding second 5 cards in the gallery
	vector<shared_ptr<IGuiElement>> SecondCardsVector;

	///vector holding third 5 cards in the gallery
	vector<shared_ptr<IGuiElement>> ThirdCardsVector;

	///vector holding fourth 5 cards in the gallery
	vector<shared_ptr<IGuiElement>> FourthCardsVector;

	///vector holding fifth 5 cards in the gallery
	vector<shared_ptr<IGuiElement>> FifthCardsVector;

	///vector holding last card in the gallery
	vector<shared_ptr<IGuiElement>>	SixthCardsVector;

public:

	///@brief method drawing contents to the program's window
	void Show() override;

	///@brief constructor loading background texture, creating gui elements for current lauoyt, filling CardVectors with cards and organizig their positions
	///@param "window" representing program's window 
	///@param "page" representing gallery's pages
	DeckLayout(shared_ptr<RenderWindow> window, shared_ptr<CardsPage> page);
	~DeckLayout();

	///@brief method saving vector of gui elements for later use
	///@param "V" vector representing saved gui elemtns
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;
	
	///@brief handling highlightning cards, showing cardPreview if clicked
	///@param "evnt" parameter describing event type for mouse handling
	void HandleMouseEvent(const Event& evnt) override;
};

