
#include <iostream>
#include <unordered_set>

void Task1();

int main()
{
    Task1();

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