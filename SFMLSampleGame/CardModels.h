#pragma once
#include "stdafx.h"
#include "BaseCardModel.h"
//set of classes holding models for all cards, special cards override basic special abilities and basic calculations of coefficients 
//special cards performing the same actions as other cards have their new inter-connecting classes

///Model class representing base behaviour of dragon model classes
class DragonCardModel : public BaseCardModel
{
private:
	///@brief method distinguishing types of dragons  
	///@param "dragons" vector holding all dragons on battlefield 
	///@return quantities of dragons of different types
	tuple<int, int, int> CalculateNumberOfDragons(vector<shared_ptr<IGuiElement>> dragons); 
public:
	
	///@brief constructor ascribing strength, name and expected value for dragon model classes 
	///@param "strength" - strength of the card
	///@param "name" - name of the card
	///@param "expectedValue" - expectedValue of the card
	DragonCardModel(int strength, string name, float expectedValue);

	///@brief method perfroming card's special ability, here for all types of dragons
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
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

	///@brief method calcualting play coeffitients of card, here for all types of dragons
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
	///@return calculated play coefficient
	virtual float CalculatePlayCoefficient(shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;
};

///Model class representing base behaviour of scholar model classes
class ScholarCardModel : public BaseCardModel
{
public:
	///@brief constructor ascribing strength, name and expected value for scholar model classes 
	///@param "strength" - strength of the card
	///@param "name" - name of the card
	///@param "expectedValue" - expectedValue of the card
	ScholarCardModel(int strength, string name, float expectedValue);

	///@brief method perfroming card's special ability, here for all types of scholars
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
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

	///@brief method calcualting play coeffitients of card, here for all types of scholars
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
	///@return calculated play coefficient
	virtual float CalculatePlayCoefficient(shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;
};

///Model class representing base behaviour of Demon Lord and Bloody Blue model classes
class DemonLordAndBloodyBlueModel : public BaseCardModel
{
public:
	///@brief constructor ascribing strength, name and expected value for Demon Lord and Bloody Blue model classes 
	///@param "strength" - strength of the card
	///@param "name" - name of the card
	///@param "expectedValue" - expectedValue of the card
	DemonLordAndBloodyBlueModel(int strength, string name, float expectedValue);

	///@brief method perfroming card's special ability, here for Demon Lord and Bloody Blue model classes 
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
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

	///@brief method calcualting play coeffitients of card, here for Demon Lord and Bloody Blue model classes 
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
	///@return calculated play coefficient
	virtual float CalculatePlayCoefficient(shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;
};

///Class representing behaviour of Lorem Ipsum model
class LoremIpsumModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	LoremIpsumModel();
	~LoremIpsumModel();
};

///Class representing behaviour of Ice Queen model
class IceQueenModel : public BaseCardModel
{
	///@brief method responsible for inserting Ice Queen card and Nix cards in normal way
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	void NormalInsertCards(shared_ptr<IGuiElement> card,
		BattleField battlefield, ICardModel::CardsVector & userLowerBattlefieldCards,
		ICardModel::CardsVector & userUpperBattlefieldCards);
public:
	///@brief method perfroming card's special ability, here for Ice Queen model 
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
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

	///@brief method calculating play coeffitients of card, here for Ice Queen model
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
	///@return calculated play coefficient
	virtual float CalculatePlayCoefficient(shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;

	///@brief constructor ascribing card's strength, name and expected value
	IceQueenModel();
	~IceQueenModel();
};

///Class representing behaviour of Nix model
class NixModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	NixModel();
	~NixModel();
};

///Class representing behaviour of Bomb Goblin model
class BombGoblinModel : public BaseCardModel
{
public:
	///@brief method perfroming card's special ability, here for Bomb goblin model
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
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

	///@brief method calculating play coeffitients of card, here for Bomb Goblin model
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
	///@return calculated play coefficient
	virtual float CalculatePlayCoefficient(shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;

	///@brief constructor ascribing card's strength, name and expected value
	BombGoblinModel();
	~BombGoblinModel();
};

///Class representing behaviour of Warrior model
class WarriorModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	WarriorModel();
	~WarriorModel();
};

///Class representing behaviour of OctoEyenormous model
class OctoEyenormousModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	OctoEyenormousModel();
	~OctoEyenormousModel();
};

///Class representing behaviour of Scholar1 model
class Scholar1Model : public ScholarCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	Scholar1Model();
	~Scholar1Model();
};

///Class representing behaviour of Scholar2 model
class Scholar2Model : public ScholarCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	Scholar2Model();
	~Scholar2Model();
};

///Class representing behaviour of Tinywing model
class TinywingModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	TinywingModel();
	~TinywingModel();
};

///Class representing behaviour of Fire Mage model
class FireMageModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	FireMageModel();
	~FireMageModel();
};

///Class representing behaviour of Green Dragon model
class GreenDragonModel : public DragonCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	GreenDragonModel();
	~GreenDragonModel();
};

///Class representing behaviour of Yellow Dragon model
class YellowDragonModel : public DragonCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	YellowDragonModel();
	~YellowDragonModel();
};

///Class representing behaviour of Red Dragon model
class RedDragonModel : public DragonCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	RedDragonModel();
	~RedDragonModel();
};

///Class representing behaviour of Mimic model
class MimicModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	MimicModel();
	~MimicModel();
};

///Class representing behaviour of Dual Boxer model
class DualBoxerModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	DualBoxerModel();
	~DualBoxerModel();
};

///Class representing behaviour of Minotaur model
class MinotaurModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	MinotaurModel();
	~MinotaurModel();
};

///Class representing behaviour of Spider Monk model
class SpiderMonkModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	SpiderMonkModel();
	~SpiderMonkModel();
};

///Class representing behaviour of Dwarf model
class DwarfModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	DwarfModel();
	~DwarfModel();
};

///Class representing behaviour of Viking Slime model
class VikingSlimeModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	VikingSlimeModel();
	~VikingSlimeModel();
};

///Class representing behaviour of Crystal Mage model
class CrystalMageModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	CrystalMageModel();
	~CrystalMageModel();
};

///Class representing behaviour of Elf model
class ElfModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	ElfModel();
	~ElfModel();
};

///Class representing behaviour of Pikeman model
class PikemanModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	PikemanModel();
	~PikemanModel();
};

///Class representing behaviour of King model
class KingModel : public BaseCardModel
{
public:
	///@brief method perfroming card's special ability, here for King model
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
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

	///@brief method calculating play coeffitients of card, here for King model
	///@param "card" element representing the card
	///@param "battlefield" enum describing battlefield
	///@param "userHandCards" vector holding cards in user's hand
	///@param "userLowerBattlefieldCards" vector holding cards in user's lower battlefield
	///@param "userUpperBattlefieldCards" vector holding cards in user's upper battlefield
	///@param "enemyLowerBattlefieldCards" vector holding cards in oponnent's lower battlefield
	///@param "enemyUpperBattlefieldCards" vector holding cards in oponnent's upper battlefield
	///@param "enemyHandCards" vector holding cards in oponnents's hand
	///@return calculated play coefficient
	virtual float CalculatePlayCoefficient(shared_ptr<IGuiElement> card,
		BattleField battlefield,
		ICardModel::CardsVector& userHandCards,
		ICardModel::CardsVector& userLowerBattlefieldCards,
		ICardModel::CardsVector& userUpperBattlefieldCards,
		ICardModel::CardsVector& enemyLowerBattlefieldCards,
		ICardModel::CardsVector& enemyUpperBattlefieldCards,
		ICardModel::CardsVector& enemyHandCards
	) override;

	///@brief constructor ascribing card's strength, name and expected value
	KingModel();
	~KingModel();
};

///Class representing behaviour of Bloody Blue model
class BloodyBlueModel : public DemonLordAndBloodyBlueModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	BloodyBlueModel();
	~BloodyBlueModel();
};

///Class representing behaviour of Adventurer model
class AdventurerModel : public BaseCardModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	AdventurerModel();
	~AdventurerModel();
};

///Class representing behaviour of Demon Lord model
class DemonLordModel : public DemonLordAndBloodyBlueModel
{
public:
	///@brief constructor ascribing card's strength, name and expected value
	DemonLordModel();
	~DemonLordModel();
};