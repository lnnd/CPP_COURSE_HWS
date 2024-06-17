#include "Coffee.h"
#include <iostream>

int arrayCost[4] = { 15, 20, 17, 25 };

Coffee::Coffee(TypeDrink typeDrink)
{
	this->typeDrink = typeDrink;
	this->cost = arrayCost[static_cast<int>(typeDrink)];
}

void Coffee::prepare()
{
	switch (typeDrink)	
	{
	case TypeDrink::Espresso:
		std::cout << "Preparing: " << "Espresso" << std::endl;
		std::cout << "Ingredients: 1 spoons of coffee, 1 spoon of sugar" << std::endl;
		break;
	case TypeDrink::Cappuccino:
		std::cout << "Preparing: " << "Cappuccino" << std::endl;
		std::cout << "Ingredients: 2 spoons of coffee, 1 spoon of sugar, milk" << std::endl;
		break;
	case TypeDrink::Latte:
		std::cout << "Preparing: " << "Latte" << std::endl;
		std::cout << "Ingredients: 2 spoons of coffee, 2 spoon of sugar, milk" << std::endl;
		break;
	case TypeDrink::Americano:
		std::cout << "Preparing: " << "Americano" << std::endl;
		std::cout << "Ingredients: 2 spoons of coffee, 1 spoon of sugar" << std::endl;
		break;
	default:
		break;
	}
}
