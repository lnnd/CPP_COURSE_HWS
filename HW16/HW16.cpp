#include <iostream>
#include "Rectangle.h"
#include "Coffee.h"
#include "CoffeeShop.cpp"

int main()
{ 
    // task1
    Rectangle rect = Rectangle(5.00, 6.00);
    float area = rect.getArea();
    float perimeter = rect.getPerimeter();

    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;

    //task 2
    Coffee coffee = Coffee(TypeDrink::Latte);
    coffee.prepare();
    std::cout << "Cost: " << coffee.getCost() << std::endl;


    CoffeeShop coffeeShop = CoffeeShop(5, "Olena");
    
    int place = coffeeShop.takePlace();
    coffeeShop.order(place);
    if (coffeeShop.prepare(place)) 
    {
		std::cout << "Your order is ready" << std::endl;
	}
	else {
		std::cout << "Your order is not ready" << std::endl;
	}
        
    bool result = coffeeShop.getReceipt(place);
    
    return 0;

    


}


