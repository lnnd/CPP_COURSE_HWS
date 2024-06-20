#include "Vector2d.h"
#include <cmath>

Vector2d::Vector2d()
{
	x = 0;
	y = 0;
}

Vector2d::Vector2d(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector)
{
	Vector2d vector = Vector2d(this->x + secondVector.x, this->y + secondVector.y);

	return vector;
}

Vector2d Vector2d::operator-(const Vector2d& secondVector)
{
	Vector2d vector = Vector2d(this->x - secondVector.x, this->y - secondVector.y);

	return vector;
}

void Vector2d::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector)
{
	Vector2d vector = Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);

	return vector;
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector)
{
	Vector2d vector = Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);

	return vector;
}

float Vector2d::operator()()
{
	return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}

const float& Vector2d::operator[](std::size_t idx) const
{
	if (idx == 0)
	{
		return x;
	}
	else if (idx == 1)
	{
		return y;
	}
}

std::ostream& operator<<(std::ostream& os, const Vector2d& vector)
{
    os << "{" << vector.x << "; " << vector.y << "}";
    return os;
}

std::istream& operator>>(std::istream& is, Vector2d& vector)
{
    is >> vector.x >> vector.y;
    return is;
}
