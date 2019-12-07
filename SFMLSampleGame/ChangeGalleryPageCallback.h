#pragma once
#include "ICallback.h"
#include "EnumGalleryPages.h"
class ChangeGalleryPageCallback : public ICallback
{
	shared_ptr<CardsPage> Page;
	CardsPage Value;
public:
	ChangeGalleryPageCallback(shared_ptr<CardsPage> page, CardsPage value);
	~ChangeGalleryPageCallback();
	virtual void action() override;
};

