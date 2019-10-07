#include "stdafx.h"
#include "RowMaker.h"


RowMaker::RowMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column)
{
	float WidthFactor = windowX / static_cast<int> (EnumScreenFields::COUNT); //iloœæ kolumn i wierszy
	float HeightFactor = windowY / static_cast<int> (EnumScreenFields::COUNT);
	FieldX = static_cast<int>(row) * WidthFactor;
	FieldY = static_cast<int>(column) * HeightFactor;
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