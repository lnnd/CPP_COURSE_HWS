#include "DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray()
{
	size = 0;
	capacity = 0;
	array = new T[size];
}

template<typename T>
inline DynamicArray<T>::DynamicArray(std::size_t size)
{
	this->size = size;
	capacity = size;
	array = new T[size];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
	size = other.size;
	capacity = other.capacity;
	array = new T[size];
	for (std::size_t i = 0; i < size; i++)
	{
		array[i] = other.array[i];
	}
}

template<typename T>
T& DynamicArray<T>::operator=(const T& other)
{
	if (this == &other) {
		return *this;
	}

	delete[] array;

	size = other.size;
	if(capacity < size)
	{
		capacity = size;
	}
	array = new T[other.size];
	for (size_t i = 0; i < other.size; i++)
	{
		array[i] = other.array[i];
	}

	return *this;
}

template<typename T>
T& DynamicArray<T>::operator[](std::size_t index)
{
	return array[index];
}

template<typename T>
void DynamicArray<T>::setSize(std::size_t newSize)
{
	delete[] array;
	size = newSize;
	if (capacity < size)
	{
		capacity = size;
	}
	array = new T[size];
}

template<typename T>
std::size_t DynamicArray<T>::getSize() const
{
	return size;
}

template<typename T>
void DynamicArray<T>::clear()
{
	delete[] array;
	size = 0;
	capacity = 0;
	array = nullptr;
}

template<typename T>
void DynamicArray<T>::push_back(int element)
{
	int* newArray = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newArray[i] = array[i];
	}
	newArray[size] = element; 

	delete[] array; 
	array = newArray; 

	size++; 
	if (capacity < size)
	{
		capacity = size;
	}
}

template<typename T>
void DynamicArray<T>::pop_back()
{
	if (size == 0)
	{
		return;
	}

	T* newArray = new T[size - 1];
	for (size_t i = 0; i < size - 1; i++)
	{
		newArray[i] = array[i];
	}

	delete[] array;
	array = newArray;

	size--;
}

template<typename T>
T DynamicArray<T>::back() const
{
	if (size == 0)
	{
		return -1;
	}

	return array[this->getSize - 1];
}

template<typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace)
{
	if (reservedSpace <= capacity)
	{
		return;
	}

	T* newArray = new T[reservedSpace];
	for (size_t i = 0; i < size; i++)
	{
		newArray[i] = array[i];
	}

	delete[] array;
	array = newArray;
	capacity = reservedSpace;
}

template<typename T>
std::size_t DynamicArray<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
void DynamicArray<T>::shrinkToFit()
{
	if (size == 0)
	{
		delete[] array;
		array = nullptr;
		capacity = 0;
	}
	else
	{
		T* newArray = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			newArray[i] = array[i];
		}

		delete[] array;
		array = newArray;
		capacity = size;
	}
}

template<typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other) const
{
	if (size != other.size)
	{
		return false;
	}

	for (size_t i = 0; i < other.size; i++)
	{
		if (array[i] != other.array[i])
		{
			return false;
		}
	}

	return true;
}
