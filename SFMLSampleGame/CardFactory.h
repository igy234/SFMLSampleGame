#pragma once
#include "stdafx.h"
#include "EnumCardName.h"
#include "BaseCard.h"
class CardFactory
{
private:
	shared_ptr<ICardModel> EnumCardNameToModel(EnumCardName enumName);

public:
	shared_ptr<BaseCard> CreateCard(EnumCardName cardName);
	CardFactory();
	~CardFactory();
};

