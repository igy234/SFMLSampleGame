#pragma once
#include"stdafx.h"
#include "EnumScreenFields.h"
#include "BaseGuiElement.h"
//Row maker class setting gui objects in one row next to each other
//class holds coordinates of fields in net, width of field and height of field 
class RowMaker
{
private:
	float FieldX, FieldY, WidthFactor, HeightFactor;
	int StarterWidthPadding = 0;
	int StarterHeightPadding = 0;
public:
	RowMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column); //extracts tuple to appropriate arguments in tie, 
	void OrganizePosition(const vector<shared_ptr<IGuiElement>> &v); //set every guielement next to each other starting from appropriate field points
	void SetStarterWidthPadding(int padding);
	void SetStarterHeightPadding(int padding);
	~RowMaker();
};

