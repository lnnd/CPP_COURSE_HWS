#include "Tea.h"
#include <iostream>

void BlackTea::prepare()
{
	std::cout << "Preparing: " << "Black tea" << "(" << getSize() << ")" << std::endl;
	std::cout << "Ingredients: 1 black tea, 1 spoon of sugar" << std::endl;
}

void GreenTea::prepare()
{
	std::cout << "Preparing: " << "Green tea" << "(" << getSize() << ")" << std::endl;
	std::cout << "Ingredients: 1 green tea, 1 spoon of sugar" << std::endl;
}
