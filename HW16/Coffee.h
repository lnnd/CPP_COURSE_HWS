#pragma once

int arrayCost[];

enum class TypeDrink
{
	Espresso = 0,
	Cappuccino,
	Latte,
	Americano
};

class Coffee
{
public:
	Coffee(TypeDrink typeDrink);

	void prepare();
	int getCost() { return cost; };

private:
	TypeDrink typeDrink;
	int cost;
};

