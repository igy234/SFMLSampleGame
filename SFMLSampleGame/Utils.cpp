#include "stdafx.h"
#include "Utils.h"

tuple<int, int, int, int> CalcualteStartingPoint(int windowX, int windowY, EnumScreenFields column, EnumScreenFields row) //4 returns in one object in one place
{
	int WidthFactor = windowX / static_cast<int> (EnumScreenFields::COUNT); //width of single field
	int HeightFactor = windowY / static_cast<int> (EnumScreenFields::COUNT); //height of single field
	int FieldX = static_cast<int>(column) * WidthFactor; //starting point of field is basically number of field times fields size 
	int FieldY = static_cast<int>(row) * HeightFactor; //starting point of field is basically number of field times fields size
	return tuple<int, int, int, int>(FieldX, FieldY, WidthFactor, HeightFactor); 
}