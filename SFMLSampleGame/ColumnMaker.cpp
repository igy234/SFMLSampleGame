#include"stdafx.h"
#include "ColumnMaker.h"
#include "Utils.h"


ColumnMaker::ColumnMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column)
{
	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(windowX, windowY, row, column); //wypakowuje tupla do poszczegolnych wartosci ktore s¹ w tie
}

ColumnMaker::~ColumnMaker()
{
}

void ColumnMaker::OrganizePosition(const vector<shared_ptr<IGuiElement>> &v) 
{
	int padding = StarterHeightPadding;
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
	FieldX = FieldX + WidthFactor / 2;
	for (auto element : v)
	{
		element->SetPositionX(FieldX);
		if (IsFirst) 
		{
			padding += element->GetPadding();
			IsFirst = false; 
		}
		else padding += element->GetPadding() + element->GetHeight() / 2 + LastHeight / 2;

		element->SetPositionY(FieldY + padding);
		LastHeight = element->GetHeight();
	}

	
}

void ColumnMaker::SetStarterWidthPadding(int padding)
{
	StarterWidthPadding = padding;
}

void ColumnMaker::SetStarterHeightPadding(int padding)
{
	StarterHeightPadding = padding;
}