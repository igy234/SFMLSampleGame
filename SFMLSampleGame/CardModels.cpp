#include "stdafx.h"
#include "CardModels.h"
#include "BaseCard.h"
#include "GenerateCards.h"
#include "CardFactory.h"
#include "Utils.h"


LoremIpsumModel::LoremIpsumModel()
	: BaseCardModel(4, "Lorem Ipsum", 4) 
{
}


LoremIpsumModel::~LoremIpsumModel()
{
}

void IceQueenModel::CardSpecialAbility(
	shared_ptr<IGuiElement> card,
	BattleField battlefield,
	ICardModel::CardsVector & userHandCards,
	ICardModel::CardsVector & userLowerBattlefieldCards,
	ICardModel::CardsVector & userUpperBattlefieldCards,
	ICardModel::CardsVector & enemyLowerBattlefieldCards,
	ICardModel::CardsVector & enemyUpperBattlefieldCards,
	ICardModel::CardsVector& enemyHandCards)
{
	ICardModel::CardsVector cardsVector = make_shared<vector<shared_ptr<IGuiElement>>>();
	auto nix = make_shared<BaseCard>(make_shared<NixModel>());
	nix->SetPadding(10);
	auto nix2 = make_shared<BaseCard>(make_shared<NixModel>());
	nix2->SetPadding(10);
	card->SetPadding(10);
	cardsVector->push_back(nix);
	cardsVector->push_back(card);
	cardsVector->push_back(nix2);
	
	switch (battlefield)
	{
	case BattleField::Lower:
		userLowerBattlefieldCards->insert(userLowerBattlefieldCards->end(), cardsVector->begin(), cardsVector->end());
		break;

	case BattleField::Upper:
		userUpperBattlefieldCards->insert(userUpperBattlefieldCards->end(), cardsVector->begin(), cardsVector->end());
		break;

	}
}

float IceQueenModel::CalculatePlayCoefficient(shared_ptr<IGuiElement> card, BattleField battlefield, ICardModel::CardsVector & userHandCards, ICardModel::CardsVector & userLowerBattlefieldCards, ICardModel::CardsVector & userUpperBattlefieldCards, ICardModel::CardsVector & enemyLowerBattlefieldCards, ICardModel::CardsVector & enemyUpperBattlefieldCards, ICardModel::CardsVector & enemyHandCards)
{
	float Impact = 4;
	return (Strength +
		Impact +
		RiskAllCards[enemyHandCards->size()][Strength - 1] +
		RiskIceQueen[userLowerBattlefieldCards->size()][userUpperBattlefieldCards->size()]) / ExpectedValue;
}

IceQueenModel::IceQueenModel()
	: BaseCardModel(4, "Ice Queen", 8)
{
}

IceQueenModel::~IceQueenModel()
{
}


NixModel::NixModel()
	: BaseCardModel(2, "Nix", 2)
{
}

NixModel::~NixModel()
{
}

void BombGoblinModel::CardSpecialAbility(shared_ptr<IGuiElement> card,
	BattleField battlefield,
	ICardModel::CardsVector & userHandCards,
	ICardModel::CardsVector & userLowerBattlefieldCards,
	ICardModel::CardsVector & userUpperBattlefieldCards,
	ICardModel::CardsVector & enemyLowerBattlefieldCards,
	ICardModel::CardsVector & enemyUpperBattlefieldCards,
	ICardModel::CardsVector& enemyHandCards)
{
	int lowestStrength = std::numeric_limits<int>::max();
	vector<shared_ptr<IGuiElement>> vect = *enemyLowerBattlefieldCards;
	vect.insert(vect.begin(), enemyUpperBattlefieldCards->begin(), enemyUpperBattlefieldCards->end());

	if (!vect.size()) 
	{
		BaseCardModel::CardSpecialAbility(card, battlefield, userHandCards, userLowerBattlefieldCards, userUpperBattlefieldCards, enemyLowerBattlefieldCards, enemyUpperBattlefieldCards, enemyHandCards);
		return;
	}
	for (auto element : vect)
	{
		auto card = static_pointer_cast<BaseCard>(element);
		if (card->GetModel()->GetStrength() < lowestStrength)
		{
			lowestStrength = card->GetModel()->GetStrength();
		}
	}

	vector<shared_ptr<IGuiElement>> weakestCards;

	for (auto element : vect)
	{
		auto card = static_pointer_cast<BaseCard>(element);
		if (card->GetModel()->GetStrength() == lowestStrength)
		{
			weakestCards.push_back(card);
		}
	}

	for (auto element : weakestCards)
	{
		auto it = find(enemyLowerBattlefieldCards->begin(), enemyLowerBattlefieldCards->end(), element);
		if (it != enemyLowerBattlefieldCards->end())
		{
			enemyLowerBattlefieldCards->erase(it);
		}
		else
		{
			auto it = find(enemyUpperBattlefieldCards->begin(), enemyUpperBattlefieldCards->end(), element);
			if (it != enemyUpperBattlefieldCards->end())
			{
				enemyUpperBattlefieldCards->erase(it);
			}
			else
			{
				cerr << "SOMETHING WENT WRONG (BOMB GOBLIN CARD DID NOT FIND CARDS TO EREASE)" << endl;
			}
		}

	}
	BaseCardModel::CardSpecialAbility(card, battlefield, userHandCards, userLowerBattlefieldCards, userUpperBattlefieldCards, enemyLowerBattlefieldCards, enemyUpperBattlefieldCards, enemyHandCards);
	
}

float BombGoblinModel::CalculatePlayCoefficient(shared_ptr<IGuiElement> card, BattleField battlefield, ICardModel::CardsVector & userHandCards, ICardModel::CardsVector & userLowerBattlefieldCards, ICardModel::CardsVector & userUpperBattlefieldCards, ICardModel::CardsVector & enemyLowerBattlefieldCards, ICardModel::CardsVector & enemyUpperBattlefieldCards, ICardModel::CardsVector & enemyHandCards)
{
	vector<shared_ptr<IGuiElement>> dragons = FindAllDragons(enemyLowerBattlefieldCards, enemyUpperBattlefieldCards);
	float Impact = 0;
	float WeakestStrength = numeric_limits<int>::max();;
	vector<shared_ptr<IGuiElement>> vectE = *enemyLowerBattlefieldCards;
	vectE.insert(vectE.begin(), enemyUpperBattlefieldCards->begin(), enemyUpperBattlefieldCards->end());


	for (auto element : vectE)
	{
		auto strenght = static_pointer_cast<BaseCard>(element)->GetModel()->GetStrength();
		if (strenght < WeakestStrength)
			WeakestStrength = strenght;
	}

	int counter = 0;
	for (auto element : vectE)
	{
		if (static_pointer_cast<BaseCard>(element)->GetModel()->GetStrength() == WeakestStrength)
		{
			counter++;
		}
	}

	Impact = WeakestStrength * counter;
	return (Strength + 
		Impact +
		RiskAllCards[enemyHandCards->size()][Strength-1] +
		RiskDestroyingCardsDependingOnDragons[dragons.size()] +
		RiskDestroyingCardsWithoutKing[enemyLowerBattlefieldCards->size() + enemyUpperBattlefieldCards->size()]) / ExpectedValue;
}

BombGoblinModel::BombGoblinModel()
	:BaseCardModel(3, "Bomb Goblin", 7)
{
}

BombGoblinModel::~BombGoblinModel()
{
}

WarriorModel::WarriorModel()
	: BaseCardModel(4, "Warrior", 4)
{
}

WarriorModel::~WarriorModel()
{
}

OctoEyenormousModel::OctoEyenormousModel()
	: BaseCardModel(7, "OctoEyenormous", 7)
{
}

OctoEyenormousModel::~OctoEyenormousModel()
{
}



Scholar1Model::Scholar1Model()
	: ScholarCardModel(1, "Scholar1", 5.52)
{
}

Scholar1Model::~Scholar1Model()
{
}

Scholar2Model::Scholar2Model()
	: ScholarCardModel(1, "Scholar2", 5.52)
{
}

Scholar2Model::~Scholar2Model()
{
}

TinywingModel::TinywingModel()
	: BaseCardModel(5, "Tinywing", 5)
{
}

TinywingModel::~TinywingModel()
{
}

FireMageModel::FireMageModel()
	: BaseCardModel(4, "Fire Mage", 4)
{
}

FireMageModel::~FireMageModel()
{
}


GreenDragonModel::GreenDragonModel()
	: DragonCardModel(6, "Green Dragon", 8)
{
}

GreenDragonModel::~GreenDragonModel()
{
}


YellowDragonModel::YellowDragonModel()
	: DragonCardModel(6, "Yellow Dragon", 8)
{
}

YellowDragonModel::~YellowDragonModel()
{
}


RedDragonModel::RedDragonModel()
	: DragonCardModel(6, "Red Dragon", 8)
{
}

RedDragonModel::~RedDragonModel()
{
}

MimicModel::MimicModel()
	: BaseCardModel(5, "Mimic", 5)
{
}

MimicModel::~MimicModel()
{
}

DualBoxerModel::DualBoxerModel()
	: BaseCardModel(4, "Dual Boxer", 4)
{
}

DualBoxerModel::~DualBoxerModel()
{
}

MinotaurModel::MinotaurModel()
	: BaseCardModel(5, "Minotaur", 5)
{
}

MinotaurModel::~MinotaurModel()
{
}

SpiderMonkModel::SpiderMonkModel()
	: BaseCardModel(3, "Spider Monk", 3)
{
}

SpiderMonkModel::~SpiderMonkModel()
{
}

DwarfModel::DwarfModel()
	: BaseCardModel(5, "Dwarf", 5)
{
}

DwarfModel::~DwarfModel()
{
}

VikingSlimeModel::VikingSlimeModel()
	: BaseCardModel(2, "Viking Slime", 2)
{
}

VikingSlimeModel::~VikingSlimeModel()
{
}

CrystalMageModel::CrystalMageModel()
	: BaseCardModel(4, "Crystal Mage", 4)
{
}

CrystalMageModel::~CrystalMageModel()
{
}

ElfModel::ElfModel()
	: BaseCardModel(4, "Elf", 4)
{
}

ElfModel::~ElfModel()
{
}

PikemanModel::PikemanModel()
	: BaseCardModel(3, "Pikeman", 3)
{
}

PikemanModel::~PikemanModel()
{
}

void KingModel::CardSpecialAbility(shared_ptr<IGuiElement> card,
	BattleField battlefield,
	ICardModel::CardsVector & userHandCards,
	ICardModel::CardsVector & userLowerBattlefieldCards,
	ICardModel::CardsVector & userUpperBattlefieldCards,
	ICardModel::CardsVector & enemyLowerBattlefieldCards,
	ICardModel::CardsVector & enemyUpperBattlefieldCards,
	ICardModel::CardsVector& enemyHandCards)
{
	
	if (!enemyHandCards->size())
	{
		BaseCardModel::CardSpecialAbility(card, battlefield, userHandCards, userLowerBattlefieldCards, userUpperBattlefieldCards, enemyLowerBattlefieldCards, enemyUpperBattlefieldCards, enemyHandCards);
		return;
	}
	else
	{
		int it = getRand(static_cast<int>(enemyHandCards->size()));
		enemyHandCards->erase(enemyHandCards->begin() + it);
		BaseCardModel::CardSpecialAbility(card, battlefield, userHandCards, userLowerBattlefieldCards, userUpperBattlefieldCards, enemyLowerBattlefieldCards, enemyUpperBattlefieldCards, enemyHandCards);
	}
}

float KingModel::CalculatePlayCoefficient(shared_ptr<IGuiElement> card, BattleField battlefield, ICardModel::CardsVector & userHandCards, ICardModel::CardsVector & userLowerBattlefieldCards, ICardModel::CardsVector & userUpperBattlefieldCards, ICardModel::CardsVector & enemyLowerBattlefieldCards, ICardModel::CardsVector & enemyUpperBattlefieldCards, ICardModel::CardsVector & enemyHandCards)
{
	vector<shared_ptr<IGuiElement>> dragons = FindAllDragons(enemyLowerBattlefieldCards, enemyUpperBattlefieldCards);

	float Impact = 4.52; // average card strength
	return (Strength + 
		Impact + 
		RiskAllCards[enemyHandCards->size()][Strength-1] +
		RiskDestroyingCardsDependingOnDragons[dragons.size()] +
		RiskKingCard[enemyHandCards->size()]) / ExpectedValue		;
}

KingModel::KingModel()
	: BaseCardModel(4, "King", 8.52)
{
}

KingModel::~KingModel()
{
}

BloodyBlueModel::BloodyBlueModel()
	: DemonLordAndBloodyBlueModel(8, "Bloody Blue", 14)
{
}

BloodyBlueModel::~BloodyBlueModel()
{
}

AdventurerModel::AdventurerModel()
	: BaseCardModel(5, "Adventurer", 5)
{
}

AdventurerModel::~AdventurerModel()
{
}

DemonLordModel::DemonLordModel()
	: DemonLordAndBloodyBlueModel(8, "Demon Lord", 14)
{
}

DemonLordModel::~DemonLordModel()
{
}


tuple<int, int, int> DragonCardModel::CalculateNumberOfDragons(vector<shared_ptr<IGuiElement>> dragons)
{
	int yellowDragonCounter = 0;
	int redDragonCounter = 0;
	int greenDragonCounter = 0;

	for (auto element : dragons)
	{
		string name = static_pointer_cast<BaseCard>(element)->GetModel()->GetName();
		if (name == "Yellow Dragon")
		{
			yellowDragonCounter++;
		}
		else if (name == "Red Dragon")
		{
			redDragonCounter++;
		}
		else if (name == "Green Dragon")
		{
			greenDragonCounter++;
		}
	}

	return { yellowDragonCounter, redDragonCounter, greenDragonCounter };
}


DragonCardModel::DragonCardModel(int strength, string name, float expectedValue)
	:BaseCardModel(strength, name, expectedValue)
{

}

void DragonCardModel::CardSpecialAbility(shared_ptr<IGuiElement> card,
	BattleField battlefield, ICardModel::CardsVector & userHandCards,
	ICardModel::CardsVector & userLowerBattlefieldCards,
	ICardModel::CardsVector & userUpperBattlefieldCards,
	ICardModel::CardsVector & enemyLowerBattlefieldCards,
	ICardModel::CardsVector & enemyUpperBattlefieldCards, 
	ICardModel::CardsVector& enemyHandCards)
{
	BaseCardModel::CardSpecialAbility(card, battlefield, userHandCards, userLowerBattlefieldCards, userUpperBattlefieldCards, enemyLowerBattlefieldCards, enemyUpperBattlefieldCards, enemyHandCards);

	if (userLowerBattlefieldCards->size() + userUpperBattlefieldCards->size() <= 2)
		return;

	vector<shared_ptr<IGuiElement>> dragons = FindAllDragons(userLowerBattlefieldCards, userUpperBattlefieldCards);

	auto [yellowDragonCounter, redDragonCounter, greenDragonCounter] = CalculateNumberOfDragons(dragons);

	if (yellowDragonCounter && redDragonCounter && greenDragonCounter)
	{
		int whichRow = getRand(1);
		switch (whichRow)
		{
		case 0:
			enemyLowerBattlefieldCards->clear();
			break;
		case 1:
			enemyUpperBattlefieldCards->clear();
			break;
		}
	}
}

float DragonCardModel::CalculatePlayCoefficient(shared_ptr<IGuiElement> card, BattleField battlefield, ICardModel::CardsVector & userHandCards, ICardModel::CardsVector & userLowerBattlefieldCards, ICardModel::CardsVector & userUpperBattlefieldCards, ICardModel::CardsVector & enemyLowerBattlefieldCards, ICardModel::CardsVector & enemyUpperBattlefieldCards, ICardModel::CardsVector & enemyHandCards)
{
	vector<shared_ptr<IGuiElement>> dragons = FindAllDragons(userLowerBattlefieldCards, userUpperBattlefieldCards);
	auto [yellowDragonCounter, redDragonCounter, greenDragonCounter] = CalculateNumberOfDragons(dragons);
	
	float averageImpact = 0;
	auto name = GetName();
	
	if (name == "Yellow Dragon")
	{
		yellowDragonCounter++;
	}
	else if (name == "Red Dragon")
	{
		redDragonCounter++;
	}
	else if (name == "Green Dragon")
	{
		greenDragonCounter++;
	}
	
	if (yellowDragonCounter && redDragonCounter && greenDragonCounter)
	{
		auto pointsLower = 0;
		auto pointsUpper = 0;

		for (auto element : *enemyLowerBattlefieldCards)
		{
			auto card = static_pointer_cast<BaseCard>(element);
			pointsLower += card->GetModel()->GetStrength();
		}
		
		for (auto element : *enemyUpperBattlefieldCards)
		{
			auto card = static_pointer_cast<BaseCard>(element);
			pointsUpper += card->GetModel()->GetStrength();
		}
		averageImpact = (pointsLower + pointsUpper) / 2;
		 
	}

	return (Strength +
		averageImpact +
		RiskAllCards[enemyHandCards->size()][Strength-1] +
		RiskDestroyingCardsDependingOnDragons[dragons.size()] +
		RiskDestroyingCardsWithoutKing[enemyLowerBattlefieldCards->size()+enemyUpperBattlefieldCards->size()])/ExpectedValue;
}

ScholarCardModel::ScholarCardModel(int strength, string name, float expectedValue)
	:BaseCardModel(strength, name, expectedValue)
{
}

void ScholarCardModel::CardSpecialAbility(shared_ptr<IGuiElement> card,
	BattleField battlefield, ICardModel::CardsVector & userHandCards,
	ICardModel::CardsVector & userLowerBattlefieldCards
	, ICardModel::CardsVector & userUpperBattlefieldCards,
	ICardModel::CardsVector & enemyLowerBattlefieldCards,
	ICardModel::CardsVector & enemyUpperBattlefieldCards,
	ICardModel::CardsVector& enemyHandCards)
{
	GenerateCards generate;
	CardFactory factory;
	shared_ptr<IGuiElement> newCard;

	BaseCardModel::CardSpecialAbility(card, battlefield, userHandCards, userLowerBattlefieldCards, userUpperBattlefieldCards, enemyLowerBattlefieldCards, enemyUpperBattlefieldCards, enemyHandCards);
	newCard = factory.CreateCard(generate.GenerateRandomCardNameEnum());
	newCard->SetPadding(10);
	newCard->SetPositionX(card->GetPositionX());
	newCard->SetPositionY(card->GetPositionY());
	userHandCards->push_back(newCard);
}

float ScholarCardModel::CalculatePlayCoefficient(shared_ptr<IGuiElement> card, BattleField battlefield, ICardModel::CardsVector & userHandCards, ICardModel::CardsVector & userLowerBattlefieldCards, ICardModel::CardsVector & userUpperBattlefieldCards, ICardModel::CardsVector & enemyLowerBattlefieldCards, ICardModel::CardsVector & enemyUpperBattlefieldCards, ICardModel::CardsVector & enemyHandCards)
{
	vector<shared_ptr<IGuiElement>> dragons = FindAllDragons(enemyLowerBattlefieldCards, enemyUpperBattlefieldCards);
	float expectedImpact = 4.52; //average strength of card
	return (Strength + expectedImpact + RiskAllCards[enemyHandCards->size()][Strength-1] +
		RiskAddingCards[userLowerBattlefieldCards->size()+userUpperBattlefieldCards->size()] +
		RiskNormalCardsDependingOnDragons[Strength-1][dragons.size()]) / ExpectedValue;
}

DemonLordAndBloodyBlueModel::DemonLordAndBloodyBlueModel(int strength, string name, float expectedValue)
	:BaseCardModel(strength, name, expectedValue)
{

}

void DemonLordAndBloodyBlueModel::CardSpecialAbility(shared_ptr<IGuiElement> card,
	BattleField battlefield,
	ICardModel::CardsVector & userHandCards,
	ICardModel::CardsVector & userLowerBattlefieldCards,
	ICardModel::CardsVector & userUpperBattlefieldCards,
	ICardModel::CardsVector & enemyLowerBattlefieldCards,
	ICardModel::CardsVector & enemyUpperBattlefieldCards, 
	ICardModel::CardsVector& enemyHandCards)
{
	int highestStrength = 0;
	vector<shared_ptr<IGuiElement>> vect = *enemyLowerBattlefieldCards;
	vect.insert(vect.begin(), enemyUpperBattlefieldCards->begin(), enemyUpperBattlefieldCards->end());
	vect.insert(vect.begin(), userLowerBattlefieldCards->begin(), userLowerBattlefieldCards->end());
	vect.insert(vect.begin(), userUpperBattlefieldCards->begin(), userUpperBattlefieldCards->end());

	if (!vect.size())
	{
		BaseCardModel::CardSpecialAbility(card, battlefield, userHandCards, userLowerBattlefieldCards, userUpperBattlefieldCards, enemyLowerBattlefieldCards, enemyUpperBattlefieldCards, enemyHandCards);
		return;
	}
	for (auto element : vect)
	{
		auto card = static_pointer_cast<BaseCard>(element);
		if (card->GetModel()->GetStrength() > highestStrength)
		{
			highestStrength = card->GetModel()->GetStrength();
		}
	}

	vector<shared_ptr<IGuiElement>> StrongestCards;

	for (auto element : vect)
	{
		auto card = static_pointer_cast<BaseCard>(element);
		if (card->GetModel()->GetStrength() == highestStrength)
		{
			StrongestCards.push_back(card);
		}
	}

	for (auto element : StrongestCards)
	{
		auto it = find(enemyLowerBattlefieldCards->begin(), enemyLowerBattlefieldCards->end(), element);
		if (it != enemyLowerBattlefieldCards->end())
		{
			enemyLowerBattlefieldCards->erase(it);
		}
		else
		{
			auto it = find(enemyUpperBattlefieldCards->begin(), enemyUpperBattlefieldCards->end(), element);
			if (it != enemyUpperBattlefieldCards->end())
			{
				enemyUpperBattlefieldCards->erase(it);
			}
			else
			{
				auto it = find(userLowerBattlefieldCards->begin(), userLowerBattlefieldCards->end(), element);
				if (it != userLowerBattlefieldCards->end())
				{
					userLowerBattlefieldCards->erase(it);
				}
				else
				{
					auto it = find(userUpperBattlefieldCards->begin(), userUpperBattlefieldCards->end(), element);

					if (it != userUpperBattlefieldCards->end())
					{
						userUpperBattlefieldCards->erase(it);
					}
					else
					{
						cerr << "DEMON LORD OR BLOODY BLUE CAUSED ERROR";
					}
				}
			}
		}

	}
	BaseCardModel::CardSpecialAbility(card, battlefield, userHandCards, userLowerBattlefieldCards, userUpperBattlefieldCards, enemyLowerBattlefieldCards, enemyUpperBattlefieldCards, enemyHandCards);

}

float DemonLordAndBloodyBlueModel::CalculatePlayCoefficient(shared_ptr<IGuiElement> card, BattleField battlefield, ICardModel::CardsVector & userHandCards, ICardModel::CardsVector & userLowerBattlefieldCards, ICardModel::CardsVector & userUpperBattlefieldCards, ICardModel::CardsVector & enemyLowerBattlefieldCards, ICardModel::CardsVector & enemyUpperBattlefieldCards, ICardModel::CardsVector & enemyHandCards)
{

	float Impact = 0;
	vector<shared_ptr<IGuiElement>> dragons = FindAllDragons(enemyLowerBattlefieldCards, enemyUpperBattlefieldCards);
	
	vector<shared_ptr<IGuiElement>> vectU = *userLowerBattlefieldCards;
	vectU.insert(vectU.begin(), userUpperBattlefieldCards->begin(), userUpperBattlefieldCards->end());
	
	vector<shared_ptr<IGuiElement>> vectE = *enemyLowerBattlefieldCards;
	vectE.insert(vectE.begin(), enemyUpperBattlefieldCards->begin(), enemyUpperBattlefieldCards->end());

	vector<shared_ptr<IGuiElement>> vectUber = vectU;
	vectUber.insert(vectUber.begin(), vectE.begin(), vectE.end());
	auto UberStrength = 0;
	
	for (auto element : vectUber)
	{
		auto strenght = static_pointer_cast<BaseCard>(element)->GetModel()->GetStrength();
		if (strenght > UberStrength)
			UberStrength = strenght;
	}
	
	vector<shared_ptr<IGuiElement>> MyStronges, EnemyStrongest;

	auto mySum = 0;
	auto enemySum = 0;

	for (auto element : vectU)
	{
		auto card = static_pointer_cast<BaseCard>(element);
		auto strenght = card->GetModel()->GetStrength();
		mySum += strenght;
		if (strenght == UberStrength)
			MyStronges.push_back(element);
	}

	for (auto element : vectE)
	{
		auto card = static_pointer_cast<BaseCard>(element);
		auto strenght = card->GetModel()->GetStrength();
		enemySum += strenght;
		if (strenght == UberStrength)
			EnemyStrongest.push_back(element);
	}

	float myImpact = (MyStronges.size()*UberStrength);
	float enemyImpact = EnemyStrongest.size()*UberStrength;

	Impact = enemyImpact - myImpact;

	auto risk1 = RiskAllCards[enemyHandCards->size()][Strength - 1];
	auto risk2 = RiskDestroyingCardsDependingOnDragons[dragons.size()];
	auto risk3 = RiskDestroyingCardsWithoutKing[enemyLowerBattlefieldCards->size() + enemyUpperBattlefieldCards->size()];

	return (Strength + 
		Impact + 
		RiskAllCards[enemyHandCards->size()][Strength-1] +
		RiskDestroyingCardsDependingOnDragons[dragons.size()] +
		RiskDestroyingCardsWithoutKing[enemyLowerBattlefieldCards->size() + enemyUpperBattlefieldCards->size()])/ExpectedValue;
}
