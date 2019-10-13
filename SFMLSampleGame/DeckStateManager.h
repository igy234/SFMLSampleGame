#pragma once
#include "BaseStateManager.h"
#include "DeckLayout.h"
class DeckStateManager : public BaseStateManager
{
protected:
	DeckLayout deckLayout;

public:
	void HandleEvent(const Event& evnt) override;
	void DrawWindowContents() override;
	void HandleMouseEvent(const Event& evnt) override;
	DeckStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager);
	~DeckStateManager();
};

