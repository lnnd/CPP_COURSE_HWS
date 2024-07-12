#pragma once
#include <string>

//forwad declaration
class Munchkin;

class Runaway
{
public:
	virtual void apply(Munchkin* munchkin) = 0;

	//#TODO: Implement in all children classes, see class Item for reference
	virtual std::string getFullInfo() = 0;// { return ""; }
};

class Runaway_LevelDowngrade : public Runaway
{
public:
	Runaway_LevelDowngrade(int level = 1) : m_levelToDowngrade(level) {}
	void apply(Munchkin* munchkin) override;
	virtual std::string getFullInfo();

protected:
	int m_levelToDowngrade;
};

class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
	Runaway_LevelDowngradeIf(int level, int minimalMunchkinLevel) 
		: Runaway_LevelDowngrade(level), m_minimalMunchkinLevelToApply(minimalMunchkinLevel) {}

	void apply(Munchkin* munchkin) override;
	virtual std::string getFullInfo();

private:
	int m_minimalMunchkinLevelToApply;
};

//Remove a card from hand(modifier) at random
class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
	//#TODO
	void apply(Munchkin* munchkin) override {}
	virtual std::string getFullInfo();
};


//Item 
// MUNCHKIN
// ACTIVE DECK
// DEACTIVED DECK

//Random item removal
class Runaway_ItemEquipedRemoval : public Runaway
{
public:
	//#TODO
	void apply(Munchkin* munchkin) override {}
	virtual std::string getFullInfo();
};

//Remove equiped item from Outfit with biggest base power
class Runaway_BiggestBonusCardRemoval : public Runaway
{
public:
	//#TODO
	void apply(Munchkin* munchkin) override {}

	virtual std::string getFullInfo();
};

