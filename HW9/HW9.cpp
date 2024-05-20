#include <iostream>

void task1();

int main()
{
    task1();
}

void translateArray(int numbers[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] > 0)
		{
			numbers[i] *= 2;
		}
		else if (numbers[i] < 0)
		{
			numbers[i] = 0;
		}

		std::cout << numbers[i] << std::endl;
	}
}

void task1()
{
	constexpr int size = 10;
	int numbers[size] = {};

	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter the number (item " << i + 1 << "): ";
		std::cin >> numbers[i];
	}

	translateArray(numbers, size); 
}