
#include "Vector2d.h"

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

void task4()
{
	Vector2d v1(1.0f, 0.0f);
	Vector2d v2(1.0f, 0.0f);
	Vector2d v3(-1.0f, 0.0f);
	Vector2d v4(0.0f, 1.0f);
	Vector2d v5(1.0f, 1.0f);
	Vector2d v6(-1.0f, -1.0f);

	std::cout << "v1 and v2 are " << static_cast<int>(v1.getRelativeState(v2)) << std::endl;
	std::cout << "v1 and v3 are " << static_cast<int>(v1.getRelativeState(v3)) << std::endl;
	std::cout << "v1 and v4 are " << static_cast<int>(v1.getRelativeState(v4)) << std::endl;
	std::cout << "v1 and v5 are " << static_cast<int>(v1.getRelativeState(v5)) << std::endl;
	std::cout << "v1 and v6 are " << static_cast<int>(v1.getRelativeState(v6)) << std::endl;

}