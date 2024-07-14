
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void Task1();

int main()
{
    Task1();




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
