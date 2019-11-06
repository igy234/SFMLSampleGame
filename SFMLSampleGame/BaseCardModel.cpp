#include "stdafx.h"
#include "BaseCardModel.h"


BaseCardModel::BaseCardModel(int strength, string name)
	:Strength(strength), Name(name)
{
}


BaseCardModel::~BaseCardModel()
{
}

int BaseCardModel::GetStrength() 
{
	return Strength;
}
string BaseCardModel::GetName()
{
	return Name;
}
void BaseCardModel::SetStrength(int strength)
{
	Strength = strength;
}
void BaseCardModel::SetName(string name)
{
	Name = name;
}