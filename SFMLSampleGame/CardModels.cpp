#include "stdafx.h"
#include "CardModels.h"
#include "BaseCard.h"

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
	ICardModel::CardsVector & enemyUpperBattlefieldCards)
{
	ICardModel::CardsVector cardsVector = make_shared<vector<shared_ptr<IGuiElement>>>();
	auto nix = make_shared<BaseCard>(make_shared<NixModel>());
	nix->SetPadding(10);
	auto nix2 = make_shared<BaseCard>(make_shared<NixModel>());
	nix2->SetPadding(10);
	card->SetPadding(10);
	cout <<"padding ice queena,nix1,nix2 to"<< card->GetPadding() <<" " <<nix->GetPadding() << " "<< nix2->GetPadding() << endl;
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

	//make_shared<NixModel>();
	//make_shared<NixModel>();
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
	: BaseCardModel(1, "Scholar1")
{
}

Scholar1Model::~Scholar1Model()
{
}

Scholar2Model::Scholar2Model()
	: BaseCardModel(1, "Scholar2")
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
	: BaseCardModel(6, "Green Dragon")
{
}

GreenDragonModel::~GreenDragonModel()
{
}

YellowDragonModel::YellowDragonModel()
	: BaseCardModel(6, "Yellow Dragon")
{
}

YellowDragonModel::~YellowDragonModel()
{
}

RedDragonModel::RedDragonModel()
	: BaseCardModel(6, "Red Dragon")
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

KingModel::KingModel()
	: BaseCardModel(4, "King")
{
}

KingModel::~KingModel()
{
}

BloodyBlueModel::BloodyBlueModel()
	: BaseCardModel(8, "Bloody Blue")
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
	: BaseCardModel(8, "Demon Lord")
{
}

DemonLordModel::~DemonLordModel()
{
}
