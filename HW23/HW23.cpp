
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>

void Task1();
void Task2();

int main()
{
    //Task1();
	Task2();
	
	
	
	return 0;
}

////////////////////////////////////////////////////////////////////
///////////////// task 1 

unsigned int uniqueWordsCount(const std::string& line)
{
	std::unordered_set<std::string> uniqueWords;
    std::string word;
    
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] == ' ')
		{
			uniqueWords.insert(word);
			word.clear();
		}
		else
		{
			word += line[i];
		}
	}
	uniqueWords.insert(word);

	return uniqueWords.size();
}

void Task1()
{
	unsigned int result = uniqueWordsCount("Hello Hey Hello Bye Hey");
	std::cout << "Number of different words - " << result << std::endl;
}

////////////////////////////////////////////////////////////////////
///////////////// task 2

std::string mostOccuredWord(const std::string& line)
{
	std::unordered_map<std::string, int> wordCount; 
	std::stringstream ss(line); 
	std::string word;
	std::string mostOccuredWord;
	int maxCount = 0;

	while (ss >> word) {
		++wordCount[word]; 
	}

	for (const auto& wc : wordCount) {
		if (wc.second > maxCount) {
			maxCount = wc.second;
			mostOccuredWord = wc.first;
		}
	}
	return mostOccuredWord;
}

void Task2()
{
	std::string result = mostOccuredWord("Hello Hey Hello Bye Hey Hey");
	std::cout << "Most occured word - " << result << std::endl;
}