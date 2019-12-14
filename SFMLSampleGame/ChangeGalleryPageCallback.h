#pragma once
#include "ICallback.h"
#include "EnumGalleryPages.h"

///Callback class performing managing changing of pages in Gallery state
class ChangeGalleryPageCallback : public ICallback
{
	///shared pointer to enum type representing two gallery pages
	shared_ptr<CardsPage> Page;

	///Value representing gallery's page
	CardsPage Value;
public:
	///@brief constructor ascribing page and value
	///@param "page" representing pages of gallery
	///@param ""value" specyfing which page
	ChangeGalleryPageCallback(shared_ptr<CardsPage> page, CardsPage value);
	~ChangeGalleryPageCallback();

	///@brief method ascribing value to appropriate page
	virtual void action() override;
};

