#include <iostream>

enum GameItems
{
    r = 1,
    p,
    s
};

int main()
{
    std::srand(std::time(nullptr));
    const int generatingRang = 3;
    
    while (true)
    {
        int roundsNumber = 0;

        std::cout << "Hello! Welcome to 'Rock Paper Scissors' game for two players.\n";
        std::cout << "Enter rounds number: (-1 to quit): ";
        std::cin >> roundsNumber;
        std::cout << std::endl << std::endl;

        if (roundsNumber == -1)
        {
            std::cout << "BYE-BYE" << std::endl;
            break;
        }

        int playerWin = 0;
        int playerLost = 0;
        int draws = 0;

        for (int i = 0; i < roundsNumber; i++)
        {
            char generatingNum = std::rand() % generatingRang + 1;
            GameItems item = static_cast<GameItems>(generatingNum);

            char playerСhoice;

            std::cout << "To make your turn one of possible symbols:" << std::endl;
            std::cout << "r - rock      p - paper       s - scissors" << std::endl;
            std::cout << "Your choice is ";
            std::cin >> playerСhoice;

            GameItems playerItem;

            switch (playerСhoice) {
            case 'r':
                playerItem = GameItems::r;
                break;
            case 'p':
                playerItem = GameItems::p;
                break;
            case 's':
                playerItem = GameItems::s;
                break;
            default:
                std::cout << "Invalid choice. Please choose again." << std::endl;
                continue;
            }

            if (item == GameItems::r)
            {
                std::cout << "PC choice is " << "r" << std::endl;
            }
            else if (item == GameItems::p)
            {
                std::cout << "PC choice is " << "p" << std::endl;
            }
            else
            {
                std::cout << "PC choice is " << "p" << std::endl;
            }


            if ((playerItem == GameItems::r && item == GameItems::p) ||
                (playerItem == GameItems::p && item == GameItems::s) ||
                (playerItem == GameItems::s && item == GameItems::r))
            {

                // player lost
                playerLost++;
                std::cout << "You LOST" << std::endl;

            }
            else if (playerItem == item)
            {
                // draws
                draws++;
                std::cout << "Draws" << std::endl;
            }
            else
            { 
                // player win
                playerWin++;
                std::cout << "You WIN" << std::endl;
            }

            std::cout << std::endl;
        }

        std::cout << "Thanks for playing. Your final stats:" << std::endl;
        std::cout << "  number of rounds: " << roundsNumber << std::endl;
        std::cout << "  number of wins: " << playerWin << std::endl;
        std::cout << "  number of losses: " << playerLost << std::endl;
        std::cout << "  number of draws: " << draws << std::endl;
    }


    
}


