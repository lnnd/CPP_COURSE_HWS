#pragma once
#include <vector>
#include "DeckBase.h"

class Monster;

class MonsterDeck 
{
public:
	MonsterDeck();
	~MonsterDeck();

	Monster* generateMonster() const;

private:
	std::vector<DeckBase*> m_monstersDatabase;
};