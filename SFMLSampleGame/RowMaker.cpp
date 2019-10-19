#include "stdafx.h"
#include "RowMaker.h"
#include "Utils.h"

RowMaker::RowMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column)
{
	int widthFactor, heightFactor;
	tie(FieldX, FieldY, widthFactor, heightFactor) = CalcualteStartingPoint(windowX, windowY, row, column); //wypakowuje tupla do poszczegolnych wartosci ktore s¹ w tie
}


RowMaker::~RowMaker()
{
}

void RowMaker::OrganizePosition(const vector<shared_ptr<IGuiElement >> &v)
{
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
	
	int padding = 0;
	for (auto element:v)
	{
		element->SetPositionY(FieldY);
		element->SetPositionX(FieldX + padding);
		padding += element->GetPadding() + element->GetWidth();
	}
}