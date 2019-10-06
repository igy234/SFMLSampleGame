#pragma once
#include"stdafx.h"
#include "EnumScreenFields.h"
#include "BaseGuiElement.h"
class RowMaker
{
private:
	float FieldX, FieldY;
public:
	RowMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column);
	void OrganizePosition(const vector<reference_wrapper<BaseGuiElement>> &v);
	~RowMaker();
};

