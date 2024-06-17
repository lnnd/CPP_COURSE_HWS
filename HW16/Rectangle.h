#pragma once

class Rectangle
{
public:
	Rectangle();
	Rectangle(float m_length, float m_height);
	~Rectangle();

	float getArea();
	float getPerimeter();

private:
	float length;
	float height;
};