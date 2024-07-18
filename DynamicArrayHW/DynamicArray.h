#pragma once
#include <cstdlib>

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


