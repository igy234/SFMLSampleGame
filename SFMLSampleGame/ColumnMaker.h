#include"stdafx.h"
#include "EnumScreenFields.h"
#include "BaseGuiElement.h"
class ColumnMaker 
{
private:
	float FieldX, FieldY, WidthFactor, HeightFactor;
public:
	ColumnMaker(int windowX, int windowY, EnumScreenFields row, EnumScreenFields column);
	void OrganizePosition(const vector<reference_wrapper<BaseGuiElement>> &v);
	~ColumnMaker();
};
