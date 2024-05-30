#include <iostream>
#include <algorithm>
#include <array>

//Sort in ascending way using the bubble sort algorithm
//Input:  5 1 9 7 3
//Output: 1 3 5 7 9
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                std::swap(arr[j - 1], arr[j]);
            }
        }
    }
}

constexpr unsigned int ROWS = 5;
constexpr unsigned int COLUMNS = 6;

enum class SortingDirection
{
    ByRows,
    ByColumns
};

//Sort 2d array using any algorithm (custom quicksort, std::sort, implemented above Bubble Sort
// or using new implementation in-place)
//Input: ByRows
// 1, 5, 4
// 3, 8, 6
// 9, 5, 1
//Output:
// 1, 4, 5
// 3, 6, 8
// 1, 5, 9

//Input: ByColumns
// 1, 5, 4
// 3, 8, 6
// 9, 5, 1
//Output:
// 1, 5, 1
// 3, 5, 4
// 9, 8, 6

void sort(int arr[ROWS][COLUMNS], SortingDirection direction)
{
    if (direction == SortingDirection::ByRows)
    {
        for (unsigned int i = 0; i < ROWS; ++i)
        {
            std::sort(arr[i], arr[i] + COLUMNS);
        }
    }
    else if (direction == SortingDirection::ByColumns)
    {
        for (unsigned int j = 0; j < COLUMNS; ++j)
        {
            std::array<int, ROWS> column;
            for (unsigned int i = 0; i < ROWS; ++i)
            {
                column[i] = arr[i][j];
            }
            std::sort(column.begin(), column.end());
            for (unsigned int i = 0; i < ROWS; ++i)
            {
                arr[i][j] = column[i];
            }
        }
    }
}

void printArray(int arr[ROWS][COLUMNS])
{
    for (unsigned int i = 0; i < ROWS; ++i)
    {
        for (unsigned int j = 0; j < COLUMNS; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    const int SIZE = 5;
    int arr[SIZE] = { 5, 1, 9, 7, 3 };

    bubbleSort(arr, SIZE);
   
    int arr_2d[ROWS][COLUMNS] = {
        {5, 4, 2, 8, 1, 7},
        {9, 0, 3, 6, 5, 4},
        {7, 3, 5, 2, 6, 1},
        {8, 2, 6, 4, 7, 3},
        {1, 5, 8, 3, 2, 9}
    };

    sort(arr_2d, SortingDirection::ByRows);
    std::cout << "\nSorted By Rows:" << std::endl;
    printArray(arr_2d);

    sort(arr_2d, SortingDirection::ByColumns);
    std::cout << "\nSorted By Columns:" << std::endl;
    printArray(arr_2d);

    return 0;
}