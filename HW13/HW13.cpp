
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <random>

const char* filename = "dateGame.txt";
const char* wordles = "wordles.txt";

void startGame();

int main()
{
    startGame();
}

std::string getRandomWord(const std::vector<std::string>& words) {
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

std::string getWordleFromFile()
{
    std::string randomWord = "";
    std::ifstream file(wordles);

    if (file.is_open()) {
     
        std::vector<std::string> words;
        std::string word;
        while (file >> word) {
            words.push_back(word);
        }
        file.close();

        srand(static_cast<unsigned int>(time(nullptr)));
        randomWord = getRandomWord(words);

    }

    return randomWord;
}

std::string getRandomWordle()
{
    return "hello";

    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, alphabet.size() - 1);

    std::string word;
    for (int i = 0; i <= 4; ++i) {
        word += alphabet[dis(gen)];
    }
    return word;
}

int getDay(const std::tm* tmObj)
{
    return tmObj->tm_mday;
}

int getMonth(const std::tm* tmObj)
{
    return tmObj->tm_mon + 1;
}

int getYear(const std::tm* tmObj)
{
    return tmObj->tm_year + 1900;
}

std::string getCurrentDay()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    std::string currentDay = std::to_string(getDay(now)) + "-" + std::to_string(getMonth(now)) + "-" + std::to_string(getYear(now));
    
    return currentDay;
}

bool todayWasGame()
{
    std::string currentDay = getCurrentDay();

    std::string dayFromFile;
    std::ifstream outputfile(filename);
    
    while (std::getline(outputfile, dayFromFile)) { 
        if (currentDay == dayFromFile)
        {
            outputfile.close();
            return true;
        }
    }
    outputfile.close();

    return false;
}

void writeСurrentDate()
{
    std::string currentDay = getCurrentDay();

    std::ofstream inputfile(filename);

    if (inputfile.is_open()) {
        inputfile << currentDay << std::endl;
        inputfile.close();
    }
}

std::string toUpper(std::string wordle)
{
    std::string result;
    for (int i = 0; i < wordle.length(); i++)
    {
        result += std::toupper(wordle[i]);
    }
    return result;
}

std::string tolower(std::string wordle)
{
    std::string result;
    for (int i = 0; i < wordle.length(); i++)
    {
        result += std::tolower(wordle[i]);
    }
    return result;
}

bool getResult(std::string& result, std::string wordle, std::string userWordle)
{
    wordle = tolower(wordle);
    userWordle = tolower(userWordle);

    if (wordle == userWordle)
    {
        result = toUpper(wordle);
        return true;
    }

    result = "*****";

    for (int i = wordle.length() - 1; i >= 0; i--)
    {
        if (wordle[i] == userWordle[i])
        {
            result[i] = std::toupper(wordle[i]);
        }
    }

    for (int i = 0; i < wordle.length(); i++)
    {
        if (result[i] == '*')
        {
            std::string resLower = tolower(result);

            int countWordle = std::count(wordle.begin(), wordle.end(), userWordle[i]);
            int countResult = std::count(resLower.begin(), resLower.end(), userWordle[i]);

            if (countWordle > 0 && countWordle - countResult > 0)
            {
                result[i] = userWordle[i];
            }
        }
    }
    return false;
}

void startGame()
{
    int userSelect = 2;
    std::string wordle;
    std::string userWordle;
    std::string result = "*****";
    
    // Already found! Come back tommorow
    bool wasGame = todayWasGame();

    while (userSelect != 0)
    {
        int numCount = 0;
        std::cout << "1 - Random wordle" << std::endl;
        if (!wasGame)
        {
            std::cout << "2 - Wordle of the day" << std::endl;
        }
        std::cout << "0 - Exit" << std::endl;
        std::cout << "Enter: ";
        std::cin >> userSelect;
        std::cout << std::endl;

        switch (userSelect)
        {
        case 1:
            wordle = getRandomWordle();
            break;
        case 2:
            if (wasGame)
            { 
                continue; 
            }
            wordle = getWordleFromFile();
            break;
        default:
            continue;
        }

        while (true)
        {
            std::cout << "RESULT : " << result << std::endl;
            std::cout << "ENTER  : ";
            std::cin >> userWordle;
            std::cout << std::endl;

            numCount++;

            bool userWin = getResult(result, wordle, userWordle);
            if (userWin)
            {
                std::cout << "that's right!" << std::endl;
                std::cout << "You made " << numCount << " tries!" << std::endl << std::endl;
                if (userSelect == 2)
                {
                    writeСurrentDate();
                }
                wasGame = true;
                break;
            }
        }
    }
}


