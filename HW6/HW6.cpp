#include <iostream>

void task1();

int main()
{
    task1();
}

void task1()
{
    int num = 0;
    int step = 0;
    int lastNum = 0;

    std::cout << "Enter 3 numbers separated by a space (first number, step, last number)" << std::endl;
    std::cin >> num >> step >> lastNum;

    while (num <= lastNum)
    {
        std::cout << num << std::endl;
        num += step;
    }
}