#include "Runaway.h"
#include "Munchkin.h"

void Runaway_LevelDowngrade::apply(Munchkin* munchkin)
{
	munchkin->updateLevelBy(-m_levelToDowngrade);
}

std::string Runaway_LevelDowngrade::getFullInfo()
{
	int a = 0;

	std::string result = "Level downgrade by " + std::to_string(m_levelToDowngrade);

	return result;
}

void Runaway_LevelDowngradeIf::apply(Munchkin* munchkin)
{
	if (munchkin->getLevel() >= m_minimalMunchkinLevelToApply)
	{
		Runaway_LevelDowngrade::apply(munchkin);
	}
}

std::string Runaway_LevelDowngradeIf::getFullInfo()
{
	int a = 0;

	std::string result = "Level downgrade by " + std::to_string(m_levelToDowngrade) + " if level is at least " + std::to_string(m_minimalMunchkinLevelToApply);

	return result;
}

std::string Runaway_ModifierFromHandRemoval::getFullInfo()
{
	int a = 0;

	std::string result = "Remove a card from hand(modifier) at random";

	return result;
}

std::string Runaway_ItemEquipedRemoval::getFullInfo()
{
	int a = 0;

	std::string result = "Remove equiped item at random";

	return result;
}

std::string Runaway_BiggestBonusCardRemoval::getFullInfo()
{
	int a = 0;

	std::string result = "Remove equiped item from Outfit with biggest base power";

	return result;
}


