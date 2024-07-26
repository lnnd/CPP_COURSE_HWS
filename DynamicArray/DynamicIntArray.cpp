#include "DynamicIntArray.h"
#include <xpolymorphic_allocator.h>

//Implementations go here

DynamicIntArray::DynamicIntArray()
{
	size = 0;
	array = nullptr;
}

DynamicIntArray::DynamicIntArray(std::size_t size)
{
	this->size = size;
	array = new int[size];
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
{
	size = other.size;
	array = new int[size];
	for (std::size_t i = 0; i < size; i++)
	{
		array[i] = other.array[i];
	}
}

DynamicIntArray::~DynamicIntArray()
{
	delete[] array;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
	if(this == &other) {
		return *this;
	}

	delete[] array; 

	size = other.size;
	array = new int[other.size];
	for (size_t i = 0; i < other.size; i++)
	{
		array[i] = other.array[i]; 
	}

	return *this; 

}

int& DynamicIntArray::operator[](std::size_t index)
{
	return array[index];
}

void DynamicIntArray::setSize(std::size_t newSize)
{
	std::size_t minSize = std::min(size, newSize);
	int* newArray = new int[newSize];
	for (std::size_t i = 0; i < minSize; i++)
	{
		newArray[i] = array[i];
	}

	delete[] array;
	size = newSize;
	array = newArray;
}

std::size_t DynamicIntArray::getSize() const
{
	return size;
}

void DynamicIntArray::clear()
{
	delete[] array;
	size = 0;
	array = nullptr;
}

bool DynamicIntArray::operator==(const DynamicIntArray& other)
{
	if (size != other.size)
	{
		return false;
	}

	for (size_t i = 0; i < other.size; i++)
	{
		if(array[i] != other.array[i])
		{
			return false;
		}
	}

	return true;
}

bool DynamicIntArray::operator!=(const DynamicIntArray& other)
{
	if (size != other.size)
	{
		return true;
	}
	return false;
}

void DynamicIntArray::push_back(int element)
{
	int* newArray = new int[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newArray[i] = array[i];
	}
	newArray[size] = element; 

	delete[] array; 
	array = newArray; 

	size++; 
}
