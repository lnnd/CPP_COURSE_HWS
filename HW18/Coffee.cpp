#include "Coffee.h"
#include <iostream>

void Espresso::prepare()
{
	std::cout << "Preparing: " << "Espresso" << std::endl;
	std::cout << "Ingredients: 1 spoons of coffee, 1 spoon of sugar" << std::endl;
}

void Cappuccino::prepare()
{
	std::cout << "Preparing: " << "Cappuccino" << std::endl;
	std::cout << "Ingredients: 2 spoons of coffee, 1 spoon of sugar, milk" << std::endl;
}

void Latte::prepare()
{
	std::cout << "Preparing: " << "Latte" << std::endl;
	std::cout << "Ingredients: 2 spoons of coffee, 2 spoon of sugar, milk" << std::endl;
}

void Americano::prepare()
{
	std::cout << "Preparing: " << "Americano" << std::endl;
	std::cout << "Ingredients: 2 spoons of coffee, 1 spoon of sugar" << std::endl;
}


