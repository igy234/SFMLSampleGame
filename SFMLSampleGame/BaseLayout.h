#pragma once
#include "ILayout.h"
class BaseLayout : public ILayout
{
protected:
	//int WindowX;
	//int WindowY;
	shared_ptr<RenderWindow> Window;
	int WidthFactor;
	int HeightFactor;
	Texture MenuTexture; //zmienic nazwe pozniej 
	Sprite MenuBackgorund;
public:
	virtual void Show() = 0;
	//void DivideScreen() override;
	BaseLayout(shared_ptr<RenderWindow> window);
	~BaseLayout();
};

