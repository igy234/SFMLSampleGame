#include "stdafx.h"
#include "CardModels.h"
#include "BaseCard.h"
#include "GenerateCards.h"
#include "CardFactory.h"
#include "Utils.h"

LoremIpsumModel::LoremIpsumModel()
	: BaseCardModel(4, "Lorem Ipsum") 
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

IceQueenModel::IceQueenModel()
	: BaseCardModel(4, "Ice Queen")
{
}

IceQueenModel::~IceQueenModel()
{
}


NixModel::NixModel()
	: BaseCardModel(2, "Nix")
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

BombGoblinModel::BombGoblinModel()
	:BaseCardModel(3, "Bomb Goblin")
{
}

BombGoblinModel::~BombGoblinModel()
{
}

WarriorModel::WarriorModel()
	: BaseCardModel(4, "Warrior")
{
}

WarriorModel::~WarriorModel()
{
}

OctoEyenormousModel::OctoEyenormousModel()
	: BaseCardModel(7, "OctoEyenormous")
{
}

OctoEyenormousModel::~OctoEyenormousModel()
{
}



Scholar1Model::Scholar1Model()
	: ScholarCardModel(1, "Scholar1")
{
}

Scholar1Model::~Scholar1Model()
{
}

Scholar2Model::Scholar2Model()
	: ScholarCardModel(1, "Scholar2")
{
}

Scholar2Model::~Scholar2Model()
{
}

TinywingModel::TinywingModel()
	: BaseCardModel(5, "Tinywing")
{
}

TinywingModel::~TinywingModel()
{
}

FireMageModel::FireMageModel()
	: BaseCardModel(4, "Fire Mage")
{
}

FireMageModel::~FireMageModel()
{
}


GreenDragonModel::GreenDragonModel()
	: DragonCardModel(6, "Green Dragon")
{
}

GreenDragonModel::~GreenDragonModel()
{
}


YellowDragonModel::YellowDragonModel()
	: DragonCardModel(6, "Yellow Dragon")
{
}

YellowDragonModel::~YellowDragonModel()
{
}


RedDragonModel::RedDragonModel()
	: DragonCardModel(6, "Red Dragon")
{
}

RedDragonModel::~RedDragonModel()
{
}

MimicModel::MimicModel()
	: BaseCardModel(5, "Mimic")
{
}

MimicModel::~MimicModel()
{
}

DualBoxerModel::DualBoxerModel()
	: BaseCardModel(4, "Dual Boxer")
{
}

DualBoxerModel::~DualBoxerModel()
{
}

MinotaurModel::MinotaurModel()
	: BaseCardModel(5, "Minotaur")
{
}

MinotaurModel::~MinotaurModel()
{
}

SpiderMonkModel::SpiderMonkModel()
	: BaseCardModel(3, "Spider Monk")
{
}

SpiderMonkModel::~SpiderMonkModel()
{
}

DwarfModel::DwarfModel()
	: BaseCardModel(5, "Dwarf")
{
}

DwarfModel::~DwarfModel()
{
}

VikingSlimeModel::VikingSlimeModel()
	: BaseCardModel(2, "Viking Slime")
{
}

VikingSlimeModel::~VikingSlimeModel()
{
}

CrystalMageModel::CrystalMageModel()
	: BaseCardModel(4, "Crystal Mage")
{
}

CrystalMageModel::~CrystalMageModel()
{
}

ElfModel::ElfModel()
	: BaseCardModel(4, "Elf")
{
}

ElfModel::~ElfModel()
{
}

PikemanModel::PikemanModel()
	: BaseCardModel(3, "Pikeman")
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
	//TRZEBA DODAÆ ENEMY HAND CARDSS ALBO ZROBIÆ COŒ INNEGO!!!
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

KingModel::KingModel()
	: BaseCardModel(4, "King")
{
}

KingModel::~KingModel()
{
}

BloodyBlueModel::BloodyBlueModel()
	: DemonLordAndBloodyBlueModel(8, "Bloody Blue")
{
}

BloodyBlueModel::~BloodyBlueModel()
{
}

AdventurerModel::AdventurerModel()
	: BaseCardModel(5, "Adventurer")
{
}

AdventurerModel::~AdventurerModel()
{
}

DemonLordModel::DemonLordModel()
	: DemonLordAndBloodyBlueModel(8, "Demon Lord")
{
}

DemonLordModel::~DemonLordModel()
{
}
DragonCardModel::DragonCardModel(int strength, string name)
	:BaseCardModel(strength, name)
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
	vector<shared_ptr<IGuiElement>> vect = *userLowerBattlefieldCards;
	vect.insert(vect.begin(), userUpperBattlefieldCards->begin(), userUpperBattlefieldCards->end());
	int yellowDragonCounter = 0;
	int redDragonCounter = 0;
	int greenDragonCounter = 0;

	if (vect.size() <= 2)
		return;

	vector<shared_ptr<IGuiElement>> dragons;
	copy_if(vect.begin(), vect.end(), back_inserter(dragons),
		[](auto element)
	{
		return (static_pointer_cast<BaseCard>(element)->GetModel()->GetName().find("Dragon") != string::npos);
	});

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

ScholarCardModel::ScholarCardModel(int strength, string name)
	:BaseCardModel(strength,name)
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

DemonLordAndBloodyBlueModel::DemonLordAndBloodyBlueModel(int strength, string name)
	:BaseCardModel(strength, name)
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
