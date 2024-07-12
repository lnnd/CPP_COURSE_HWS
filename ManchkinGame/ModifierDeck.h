#pragma once
#include <vector>
#include "DeckBase.h"

//forward declaration to not include header into header which will increase compilation time
class Modifier;

class ModifierDeck
{
public:
	ModifierDeck();
	~ModifierDeck();

	Modifier* generateModifier() const;

	std::vector<Modifier*> generateModifiers() const;

private:
	std::vector<DeckBase*> m_modifiersDatabase;
};