#pragma once
#include <vector>
#include "DeckBase.h"

class Item;

class ItemDeck
{
public:
	ItemDeck();
	~ItemDeck();

	std::vector<Item*> generateItems() const;

private:
	std::vector<DeckBase*> m_itemsDataBase;
};