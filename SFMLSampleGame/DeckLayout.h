#pragma once
#include "BaseLayout.h"
//class not used yet
class DeckLayout : public BaseLayout
{
public:
	void Show() override;
	DeckLayout(shared_ptr<RenderWindow> window);
	~DeckLayout();
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;
};

