
#include <iostream>

void task1();

int main()
{
    task1();
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

