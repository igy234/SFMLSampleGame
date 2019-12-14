#pragma once
#include "stdafx.h"
//start of existing at the begining of the program and end of existing at the end of the program
///Singleton class holding font 
class FontProvider 
{
private:
	///@brief constructor loading font from file and managing error message
	FontProvider();

	///holds font
	Font font;

public:
	///@brief creation of static instance of font provider
	///@return static instance of font provider
	static FontProvider& instance(); 

	///@brief getter for font
	///@return font attribute of the class
	Font& GetFont(); 
};

