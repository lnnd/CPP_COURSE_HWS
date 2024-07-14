
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

void Task1();
void Task2();

int main()
{
    Task1();
    
	Task2();
	
	return 0;
}

std::vector<std::string> getStringContainer()
{
	std::vector<std::string> stringContainer = {
		"Jedi",
		"Sith",
		"Force",
		"Skywalker",
		"Vader",
		"Yoda",
		"Kenobi",
		"Palpatine",
		"Anakin",
		"Padme"
	};
	return stringContainer;
}

bool compareByLength(std::string stringFirst, std::string stringSecond)
{
	return stringFirst.length() < stringSecond.length();
}

class FunctorByLenth
{
public:
	FunctorByLenth();
	~FunctorByLenth();

	bool operator()(std::string stringFirst, std::string stringSecond)
	{
		return stringFirst.length() < stringSecond.length();
	}

private:

};

FunctorByLenth::FunctorByLenth()
{
}

FunctorByLenth::~FunctorByLenth()
{
}

void Task1()
{
	std::vector<std::string> stringContainer;

	// a)
	stringContainer = getStringContainer();
	std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);

	// b)
	stringContainer = getStringContainer(); // Reset the container
	std::sort(stringContainer.begin(), stringContainer.end(), FunctorByLenth());

	// c)
	auto lambdaByLenth = [](std::string stringFirst, std::string stringSecond)
	{
		return stringFirst.length() < stringSecond.length();
	};

	stringContainer = getStringContainer(); // Reset the container
	std::sort(stringContainer.begin(), stringContainer.end(), lambdaByLenth);	
}

////////////////////////////////////////////////////////////////////////////////////////////
/////////////// Task 2 

unsigned int countDivisibleBy(const std::vector<int>& vec, int number) 
{
	auto lambda = [number](int i) 
	{ 
		return i % number == 0;
	};

	unsigned int result = std::count_if(vec.begin(), vec.end(), lambda);

	return result;
}

void Task2()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
	int number = 3;

	unsigned int count = countDivisibleBy(vec, number);

	std::cout << "The number of elements divisible by " << number << " is " << count << std::endl;
}
