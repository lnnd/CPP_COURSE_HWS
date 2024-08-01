
#include "Vector2d.h"

void task1();
void task2();
void task3();

int main()
{
	task1();
	task2();
	task3();


	return 0;
}

void task1()
{
	Vector2d vector = Vector2d(1.0f, 1.0f, 3.0f, 3.0f);
	vector.printVector();
}

void task2()
{
	Vector2d vector1 = Vector2d(1.0f, 1.0f);
	Vector2d vector2 = Vector2d(3.0f, 3.0f);

	float dotProduct = vector1.dotProduct(vector2);

	std::cout << "Dot product: " << dotProduct << std::endl;
}

void task3()
{
	Vector2d vector = Vector2d(5.0f, 7.0f);
	Vector2d negatedVector = vector.negate();

	negatedVector.printVector();
}