#include "Vector3d.h"

Vector3d::Vector3d()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3d::Vector3d(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3d Vector3d::crossProduct(const Vector3d& other)
{
	Vector3d vector3D = Vector3d(
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x
	);

	return vector3D;
}
