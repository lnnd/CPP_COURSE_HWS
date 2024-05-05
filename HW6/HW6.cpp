#include <iostream>

void task1();
void task2();

int main()
{
    task1();
    
    task2();
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

void task2()
{
    int num = 0;
    
    std::cout << "Enter the Fibonacci sequence number" << std::endl;
    std::cin >> num;

    if (num <= 0)
    {
        std::cout << "Error number";
        return;
    }

    int f1 = 1;
    int f2 = 0;
    
    for (f1; num > 0; num--)
    {
        int a = f1;
        f1 += f2;
        f2 = a;
    }

    std::cout << f1 << std::endl;
}