#include <iostream>
#include "DynamicIntArray.h"

int main()
{
	//Testing of ALL methods, c-tors, d-tors goes here

	DynamicIntArray arr1 = DynamicIntArray(2);

	DynamicIntArray arr2 = DynamicIntArray();
	arr2.push_back(1);
	arr2.push_back(2);
	arr2.push_back(3);

	for (size_t i = 0; i < arr2.getSize(); i++)
	{
		std::cout << arr2[i] << std::endl;
	}
	
	////////////////////////////////
	DynamicIntArray arr3 = arr2;
	
	for (size_t i = 0; i < arr3.getSize(); i++)
	{
		std::cout << arr3[i] << std::endl;
	}

	////////////////////////////////
	std::cout << "size = " << arr3.getSize() << std::endl;
	arr3.setSize(arr3.getSize() + 1);
	std::cout << "new size = " << arr3.getSize() << std::endl;

	////////////////////////////////
	std::cout << "same arr2 == arr3 = " << (arr2 == arr3) << std::endl;
	std::cout << "same arr3 == arr3 = " << (arr3 == arr3) << std::endl;
	std::cout << "not same arr2 != arr3 = " << (arr2 != arr3) << std::endl;
	std::cout << "not same arr3 != arr3 = " << (arr3 != arr3) << std::endl;

	////////////////////////////////
	std::cout << "clear" << std::endl;
	arr3.clear();
	std::cout << "size = " << arr3.getSize() << std::endl;
}