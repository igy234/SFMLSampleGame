#include "stdafx.h"
#include "ChangeGalleryPageCallback.h"


ChangeGalleryPageCallback::ChangeGalleryPageCallback(shared_ptr<CardsPage> page, CardsPage value)
:Page(page),
Value(value)
{
	
}


ChangeGalleryPageCallback::~ChangeGalleryPageCallback()
{

}

void ChangeGalleryPageCallback::action()
{
	*Page = Value;
}
