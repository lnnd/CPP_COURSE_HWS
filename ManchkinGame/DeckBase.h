#pragma once
#include <vector>


class DeckBase
{
public:
	DeckBase() = default;
	//~DeckBase();

	static DeckBase* generate(const std::vector<DeckBase*>& deck);
};

