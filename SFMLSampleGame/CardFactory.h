#pragma once
#include "stdafx.h"
#include "EnumCardName.h"
#include "BaseCard.h"
///Factory class used to create cards
class CardFactory
{
private:
	///@brief method changing the card name into model card object
	///@param "enumName" enum type name of the card
	///@return card model object according to "enumName"
	shared_ptr<ICardModel> EnumCardNameToModel(EnumCardName enumName);

public:
	///@brief cration of card based on card's name and its model
	///@param "cardName" enum type name of the card
	///@return card object 
	shared_ptr<BaseCard> CreateCard(EnumCardName cardName); 
	CardFactory();
	~CardFactory();
};

