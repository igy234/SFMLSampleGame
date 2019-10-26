#include "stdafx.h"
#include "Utils.h"

tuple<int, int, int, int> CalcualteStartingPoint(int windowX, int windowY, EnumScreenFields column, EnumScreenFields row) //4 returny w jednym obiekcie w jednym miejscu zwraca pare intów
{
	int WidthFactor = windowX / static_cast<int> (EnumScreenFields::COUNT);
	int HeightFactor = windowY / static_cast<int> (EnumScreenFields::COUNT);
	int FieldX = static_cast<int>(column) * WidthFactor;
	int FieldY = static_cast<int>(row) * HeightFactor;
	return tuple<int, int, int, int>(FieldX, FieldY, WidthFactor, HeightFactor);
}