#include "stdafx.h"
#include "CardFactory.h"
#include "CardModels.h"

CardFactory::CardFactory()
{
}


CardFactory::~CardFactory()
{
}

shared_ptr<BaseCard> CardFactory::CreateCard(EnumCardName cardName)
{

	auto CardName = EnumCardNameToModel(cardName);
	auto card = make_shared<BaseCard>(CardName);
	//card->SetPadding(0);
	return card;
}

shared_ptr<ICardModel> CardFactory::EnumCardNameToModel(EnumCardName enumName)
{
	//return enumName == EnumCardName::LoremIpsum ? make_shared<LoremIpsumModel>() :
	//	enumName == EnumCardName::IceQueen ? make_shared<IceQueenModel>() :
	//	enumName == EnumCardName::Nix ? make_shared<NixModel>() :
	//	enumName == EnumCardName::BombGoblin ? make_shared<BombGoblinModel>() :
	//	enumName == EnumCardName::Warrior ? make_shared<WarriorModel>() :
	//	enumName == EnumCardName::OctoEyenormous ? make_shared<OctoEyenormousModel>() :
	//	enumName == EnumCardName::Scholar1 ? make_shared<Scholar1Model>() :
	//	enumName == EnumCardName::Scholar2 ? make_shared<Scholar2Model>() :
	//	enumName == EnumCardName::Tinywing ? make_shared<TinywingModel>() :
	//	enumName == EnumCardName::FireMage ? make_shared<FireMageModel>() :
	//	enumName == EnumCardName::GreenDragon ? make_shared<GreenDragonModel>() :
	//	enumName == EnumCardName::YellowDragon ? make_shared<YellowDragonModel>() :
	//	enumName == EnumCardName::RedDragon ? make_shared<RedDragonModel>() :
	//	enumName == EnumCardName::Mimic ? make_shared<MimicModel>() :
	//	enumName == EnumCardName::DualBoxer ? make_shared<DualBoxerModel>() :
	//	enumName == EnumCardName::Minotaur ? make_shared<MinotaurModel>() :
	//	enumName == EnumCardName::SpiderMonk ? make_shared<SpiderMonkModel>() :
	//	enumName == EnumCardName::Dwarf ? make_shared<DwarfModel>() :
	//	enumName == EnumCardName::VikingSlime ? make_shared<VikingSlimeModel>() :
	//	enumName == EnumCardName::CrystalMage ? make_shared<CrystalMageModel>() :
	//	enumName == EnumCardName::Elf ? make_shared<ElfModel>() :
	//	enumName == EnumCardName::Pikeman ? make_shared<PikemanModel>() :
	//	enumName == EnumCardName::King ? make_shared<KingModel>() :
	//	enumName == EnumCardName::BloodyBlue ? make_shared<BloodyBlueModel>() :
	//	enumName == EnumCardName::Adventurer ? make_shared<AdventurerModel>() :
	//	enumName == EnumCardName::DemonLord ? make_shared<DemonLordModel>() :
	//	nullptr;

	switch (enumName)
	{
	case EnumCardName::LoremIpsum:
		return make_shared<LoremIpsumModel>();
		break;
	case EnumCardName::IceQueen:
		return make_shared<IceQueenModel>();
		break;
	case EnumCardName::Nix:
		return make_shared<NixModel>();
		break;
	case EnumCardName::BombGoblin:
		return make_shared<BombGoblinModel>();
		break;
	case EnumCardName::Warrior:
		return make_shared<WarriorModel>();
		break;
	case EnumCardName::OctoEyenormous:
		return make_shared<OctoEyenormousModel>();
		break;
	case EnumCardName::Scholar1:
		return make_shared<Scholar1Model>();
		break;
	case EnumCardName::Scholar2:
		return make_shared<Scholar2Model>();
		break;
	case EnumCardName::Tinywing:
		return make_shared<TinywingModel>();
		break;
	case EnumCardName::FireMage:
		return make_shared<FireMageModel>();
		break;
	case EnumCardName::GreenDragon:
		return make_shared<GreenDragonModel>();
		break;
	case EnumCardName::YellowDragon:
		return make_shared<YellowDragonModel>();
		break;
	case EnumCardName::RedDragon:
		return make_shared<RedDragonModel>();
		break;
	case EnumCardName::Mimic:
		return make_shared<MimicModel>();
		break;
	case EnumCardName::DualBoxer:
		return make_shared<DualBoxerModel>();
		break;
	case EnumCardName::Minotaur:
		return make_shared<MinotaurModel>();
		break;
	case EnumCardName::SpiderMonk:
		return make_shared<SpiderMonkModel>();
		break;
	case EnumCardName::Dwarf:
		return make_shared<DwarfModel>();
		break;
	case EnumCardName::VikingSlime:
		return make_shared<VikingSlimeModel>();
		break;
	case EnumCardName::CrystalMage:
		return make_shared<CrystalMageModel>();
		break;
	case EnumCardName::Elf:
		return make_shared<ElfModel>();
		break;
	case EnumCardName::Pikeman:
		return make_shared<PikemanModel>();
		break;
	case EnumCardName::King:
		return make_shared<KingModel>();
		break;
	case EnumCardName::BloodyBlue:
		return make_shared<BloodyBlueModel>();
		break;
	case EnumCardName::Adventurer:
		return make_shared<AdventurerModel>();
		break;
	case EnumCardName::DemonLord:
		return make_shared<DemonLordModel>();
		break;
	}
	return nullptr;

}