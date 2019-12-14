#pragma once
#include"stdafx.h"
#include "EnumScreenFields.h"
#include "BaseGuiElement.h"
///Class setting gui objects in one column below each other in provided part of the window
class ColumnMaker 
{
private:
	///holds coordinate x of fields in net dividng the screen
	float FieldX;

	///holds coordinate y of fields in net dividng the screen
	float FieldY;

	///holds width of fields in net dividng the screen
	float WidthFactor;

	///holds height of fields in net dividng the screen
	float HeightFactor;

	///holds width padding for objects set by column maker, default is 0
	int StarterWidthPadding = 0;

	///holds height padding for objects set by column maker, default is 0
	int StarterHeightPadding = 0;
public:

	///@brief constructor extracts tuple to appropriate arguments in tie 
	///@param "windowX" representing window's width
	///@param "windowY" representing window's height
	///@param "row" representing row in net (divided screen parts)
	///@param "column" representing colum in net (divided screen parts)
	ColumnMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column);

	///@brief sets every gui element below each other starting from appropriate field points
	///@param "v" vector representing elements to be organized
	void OrganizePosition(const vector<shared_ptr<IGuiElement>> &v);

	///@brief setter for StarterWidthPadding
	///@param "padding" specifyies width padding
	void SetStarterWidthPadding(int padding); 

	///@brief setter for StarterHeightPadding
	///@param "padding" specifyies height padding
	void SetStarterHeightPadding(int padding);
	~ColumnMaker();
};
