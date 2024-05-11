
#include <iostream>
#include <cmath>

#include "HW8.h";
#include "Recursion.h";
#include "Cycle.h";

const float PI = 3.14159;

int main()
{
	int result;

	// Task1
	EnteringNumbers(5);

	// Task2
	result = factorial(5);

	// Task3
	printNaturalNumbers(5);

	// Task 4 (Area)
	getArea(5.0f);

	// Task 4 (Circumference)
	getCircumference(5.0f);
}

void EnteringNumbers(int a)
{
	int positive = 0;
	int negative = 0;
	int zero = 0;

	for (int i = 1; i <= a; i++)
	{
		int num;

		std::cout << "Enter the number: ";
		std::cin >> num;
		std::cout << std::endl;

		if (num > 0)
		{
			positive++;
		}
		else if (num < 0)
		{
			negative++;
		}
		else
		{
			zero++;
		}
	}

	std::cout << "Input " << a << " time(s)" << std::endl;
	std::cout << "Positive: " << positive << " negative: " << negative << " zeroes: " << zero << std::endl;
}

int factorial(int count)
{	
	int result;

	result = factorial_Cycle(count);
	std::cout << "Factorial (Cycle): " << count << " = " << result << std::endl;

	result = factorial_Recursion(count, count);
	std::cout << "Factorial (Recursion): " << count << " = " << result << std::endl;

	return result;
}

void printNaturalNumbers(int count)
{
	std::cout << "Print natural numbers (to smallest - Cycle)" << std::endl;
	printNaturalNumbers_To_Smallest_Cycle(count);
	std::cout << std::endl;
	
	std::cout << "Print natural numbers (to largest - Cycle)" << std::endl;
	printNaturalNumbers_To_Largest_Cycle(count);
	std::cout << std::endl;

	std::cout << "Print natural numbers (to smallest - Recursion)" << std::endl;
	printNaturalNumbers_To_Smallest_Recursion(count);
	std::cout << std::endl;

	std::cout << "Print natural numbers (to largest - Recursion)" << std::endl;
	printNaturalNumbers_To_Largest_Recursion(count);
	std::cout << std::endl;
}

float getArea(float radius)
{
	float result = PI * pow(radius, 2);
	std::cout << "Area = " << result << std::endl;
	return result;
}

float getCircumference(float radius)
{
	float result = 2 * PI * radius ;
	std::cout << "Circumference = " << result << std::endl;
	return result;
}


