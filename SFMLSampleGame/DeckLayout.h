#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
//class not used yet
class DeckLayout : public BaseLayout
{
	shared_ptr<RectangleObject> UnderDevelopementRectangle;
	vector<shared_ptr<IGuiElement>> UnderDevelopementVector; //holding rectangle with information about under developement info
public:
	void Show() override;
	DeckLayout(shared_ptr<RenderWindow> window);
	~DeckLayout();
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;
};

