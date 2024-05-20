#include <iostream>

void task1();
void task2();
void task3();
void task4();

int main()
{
    task1();
	task2();
	task3();
	task4();
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

void toUppercase(char str[]) {
	
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 'a' + 'A';
		}
		std::cout << str[i];
		i++;
	}
}

void task2()
{
	const int MAX_LENGTH = 100;
	char str[MAX_LENGTH];

	std::cout << "Enter a string: ";
	std::cin.getline(str, MAX_LENGTH);
	std::cout << "\n";

	toUppercase(str);
}

bool isPalindrom(const char str[]) {
	int left = 0;
	int right = strlen(str) - 1;

	while (left < right) {
		if (str[left] != str[right]) {
			return false;
		}
		left++;
		right--;
	}

	return true;
}

void task3()
{
	const int MAX_LENGTH = 100;
	char str[MAX_LENGTH];

	std::cout << "Enter a string: ";
	std::cin.getline(str, MAX_LENGTH);
	std::cout << "\n";

	if (isPalindrom(str)) {
		std::cout << "The string is a palindrome" << std::endl;
	}
	else {
		std::cout << "The string is NOT a palindrome" << std::endl;
	}
}

bool isVowel(char c) {
	c = std::tolower(c); 
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount) {
	vowelsCount = 0;
	consonantsCount = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		char c = str[i];
		if (std::isalpha(c)) { 
			if (isVowel(c)) {
				vowelsCount++;
			}
			else {
				consonantsCount++;
			}
		}
	}
}

void task4()
{
	const int MAX_LENGTH = 100;
	char str[MAX_LENGTH];
	int vowelsCount, consonantsCount;

	std::cout << "Enter a string: ";
	std::cin.getline(str, MAX_LENGTH);
	std::cout << "\n";

	parseStringLetters(str, vowelsCount, consonantsCount);

	std::cout << "Number of vowels: " << vowelsCount << std::endl;
	std::cout << "Number of consonants: " << consonantsCount << std::endl;


}