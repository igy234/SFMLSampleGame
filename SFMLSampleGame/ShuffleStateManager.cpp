#include "stdafx.h"
#include "ShuffleStateManager.h"
#include "GenerateCards.h"
#include "CardFactory.h"
#include "RowMaker.h"

ShuffleStateManager::ShuffleStateManager(shared_ptr<RenderWindow> window, shared_ptr<IStateOperator<MatchState>> currentManager, shared_ptr<PlayLayout> playLayout, 
	shared_ptr<vector<shared_ptr<IGuiElement>>> userHandCards, shared_ptr<RectangleObject> exchangeCardsInfo, shared_ptr<ICallback> ingameCall)
	:BaseStateManager(window, currentManager),
	UserHandCards(userHandCards),
	Layout(playLayout),
	ExchangeCardsInfo(exchangeCardsInfo),
	ingameCallback(ingameCall)
{
	b3 = make_shared<ButtonObject>("End Exchange", 0, 0, 250, 50, ingameCallback);
	vector<shared_ptr<IGuiElement>> TempVec;
	TempVec.push_back(ExchangeCardsInfo);
	TempVec.push_back(b3);
	Layout->SetGuiElementsForCurrentState(TempVec);

	ExchangeCardsInfo->setOutlineThickness(2);
	ExchangeCardsInfo->SetPadding(0);
	vector<shared_ptr<IGuiElement>> ExchangeCardsPopup; //holding rectangle with information about exchanging cards
	ExchangeCardsPopup.push_back(ExchangeCardsInfo);
	ExchangeCardsPopup.push_back(b3);
	RowMaker rowMakerExchangeCards(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldFour, EnumScreenFields::FieldEight);
	rowMakerExchangeCards.OrganizePosition(ExchangeCardsPopup);

}


ShuffleStateManager::~ShuffleStateManager()
{
}

void ShuffleStateManager::DrawWindowContents()
{
	Layout->Show();
}

void ShuffleStateManager::HandleMouseEvent(const Event& evnt)
{
	Layout->HandleMouseEvent(evnt);
}

void ShuffleStateManager::HandleEvent(const Event& evnt)
{

}

void ShuffleStateManager::PerformCardOperation(shared_ptr<IGuiElement> card)
{
	if (--ExchangeCount < 0)
	{
		ingameCallback->action();
		return;
	}
		
	ExchangeCardsInfo->SetText("Exchange your cards, exchanges left: " + to_string(ExchangeCount));
	GenerateCards generate;
	CardFactory factory;
	shared_ptr<IGuiElement> newCard;

	newCard = factory.CreateCard(generate.GenerateRandomCardNameEnum());

	newCard->SetPositionX(card->GetPositionX());
	newCard->SetPositionY(card->GetPositionY());

	replace(UserHandCards->begin(), UserHandCards->end(), card, newCard);
	
}

void ShuffleStateManager::HandleExchangeCardsInformation()
{
	

	//ExchangeCardsInfo->setVisibility(false);
}