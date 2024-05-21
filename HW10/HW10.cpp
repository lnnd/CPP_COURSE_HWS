
#include <iostream>

void task1();
bool task2();

int main()
{
    task1();
    task2();
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
