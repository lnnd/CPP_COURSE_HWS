#pragma once
#include <cstdlib>
#include <xpolymorphic_allocator.h>

//#TODO: Make it template class
//int type should be replace with smth more general
template <typename T>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(std::size_t size);
    DynamicArray(const DynamicArray& other);   //c-py c-tor, #TODO,change signature if needed

    ~DynamicArray();

    T& operator=(const T& other); //assignment operator, #TODO, change signature if needed

    //validate index always or only in _DEBUG configuration
    T& operator[](std::size_t index);

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();

    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void push_back(int element);


    //#TODO: HW new methods
    void pop_back();    //remove last element
    T back() const;   //get last element

    //https://cplusplus.com/reference/vector/vector/reserve/
    //used to allocate more memory then needed right now
    //to greatly decrease number of heap call for memory reallocation
    //and number of operations to copy old data to new memory chunk
    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const;    //returns reserve size. Should be ALWAYS >= then actual size

    //reduce the capacity to fit its size
    //https://cplusplus.com/reference/vector/vector/shrink_to_fit/
    void shrinkToFit();

    bool operator==(const DynamicArray& other) const;    //#TODO, change signature if needed
private:
    std::size_t size = 0;
    T* array;
    std::size_t capacity = 0;
};

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
DynamicArray<T>::~DynamicArray()
{
	delete[] array;
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





