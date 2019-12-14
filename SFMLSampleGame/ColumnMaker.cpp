#include"stdafx.h"
#include "ColumnMaker.h"
#include "Utils.h"


ColumnMaker::ColumnMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column)
{
	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(windowX, windowY, row, column); //extracts tuple to appropriate arguments in tie
}

ColumnMaker::~ColumnMaker()
{
}

void ColumnMaker::OrganizePosition(const vector<shared_ptr<IGuiElement>> &v) 
{
	int padding = StarterHeightPadding;
	int LastHeight = 0;
	bool IsFirst = true;
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