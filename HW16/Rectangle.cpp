#include "Rectangle.h"

Rectangle::Rectangle()
{
	length = 0;
	height = 0;
}

Rectangle::Rectangle(float m_length, float m_height)
{
	length = m_length;
	height = m_height;
}

Rectangle::~Rectangle()
{
}

float Rectangle::getArea()
{
	return length * height;
}

float Rectangle::getPerimeter()
{
	return length + length + height +  height;
}