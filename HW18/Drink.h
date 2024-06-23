#pragma once
#include <string>

enum class TypeDrink {
    Espresso = 0,
    Cappuccino,
    Latte,
    Americano,
    BlackTea,
    GreenTea
};

class Drink {
public:
    virtual ~Drink() = default;
    virtual int getCost() = 0;
    virtual void prepare() = 0;
    virtual void setSize(std::string size) = 0;
    virtual std::string getSize() = 0;
    virtual std::string getSizes() = 0;
    
};

class DrinkCreator {
public:
    static Drink* createDrink(TypeDrink drinkType);
};