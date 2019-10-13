#pragma once
#include "BaseLayout.h"
class PlayLayout : public BaseLayout
{
public:
	void Show() override;
	PlayLayout(shared_ptr<RenderWindow> window);
	~PlayLayout();
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;
};

