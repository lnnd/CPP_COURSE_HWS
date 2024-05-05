#include <iostream>

void task1();
void task2();
void task3();
void task4();

int main()
{
    task1();
    
    task2();
    
    task3();

    task4();
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

void task4()
{
    int height = 0;
    int width = 0;
    
    std::cout << "Enter the height and width of the triangle (separated by spaces)" << std::endl;
    std::cin >> height >> width;

    if (height <=0 || width <= 0)
    {
        std::cout << "Error number(s)";
        return;
    }

    // A
    for (int i = 0; i < height; i++)
    {
        for (int j = (width - i); j > 0; j--)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // B
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            std::cout << "*";
            if (j == i)
            {
                //std::cout << std::endl;
                break;
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // C
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // D
    for (int i = 1; i <= height; i++)
    {
        for (int k = (i - 1); k > 0; k--)
        {
            std::cout << " ";
        }

        for (int j = 1; j <= width; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // E
    bool bigEven = false;
    
    for (int i = 1; i <= height; i++)
    {
        bigEven = !bigEven;
        bool even = bigEven;

        for (int j = 1; j <= width; j++)
        {
            std::cout << even ? 1 : 0;
            even = !even;
            if (j == i)
            {
                break;
            }
        }
        std::cout << std::endl;
    }
}