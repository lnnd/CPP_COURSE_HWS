#include "ItemDeck.h"

#include "Item.h"

ItemDeck::ItemDeck()
{
	//TODO: Move item's database to file in format:
	// type;name; params for the type
	//For example:
	//UndeadWeapon;"Holy Grenade";4		//should call UndeadWeapon("Holy Grenade", 4);

	//TODO: Setup more items of diferent types
	m_itemsDataBase =
	{ new Weapon{"The Sword of DOOM", 5},
	new UndeadWeapon{"Stinky knife", 2},
	new UndeadWeapon{"Holy grenade", 4},
	new HolySword{ "Holy Sword", 10 },
	new MagicShield{ "Magic Shield", 3 } };
}

ItemDeck::~ItemDeck()
{
	//TODO: FREE MEMORY
	for (Item* item : m_itemsDataBase)
	{
		delete item;
	}
}

std::vector<Item*> ItemDeck::generateItems() const
{
	std::vector<Item*> items;
	for (int i = 0; i <= 2;)
	{

		const int choice = std::rand() % m_itemsDataBase.size();
		if (std::find(items.begin(), items.end(), m_itemsDataBase[choice]) == items.end())
		{
			i++;
			items.push_back(m_itemsDataBase[choice]);
		}
		
	}
	
	//TODO: PICK AT RANDOM SEVERAL ITEMS FROM DATABASE AS A PLAYER HAND
	return items;
}
