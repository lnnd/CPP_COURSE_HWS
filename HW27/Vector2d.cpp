#include "Vector2d.h"
#include <cmath>

int Vector2d::count = 0;

Vector2d::Vector2d()
{
	x = 0;
	y = 0;

	count++;
}

Vector2d::Vector2d(float x, float y)
{
	this->x = x;
	this->y = y;

	count++;
}

Vector2d::Vector2d(float x0, float y0, float x1, float y1)
{
	x = x1 - x0;
	y = y1 - y0;

	count++;
}

Vector2d::Vector2d(const Vector2d& other)
{
	this->x = other.x;
	this->y = other.y;

	count++;
}

Vector2d& Vector2d::operator=(const Vector2d& other)
{
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
	}

	count++;

	return *this;
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

void Vector2d::printVector()
{
	std::cout << "{" << x << "; " << y << "}" << std::endl;
}

float Vector2d::dotProduct(Vector2d& other) const
{
	return x * other.x + y * other.y;
}

Vector2d Vector2d::negate() const
{
	return Vector2d(-x, -y);
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const
{
	float dot = this->dotProduct(const_cast<Vector2d&>(other));
	float mag1 = std::sqrt(x * x + y * y);
	float mag2 = std::sqrt(other.x * other.x + other.y * other.y);

	if (x == other.x && y == other.y)
	{
		return VectorRelativeState::Identical;
	}
	else if (dot == mag1 * mag2)
	{
		return VectorRelativeState::CoDirected;
	}
	else if (dot == -mag1 * mag2)
	{
		return VectorRelativeState::OppositeDirected;
	}
	else
	{
		float angle = std::acos(dot / (mag1 * mag2)) * 180 / 3.14159265358979323846;
		if (std::abs(angle - 90.0f) < 1e-5)
		{
			return VectorRelativeState::RightAngle;
		}
		else if (angle < 90.0f)
		{
			return VectorRelativeState::AcuteAngle;
		}
		else
		{
			return VectorRelativeState::ObtuseAngle;
		}
	}
}

void Vector2d::scale(float factorX, float factorY)
{
	x *= factorX;
	y *= factorY;
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