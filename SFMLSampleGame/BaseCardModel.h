#pragma once
#include "ICardModel.h"
class BaseCardModel :public ICardModel
{
private: 
	int Strength;
	string Name;
public:
	virtual int GetStrength() override;
	virtual string GetName() override;
	virtual void SetStrength(int strength) override;
	virtual void SetName(string name) override;
	BaseCardModel(int strength, string name);
	~BaseCardModel();

};

