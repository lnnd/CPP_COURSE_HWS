
#include "Drink.h"
#include <iostream> 
#include "CoffeeShop.cpp"

int main()
{
    //task 2
    Drink* latte = DrinkCreator::createDrink(TypeDrink::Latte);
    latte->prepare();
    std::cout << "Cost: " << latte->getCost() << std::endl;

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