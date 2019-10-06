#include "stdafx.h"
#include "FontProvider.h"



FontProvider::FontProvider()
{
	if (!font.loadFromFile("Resources/Fonts/GWINT_Font.ttf"))
	{
		cerr << "Error while loading font" << endl; //error handling
		system("pause");

	}
}


FontProvider& FontProvider::instance()
{
	static FontProvider INSTANCE;
	return INSTANCE;
}

Font& FontProvider::GetFont()
{
	return font;
}