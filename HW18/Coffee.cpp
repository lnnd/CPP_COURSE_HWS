#include "Coffee.h"
#include <iostream>

void Espresso::prepare()
{
	std::cout << "Preparing: " << "Espresso" << "(" << getSize() << ")" << std::endl;
	std::cout << "Ingredients: 1 spoons of coffee, 1 spoon of sugar" << std::endl;
}

void Cappuccino::prepare()
{
	std::cout << "Preparing: " << "Cappuccino" << "(" << getSize() << ")" << std::endl;
	std::cout << "Ingredients: 2 spoons of coffee, 1 spoon of sugar, milk" << std::endl;
} 

void Latte::prepare()
{
	std::cout << "Preparing: " << "Latte" << "(" << getSize() << ")" << std::endl;
	std::cout << "Ingredients: 2 spoons of coffee, 2 spoon of sugar, milk" << std::endl;
}

void Americano::prepare()
{
	std::cout << "Preparing: " << "Americano" << "(" << getSize() << ")" << std::endl;
	std::cout << "Ingredients: 2 spoons of coffee, 1 spoon of sugar" << std::endl;
}


