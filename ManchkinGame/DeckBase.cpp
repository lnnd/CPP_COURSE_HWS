#include "DeckBase.h"

DeckBase* DeckBase::generate(const std::vector<DeckBase*>& m_Database)
{
	const int choice = std::rand() % m_Database.size();
	return m_Database[choice];
}
