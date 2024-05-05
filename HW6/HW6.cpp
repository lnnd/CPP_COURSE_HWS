#include <iostream>

void task1();
void task2();
void task3();

int main()
{
    task1();
    
    task2();
    
    task3();
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

void task3()
{
    int num = 0;

    std::cout << "Enter a positive integer" << std::endl;
    std::cin >> num;

    if (num <= 0)
    {
        std::cout << "Error number";
        return;
    }

    int result = 1;

    for (int i = 1; i <= num; i++)
    {
        result *= i;
    }

    std::cout << "Result: " << result << std::endl;
}