#pragma once
#include "BaseStateManager.h"
#include "DeckLayout.h"
#include "EnumGalleryPages.h"
///Class managing the Deck(Gallery) state of the program
class DeckStateManager : public BaseStateManager
{
protected:
	///shared pointer to Deck Layout object managing the layout in this state
	shared_ptr<DeckLayout> deckLayout;

	///shared pointer to enum type representing two gallery pages
	shared_ptr<CardsPage> Page;

public:
	///@brief method responsible for handling events in this state
	///@param "evnt" parameter describing event type for event handling
	void HandleEvent(const Event& evnt) override;

	///@brief method calling layout to draw window's contents for current state
	void DrawWindowContents() override;

	///@brief method calling layout to handle its mouse events
	///@param "evnt" parameter describing event type for mouse handling
	void HandleMouseEvent(const Event& evnt) override;

	///@brief constructor ascribing window and current manager, creating redirecting to other states and gallery switching buttons, organizing position of buttons, saving gui elements.
	///@param "window" representing program's window
	///@param "currentManager" representing state of the program
	DeckStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager);
	~DeckStateManager();
};

