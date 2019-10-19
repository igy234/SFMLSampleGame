#pragma once
#include "ILayout.h"
#include "IGuiElement.h"
class BaseLayout : public ILayout
{
protected:
	shared_ptr<RenderWindow> Window;
	Texture BackgroundTexture; //zmienic nazwe pozniej 
	Sprite BackgroundSprite;
	vector <shared_ptr<IGuiElement>> GuiElements;
	map<string, shared_ptr<ButtonObject>> ButtonObjectsMap;
public:
	virtual void Show() = 0;
	//void DivideScreen() override;
	BaseLayout(shared_ptr<RenderWindow> window);
	void ObtainVector(vector<shared_ptr<IGuiElement>> V) override;
	void ObtainButtonsMap(map<string, shared_ptr<ButtonObject>> M) override;
	void HandleMouseEvent(const Event& evnt) override;
	~BaseLayout();
};

