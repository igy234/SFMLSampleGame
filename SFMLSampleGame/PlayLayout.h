#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
#include "PreviewCard.h"
#include "IStateManager.h"

/// Class managing the layout of window in the Play state
class PlayLayout : public BaseLayout
{
protected:
	///hardcoded position shift resulting from outline thickness od gui elements
	const int ThicknessShift =  2;

	///outline thickness od gui elements
	const int Thickness = 2;

	///attribute representing padding for object of PreviewCard class 
	const int PreviewPadding = 55;


	///holding  object of PreviewCard class responsible for managing card preview
	PreviewCard CardPreview; 

	///vecotr of rectangles creating UI lines
	vector<RectangleObject> UiLines; 

	///vector holding cards in user's hand
	shared_ptr<vector<shared_ptr<IGuiElement>>> UserHandCards;

	///vector holding cards in user's lower battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> UserLowerBattlefieldCards;

	///vector holding cards in user's upper battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> UserUpperBattlefieldCards;

	///vector holding cards in AI's lower battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> EnemyLowerBattlefieldCards;

	///vector holding cards in AI's upper battlefield
	shared_ptr<vector<shared_ptr<IGuiElement>>> EnemyUpperBattlefieldCards; 

	///representing current state of the program
	shared_ptr<IStateManager>& CurrentManager;

	///vector holding gui elements which only purpose is to be drawn
	shared_ptr<vector<shared_ptr<IGuiElement>>> DrawOnlyVector;
public:

	///@brief method drawing all gui elements to window
	void Show() override;
	
	///@brief constructor ascribing values to class attributes, loading background texture, creation of all gui elements used in play state and setting their postion
	///@param "window" representing program's window
	///@param "userHandCards" representing cards in user's hand
	///@param "currentManager" representing current state of the program
	PlayLayout(shared_ptr<RenderWindow> window, shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards,
		shared_ptr<IStateManager>& currentManager); 
	
	~PlayLayout();
	
	///@brief method handling highlightning cards and battlefields, showing card's preview if clicked
	///@param "evnt" parameter describing event type for mouse handling
	void HandleMouseEvent(const Event& evnt) override;

	///@brief obtaing vector of gui elements and saving them for later use
	///@param "V" representing vector of elements to be saved for later
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override; 

	///@brief getter for DrawOnlyVector
	///@returns vector of elements which only purpose is to be drawn
	shared_ptr<vector<shared_ptr<IGuiElement>>> GetDrawOnlyContents();

	///@brief setter for UserLowerBattlefieldCards attribute
	///@param "cards" vector representing cards to be set
	void SetLowerUserBattlefieldCards(shared_ptr<vector<shared_ptr<IGuiElement>>> cards);

	///@brief setter for UserUpperBattlefieldCards attribute
	///@param "cards" vector representing cards to be set
	void SetUpperUserBattlefieldCards(shared_ptr<vector<shared_ptr<IGuiElement>>> cards);

	///@brief setter for EnemyLowerBattlefieldCards attribute
	///@param "cards" vector representing cards to be set
	void SetLowerEnemyBattlefieldCards(shared_ptr<vector<shared_ptr<IGuiElement>>> cards);

	///@brief setter for EnemyUpperBattlefieldCards attribute
	///@param "cards" vector representing cards to be set
	void SetUpperEnemyBattlefieldCards(shared_ptr<vector<shared_ptr<IGuiElement>>> cards);
};

