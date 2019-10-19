#include "stdafx.h"
#include "Utils.h"

tuple<int, int, int, int> CalcualteStartingPoint(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column) //2 returny w jednym obiekcie w jednym miejscu zwraca pare intów
{
	int WidthFactor = windowX / static_cast<int> (EnumScreenFields::COUNT);
	int HeightFactor = windowY / static_cast<int> (EnumScreenFields::COUNT);
	int FieldX = static_cast<int>(row) * WidthFactor;
	int FieldY = static_cast<int>(column) * HeightFactor;
	return tuple<int, int, int, int>(FieldX, FieldY, WidthFactor, HeightFactor);
}