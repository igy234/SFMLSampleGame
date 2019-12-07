#include "stdafx.h"
#include "DeckStateManager.h"
#include "MenuCallback.h"
#include "CloseWindowCallback.h"
#include "PlayCallback.h"
#include "RowMaker.h"
#include "ChangeGalleryPageCallback.h"


DeckStateManager::DeckStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<GameState>> currentManager)
	:BaseStateManager(window, currentManager),
	Page(make_shared<CardsPage>(CardsPage::First))
{
	deckLayout = make_shared<DeckLayout>(window, Page);
	shared_ptr<ButtonObject> b1 = make_shared<ButtonObject>("Play", 0, 0, 200, 50, make_shared<PlayCallback>(currentManager)); // taki nowy konstruktor
	shared_ptr<ButtonObject> b2 = make_shared<ButtonObject>("Menu", 0, 0, 200, 50, make_shared<MenuCallback>(currentManager));
	shared_ptr<ButtonObject> b3 = make_shared<ButtonObject>("Quit", 0, 0, 200, 50, make_shared<CloseWindowCallback>(Window));
	b1->SetPadding(25);
	b2->SetPadding(25);
	b3->SetPadding(25);
	

	
	RowMaker rowMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldFive, EnumScreenFields::FieldEleven);
	rowMaker.OrganizePosition({b1,b2,b3});
	cout << Window->getSize().x << " " << Window->getSize().y << endl;


	
	shared_ptr<ButtonObject> b4 = make_shared<ButtonObject>("Previous", 0, 0, 200, 50, make_shared<ChangeGalleryPageCallback>(Page, CardsPage::First)); // taki nowy konstruktor
	shared_ptr<ButtonObject> b5 = make_shared<ButtonObject>("Next", 0, 0, 200, 50, make_shared<ChangeGalleryPageCallback>(Page, CardsPage::Second));
	b4->SetPadding(25);
	b5->SetPadding(25);

	RowMaker rowMakerSecond(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldFour, EnumScreenFields::FieldNine);
	rowMakerSecond.SetStarterHeightPadding(50);
	rowMakerSecond.OrganizePosition({b4,b5});

	vector<shared_ptr<IGuiElement>> V;
	V.push_back(b1);
	V.push_back(b2);
	V.push_back(b3);
	V.push_back(b4);
	V.push_back(b5);

	deckLayout->ObtainVector(V);

}


DeckStateManager::~DeckStateManager()
{
}

void DeckStateManager::HandleEvent(const Event& evnt)
{
	switch (evnt.type)
	{
	case Event::Closed: //jeœli zamknij x to zamknij okno
		Window->close();
		break;
	case Event::KeyReleased:
		switch (evnt.key.code)
		{
		case Keyboard::Return:
			break;
		}
		break;

	}

	HandleMouseEvent(evnt);
}

void DeckStateManager::DrawWindowContents()
{
	deckLayout->Show();
}

void DeckStateManager::HandleMouseEvent(const Event& evnt)
{
	deckLayout->HandleMouseEvent(evnt);
}