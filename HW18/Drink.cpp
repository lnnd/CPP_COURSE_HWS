#pragma once
#include "Drink.h"
#include "Coffee.h"
#include "Tea.h"

int arrayCost[6] = { 15, 20, 17, 25, 33, 30 };

Drink* DrinkCreator::createDrink(TypeDrink typeDrink)
{
	int cost = arrayCost[static_cast<int>(typeDrink)];

	if (typeDrink == TypeDrink::Latte)
	{
		return new Latte(cost);
	}
	else if (typeDrink == TypeDrink::Americano)
	{
		return new Americano(cost);
	}
	else if (typeDrink == TypeDrink::Cappuccino)
	{
		return new Cappuccino(cost);
	}
	else if (typeDrink == TypeDrink::Espresso)
	{
		return new Espresso(cost);
	}
	else if (typeDrink == TypeDrink::BlackTea)
	{
		return new BlackTea(cost);
	}
	else if (typeDrink == TypeDrink::GreenTea)
	{
		return new GreenTea(cost);
	}
	return nullptr;
}
