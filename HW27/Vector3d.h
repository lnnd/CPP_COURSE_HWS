#pragma once
class Vector3d
{
public:

	float x;
	float y;
	float z;

	Vector3d();
	Vector3d(float x, float y, float z);

	Vector3d crossProduct(const Vector3d& other);

};

