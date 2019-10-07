#pragma once
#include "BaseLayout.h"
#include "RectangleObject.h"
#include "ButtonObject.h"
class MenuLayout : public BaseLayout
{
protected: 
	
public:
	void Show() override;
	MenuLayout(shared_ptr<RenderWindow> window);
	~MenuLayout();
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;
};

