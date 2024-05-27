#include <iostream>

int factorial_Recursion(int result)
{
    if (result == 1) {
        return 1;
    }

    return result * factorial_Recursion(result - 1);
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

void printNaturalNumbers_To_Largest_Recursion(int count)
{
	if (count <= 0) {
		return;
	}

	printNaturalNumbers_To_Largest_Recursion(count - 1);
	std::cout << count << std::endl;
}
