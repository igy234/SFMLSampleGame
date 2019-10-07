#pragma once
#include "stdafx.h"

class Menu
{
public:
	Menu(const float& width, const float& height);
	~Menu();
	
	void drawBackground(RenderWindow &window);
private: 
	Texture MenuTexture;
	Sprite MenuBackgorund;
	

};




