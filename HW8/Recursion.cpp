#include <iostream>

int factorial_Recursion(int result, int count)
{
	if (count == 1)
	{
		return result;
	}

	result = result * --count;

	factorial_Recursion(result, count);
}

void printNaturalNumbers_To_Smallest_Recursion(int count)
{
	if (count == 0)
	{
		return;
	}

	std::cout << count << std::endl;
	printNaturalNumbers_To_Smallest_Recursion(--count);
}

void printNaturalNumbers_To_Largest_Recursion(int count, int current = 1)
{
	if (count <= 0) {
		return;
	}

	std::cout << current << std::endl;
	printNaturalNumbers_To_Largest_Recursion(count - 1, current + 1);
}