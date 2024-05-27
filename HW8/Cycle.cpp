
#include <iostream>

int factorial_Cycle(int count)
{
	int result = count;
	for (int i = count - 1; i > 1; i--)
	{
		result *= i;
	}
	return result;
}

void printNaturalNumbers_To_Smallest_Cycle(int count)
{
	for (int i = count; i > 0; i--)
	{
		std::cout << i << std::endl;
	}
}

void printNaturalNumbers_To_Largest_Cycle(int count)
{
	for (int i = 1; i <= count; i++)
	{
		std::cout << i << std::endl;
	}
}