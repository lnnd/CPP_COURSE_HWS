
#include <iostream>

void task1();
bool task2();
void task3();
void task4();

int main()
{
    task1();
    task2();
    task3();
    task4();
}

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void task1()
{
    int a = 10;
    int b = 20;

    swap(a, b);
    swap(&a, &b);
}

bool calculateSum(const double* arr, int arrSize, double& sum)
{
    for (int i = 0; i < arrSize; i++)
    {
        sum += *(arr + i);
    }

    return (sum > 0) ? true : false;

}

bool task2()
{
    const int LENGTH_ARR = 3;

    double arr[LENGTH_ARR] = { 10, 20, 30 };
    double sum = 0;

    bool result = calculateSum(arr, LENGTH_ARR, sum);

    return result;
} 

bool find(const int* arr, int size, int elem)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elem)
        {
            return true;
        }
    }

    return false;
}

void task3()
{
    const int LENGTH_ARR = 3;

    int arr[LENGTH_ARR] = { 10, 20, 30 };
    int elem = 20;

    bool result = find(arr, LENGTH_ARR, elem);
}

int lastValueOfArray(double* arr, int size, double& lastNum)
{
    for (int i = 0; i < size; i++)
    {
        if ( *(arr + i) == lastNum)
        {
            return i;
        }
    }

    return -1;
}

void task4()
{
    //Find where the element of the array is located and return the index
    //If the element is not found, we return -1
    
    const int LENGTH_ARR = 4;
    double arr[LENGTH_ARR] = { 10, 20, 30, 60 };
    double num = 30;

    int result = lastValueOfArray(arr, LENGTH_ARR, num);
    std::cout << result;
}





























