#include <string>
#include "Drink.h"
#include <vector>
#include <iostream>
#include <sstream>

class CoffeeShop
{
public:

	std::vector<bool*> m_Tables;
	std::vector<Drink*> m_Orders; 

	std::vector<std::string> split(const std::string& str, char delimiter)
	{
		std::vector<std::string> tokens;
		std::stringstream ss(str);
		std::string token;

		while (std::getline(ss, token, delimiter))
		{
			tokens.push_back(token);
		}

		return tokens;
	}

	CoffeeShop(int TABLES_COUNT, std::string m_name)
	{
		this->TABLES_COUNT = TABLES_COUNT;

		this->m_Tables.resize(TABLES_COUNT);
		for (int i = 0; i < TABLES_COUNT; i++)
			m_Tables[i] = new bool(false);

		this->m_Orders.resize(TABLES_COUNT);
		for (int i = 0; i < TABLES_COUNT; i++)
			m_Orders[i] = nullptr;

		name = m_name;
	}

	std::string getName() { return name; };

	int takePlace()
	{
		for (int i = 0; i < TABLES_COUNT; i++)
			if (!(*m_Tables[i]))
				return i;

		return -1;
	}

	void order(int tableNumber)
	{
		int result;

		while (true)
		{
			std::cout << "Place your order" << std::endl;
			std::cout << "0 - Espresso" << std::endl;
			std::cout << "1 - Cappuccino" << std::endl;
			std::cout << "2 - Latte" << std::endl;
			std::cout << "3 - Americano" << std::endl;
			std::cout << "4 - Black tea" << std::endl;
			std::cout << "5 - Green tea" << std::endl;
			std::cout << "-1 to exit" << std::endl;
			std::cout << "Your choice:";

			std::cin >> result;

			if (result == -1)
				return;

			if (result >= 0 && result <= 5)
				break;
		}

		Drink* drink = DrinkCreator::createDrink(static_cast<TypeDrink>(result));

		std::string Sizes = drink->getSizes();
		std::vector<std::string> vecorSizes = split(Sizes, ',');

		if(vecorSizes.size() == 1)
		{
			drink->setSize(vecorSizes[0]);
		}
		else
		{
			while (true)
			{
				std::cout << "Choose a size" << std::endl;
				for (int i = 0; i < vecorSizes.size(); i++)
				{
					std::cout << vecorSizes[i] << " - " << i << std::endl;
				}
				std::cout << "Your choice:";
				std::cin >> result;
				if (result > 0 && result < vecorSizes.size())
				{
					drink->setSize(vecorSizes[result]);
					break;
				}
			}
		}

		delete m_Tables[tableNumber];
		m_Tables[tableNumber] = new bool(true);

		delete m_Orders[tableNumber];
		m_Orders[tableNumber] = drink;
	}

	bool prepare(int tableNumber)
	{
		if (m_Orders[tableNumber] != nullptr)
		{
			m_Orders[tableNumber]->prepare();
			return true;
		}
		return false;
	}

	bool getReceipt(int tableNumber)
	{
		if (m_Orders[tableNumber] != nullptr)
		{
			int cost = m_Orders[tableNumber]->getCost();
			delete m_Tables[tableNumber];
			m_Tables[tableNumber] = new bool(false);
			delete m_Orders[tableNumber];
			m_Orders[tableNumber] = nullptr;

			std::cout << "Cafe " << name << std::endl;
			std::cout << "Receipt: " << cost << std::endl;

			return true;
		}
		return false;
	}

private:
	int TABLES_COUNT;
	std::string name;
};