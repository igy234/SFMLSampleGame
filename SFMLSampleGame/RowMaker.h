#pragma once
#include"stdafx.h"
#include "EnumScreenFields.h"
#include "BaseGuiElement.h"
class RowMaker
{
private:
	float FieldX, FieldY;
	int StarterWidthPadding = 0;
	int StarterHeightPadding = 0;
public:
	RowMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column);
	void OrganizePosition(const vector<shared_ptr<IGuiElement>> &v);
	void SetStarterWidthPadding(int padding);
	void SetStarterHeightPadding(int padding);
	~RowMaker();
};

