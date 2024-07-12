#pragma once
#include "Tribe.h"
#include <string>
#include "DeckBase.h"

class Item : public DeckBase
{
public:
	virtual int getPower(Tribe monsterTribeModifier) const { return 0; }
	virtual int getBasePower() const { return 0; }

	void setName(const std::string& name) { m_name = name; }
	const std::string getName() const { return m_name; }
	virtual std::string getFullInfo() const = 0;

protected:
	std::string m_name;
	//other fields like description, image, category

private:
};

class Weapon : public Item
{
public:
	Weapon(const std::string& name, int power)
	{
		setName(name);
		m_power = power;
	}

	int getBasePower() const override
	{
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: None\n";
	}

protected:
	int m_power = 0;
};

class UndeadWeapon : public Weapon
{
public:
	UndeadWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)	
		{
		case Tribe::Undead:
			return m_power * 2;
		case Tribe::Human:
		case Tribe::Zombie:
		default:
			return m_power;
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs UNDEADS!\n";
	}
};

class HolySword : public Weapon
{
public:
	HolySword(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Undead:
		case Tribe::Human:
		case Tribe::Zombie:
			return m_power * 10;
		default:
			return m_power;
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", destroys the Zombie!\n";
	}
};

class MagicShield : public Weapon
{
public:
	MagicShield(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::God:
		case Tribe::Human:
			return m_power * 2;
		case Tribe::Zombie:
		case Tribe::Undead:
		default:
			return m_power;
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs Human!\n";
	}
};

//TODO: Add new Item type with unique properties