#include"stdafx.h"
#include "ColumnMaker.h"



ColumnMaker::ColumnMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column)
{
	WidthFactor = windowX / static_cast<int> (EnumScreenFields::COUNT);
	HeightFactor = windowY / static_cast<int> (EnumScreenFields::COUNT);
	FieldX = static_cast<int>(row) * WidthFactor;
	FieldY = static_cast<int>(column) * HeightFactor;
}

ColumnMaker::~ColumnMaker()
{
}

void ColumnMaker::OrganizePosition(const vector<reference_wrapper<BaseGuiElement>> &v) 
{
	int padding = 0;
	int LastHeight = 0;
	bool IsFirst = true;
	/*if (v.size())
	{
		v[0].get().SetPositionX(FieldX);
		padding += v[0].get().GetPadding();
		v[0].get().SetPositionY(FieldY + padding);
		LastHeight = v[0].get().GetHeight();
		auto iterator = v.cbegin() + 1;
		for (iterator; iterator != v.cend(); iterator++)
		{
			(*iterator).get().SetPositionX(FieldX);
			padding += (*iterator).get().GetPadding() + (*iterator).get().GetHeight() / 2 + LastHeight / 2;
			(*iterator).get().SetPositionY(FieldY + padding);
			LastHeight = (*iterator).get().GetHeight();
		}
	}*/
	FieldX= FieldX + WidthFactor / 2;
	for (reference_wrapper<BaseGuiElement> element : v)
	{
		element.get().SetPositionX(FieldX);
		if (IsFirst) 
		{
			padding += element.get().GetPadding(); 
			IsFirst = false; 
		}
		else padding += element.get().GetPadding() + element.get().GetHeight() / 2 + LastHeight / 2;

		element.get().SetPositionY(FieldY + padding);
		LastHeight = element.get().GetHeight();
	}
}