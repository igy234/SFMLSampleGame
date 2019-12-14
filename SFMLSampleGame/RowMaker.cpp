#include "stdafx.h"
#include "RowMaker.h"
#include "Utils.h"

RowMaker::RowMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column)
{
	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(windowX, windowY, row, column); 
}


RowMaker::~RowMaker()
{
}

void RowMaker::OrganizePosition(const vector<shared_ptr<IGuiElement>> &v)
{
		
	int padding = StarterWidthPadding;
	for (auto element:v)
	{
		element->SetPositionY(FieldY + StarterHeightPadding);
		element->SetPositionX(FieldX + padding);
		padding += element->GetPadding() + element->GetWidth();
	}
}

void RowMaker::SetStarterWidthPadding(int padding)
{
	StarterWidthPadding = padding;
}

void RowMaker::SetStarterHeightPadding(int padding)
{
	StarterHeightPadding = padding;
}