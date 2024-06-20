#include <iostream>
#include "Vector2d.h"

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();

int main()
{
	// operator=;
	task1();

	// operator+;
	task2();

	// operator-;
	task3();

	// operator*=;
	task4();

	// operator();
	task5();

	// operator[];
	task6();

	// operator<<;
	task7();

	// operator>>;
	task8();

	// getCount();
	task9();
}

void task1()
{
	// operator=;

	Vector2d vector1 = Vector2d(1, 2);
	Vector2d vector2 = vector1;

	vector2.printVector();

}

void task2()
{
	// operator+;

	Vector2d vector1 = Vector2d(1, 2);
	Vector2d vector2 = Vector2d(3, 4);
	Vector2d vector3 = vector1 + vector2;

	vector3.printVector();
}

void task3()
{
	// operator-;

	Vector2d vector1 = Vector2d(1, 2);
	Vector2d vector2 = Vector2d(3, 4);
	Vector2d vector3 = vector1 - vector2;

	vector3.printVector();
}

void task4()
{
	// operator*=;

	Vector2d vector1 = Vector2d(1, 2);
	vector1 *= 2;

	vector1.printVector();
}

void task5()
{
	// operator();

	Vector2d vector1 = Vector2d(3, 4);
	std::cout << vector1() << std::endl;
}

void task6()
{
	// operator[];

	Vector2d vector1 = Vector2d(1, 2);
	std::cout << "X: " << vector1[0 ]<< "Y: " << vector1[1] << std::endl;
}

void task7()
{
	// operator<<;

	Vector2d vector1 = Vector2d(3, 4);
	std::cout << "Vector4: " << vector1 << std::endl;
}

void task8()
{
	// operator>>;

	Vector2d vector1 = Vector2d(3, 4);
	std::cin >> vector1;
}

void task9() 
{
	// getCount();

	std::cout << "Count: " << Vector2d::getCount() << std::endl;
}



