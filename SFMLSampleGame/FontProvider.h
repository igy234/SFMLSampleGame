#pragma once
#include "stdafx.h"

class FontProvider //poczatek zycia na poczatku programu koniec na koncu
{
private:
	FontProvider();
	Font font;

public:
	static FontProvider& instance();
	Font& GetFont();
};

