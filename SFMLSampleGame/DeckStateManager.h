#pragma once
#include "BaseStateManager.h"
#include "DeckLayout.h"
#include "EnumGalleryPages.h"
//class not used yet
class DeckStateManager : public BaseStateManager
{
protected:
	shared_ptr<DeckLayout> deckLayout;
	shared_ptr<CardsPage> Page;

public:
	void HandleEvent(const Event& evnt) override;
	void DrawWindowContents() override;
	void HandleMouseEvent(const Event& evnt) override;
	DeckStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager);
	~DeckStateManager();
};

