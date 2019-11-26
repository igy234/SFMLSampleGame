#pragma once
#include "stdafx.h"
#include "BaseCardModel.h"

class DragonCardModel : public BaseCardModel
{
public:
	DragonCardModel(int strength, string name);
	virtual void CardSpecialAbility(
		shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;
};

class ScholarCardModel : public BaseCardModel
{
public:
	ScholarCardModel(int strength, string name);
	virtual void CardSpecialAbility(
		shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;
};

class DemonLordAndBloodyBlueModel : public BaseCardModel
{
public:
	DemonLordAndBloodyBlueModel(int strength, string name);
	virtual void CardSpecialAbility(
		shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;
};

class LoremIpsumModel : public BaseCardModel
{
public:
	LoremIpsumModel();
	~LoremIpsumModel();
};

class IceQueenModel : public BaseCardModel
{
public:
	virtual void CardSpecialAbility(
		shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;
	IceQueenModel();
	~IceQueenModel();
};

class NixModel : public BaseCardModel
{
public:
	NixModel();
	~NixModel();
};

class BombGoblinModel : public BaseCardModel
{
public:
	virtual void CardSpecialAbility(
		shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;
	BombGoblinModel();
	~BombGoblinModel();
};

class WarriorModel : public BaseCardModel
{
public:
	WarriorModel();
	~WarriorModel();
};

class OctoEyenormousModel : public BaseCardModel
{
public:
	OctoEyenormousModel();
	~OctoEyenormousModel();
};

class Scholar1Model : public ScholarCardModel
{
public:
	Scholar1Model();
	~Scholar1Model();
};

class Scholar2Model : public ScholarCardModel
{
public:
	Scholar2Model();
	~Scholar2Model();
};

class TinywingModel : public BaseCardModel
{
public:
	TinywingModel();
	~TinywingModel();
};

class FireMageModel : public BaseCardModel
{
public:
	FireMageModel();
	~FireMageModel();
};

class GreenDragonModel : public DragonCardModel
{
public:
	GreenDragonModel();
	~GreenDragonModel();
};

class YellowDragonModel : public DragonCardModel
{
public:
	YellowDragonModel();
	~YellowDragonModel();
};

class RedDragonModel : public DragonCardModel
{
public:
	RedDragonModel();
	~RedDragonModel();
};

class MimicModel : public BaseCardModel
{
public:
	MimicModel();
	~MimicModel();
};

class DualBoxerModel : public BaseCardModel
{
public:
	DualBoxerModel();
	~DualBoxerModel();
};

class MinotaurModel : public BaseCardModel
{
public:
	MinotaurModel();
	~MinotaurModel();
};

class SpiderMonkModel : public BaseCardModel
{
public:
	SpiderMonkModel();
	~SpiderMonkModel();
};

class DwarfModel : public BaseCardModel
{
public:
	DwarfModel();
	~DwarfModel();
};

class VikingSlimeModel : public BaseCardModel
{
public:
	VikingSlimeModel();
	~VikingSlimeModel();
};

class CrystalMageModel : public BaseCardModel
{
public:
	CrystalMageModel();
	~CrystalMageModel();
};

class ElfModel : public BaseCardModel
{
public:
	ElfModel();
	~ElfModel();
};

class PikemanModel : public BaseCardModel
{
public:
	PikemanModel();
	~PikemanModel();
};

class KingModel : public BaseCardModel
{
public:
	virtual void CardSpecialAbility(
		shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;
	KingModel();
	~KingModel();
};

class BloodyBlueModel : public DemonLordAndBloodyBlueModel
{
public:
	BloodyBlueModel();
	~BloodyBlueModel();
};

class AdventurerModel : public BaseCardModel
{
public:
	AdventurerModel();
	~AdventurerModel();
};

class DemonLordModel : public DemonLordAndBloodyBlueModel
{
public:
	DemonLordModel();
	~DemonLordModel();
};