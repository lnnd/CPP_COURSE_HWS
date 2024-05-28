#include <iostream>

constexpr unsigned int ROWS = 4;
constexpr unsigned int COLUMNS = 6;

/*
* Please, don't input, output your array here
* The sole purpose of this function is to
* return the result of the search, nothing else (aka Single Responsibility Principle)
*/
bool find(int arr_2d[ROWS][COLUMNS], int toFind)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (arr_2d[i][j] == toFind)
            {
                return true;
            }
        }
    }

    return false;
}


//#2
enum class SortingDirection
{
    Ascending,
    Descending
};


/*
* Please, don't input, output your array here
* The sole purpose of this function is to
* check either array is sorted, nothing else (aka Single Responsibility Principle)
*
* {1,2,3,4,5} SortingDirection::Ascending - true, SortingDirection::Descending - false
* {5,4,3,2,1} SortingDirection::Ascending - false, SortingDirection::Descending - true
* {1,2, 5, 4, 3} SortingDirection::Ascending - false, SortingDirection::Descending - false
*/
bool isSorted(const int* arr, int size, SortingDirection direction)
{
    if (direction == SortingDirection::Ascending)
        for (int i = 1; i < size; i++)
        {
            if (arr[i - 1] >= arr[i])
            {
                return false;
            }
        }
    else if (direction == SortingDirection::Descending)
    {
        for (int i = 1; i < size; i++)
        {
            if (arr[i - 1] <= arr[i])
            {
                return false;
            }
        }
    }
    
    return true;
}


//#3_1
void traverseTopDownRightLeftByColumns(int arr_2d[ROWS][COLUMNS])
{
    for (int j = COLUMNS - 1; j >= 0; j--)
    {
        for (int i = ROWS - 1; i >= 0; i--)
        {
            std::cout << arr_2d[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//#3_2
void traverseLeftRightDownTopSwitchingByRows(int arr_2d[ROWS][COLUMNS])
{
    bool ascending = true;
    int i, j;

    for (i = ROWS - 1; i >= 0; i--)
    {
        if (ascending) 
        {
            for (j = 0; j < COLUMNS; j++)
            {
                std::cout << arr_2d[i][j] << " ";
            }
            std::cout << std::endl;
            ascending = !ascending;
        }
        else
        {
            for (j = COLUMNS - 1; j >= 0; j--)
            {
                std::cout << arr_2d[i][j] << " ";
            }
            std::cout << std::endl;
            ascending = !ascending;
        }
    }
}

int main()
{
    int arr_2d[ROWS][COLUMNS] = {
      {11, 12, 13, 14, 15, 16 },
      {21, 22, 23, 24, 25, 26 },
      {31, 32, 33, 34, 35, 36 },
      {41, 42, 43, 44, 45, 46 }
    };

    std::cout << find(arr_2d, 24) << std::endl;

    const int SIZE = 5;
    int arr[SIZE] = { 11, 12, 13, 14, 15 };
    std::cout << "Is sorted Ascending: " << isSorted(arr, SIZE, SortingDirection::Ascending) << std::endl;
    std::cout << "Is sorted Descending: " << isSorted(arr, SIZE, SortingDirection::Descending) << std::endl;

    traverseTopDownRightLeftByColumns(arr_2d);
    traverseLeftRightDownTopSwitchingByRows(arr_2d);
}