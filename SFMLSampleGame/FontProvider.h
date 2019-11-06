#pragma once
#include "stdafx.h"
//start of existing at the begining of the program and end of existing at the end of the program
//singleton holding font 
class FontProvider 
{
private:
	FontProvider(); //loading font from file
	Font font;

public:
	static FontProvider& instance(); //creation of static Instance and return of it 
	Font& GetFont(); //getter for font
};

