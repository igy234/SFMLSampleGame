#pragma once
#include "stdafx.h"

#define MAX_NUMBER_OF_ITEMS 3

class Button : public Drawable
{
public:
	Button(string description, float t_x, float t_y);
	Button() = delete; //usuwamy domyœlny ¿eby zrobiæ swój
	~Button() = default;
	int GetPressedItem() { return selectedItemIndex; }
	void HighlightButton(int x, int y); 
	void HighlightControl(int x, int y); 
	int MouseClickedInRange(int x, int y); 
	void MoveUp();
	void MoveDown();
	void draw(RenderTarget& target, RenderStates state) const override;
	void drawTexts(RenderWindow &window);

private:
	float ButtonWidth = 275;
	float ButtonHeight = 50;
	float ButtonPadding = 25; //odstep miedzy guzikami 
	Font font;
	
	Text menuTexts[MAX_NUMBER_OF_ITEMS];
	int selectedItemIndex;
	ConvexShape convex;
	Texture BtnTexture;
	const int Thickness = 2;
	bool HighlightCtrl = true;
};

