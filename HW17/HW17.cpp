#include <iostream>
#include "Vector2d.h"

void task1();

int main()
{
	task1();
}

void task1()
{
	Vector2d vector1 = Vector2d(1, 2);
	Vector2d vector2 = Vector2d(3, 4);
	Vector2d vector3 = vector1 + vector2;
	Vector2d vector4 = vector1 - vector2;
	
	vector4 *= -1;

	float length = vector4();
	std::cout << "Length of vector4: " << length << std::endl;

	std::cout << "Vector4: " << vector4[0] << ", " << vector4[1] << std::endl;

	std::cout << "Vector4: " << vector4 << std::endl;

	std::cin >> vector4;

	int a = 0;


}

