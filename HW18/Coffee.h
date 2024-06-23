#pragma once
#include "Drink.h"
#include <string>

class Coffee : public Drink
{
public:
	virtual int getCost() = 0;

	virtual void setSize(std::string size) = 0;
	virtual std::string getSize() = 0;
	virtual std::string getSizes() = 0;
};

class Espresso : public Coffee
{
public:
	int cost;
	Espresso(int cost) { this->cost = cost; }
	virtual int getCost() { return cost; };
	virtual void prepare();

	std::string size;
	std::string sizes =  "S";

	virtual void setSize(std::string size) { this->size = size; };
	virtual std::string getSize(){ return size; };
	virtual std::string getSizes() { return sizes; };
};

class Cappuccino : public Coffee
{
public:
	int cost;
	Cappuccino(int cost) { this->cost = cost; }
	virtual int getCost() { return cost; };
	virtual void prepare();

	std::string size;
	std::string sizes = "M,L";

	virtual void setSize(std::string size) { this->size = size; };
	virtual std::string getSize() { return size; };
	virtual std::string getSizes() { return sizes; };
};

class Latte : public Coffee
{
public:
	int cost;
	Latte(int cost) { this->cost = cost; }
	virtual int getCost() { return cost; };
	virtual void prepare();

	std::string size;
	std::string sizes = "M,L,XL";

	virtual void setSize(std::string size) { this->size = size; };
	virtual std::string getSize() { return size; };
	virtual std::string getSizes() { return sizes; }; 
};

class Americano : public Coffee
{
public:
	int cost;
	Americano(int cost) { this->cost = cost; }
	virtual int getCost() { return cost; };
	virtual void prepare();

	std::string size;
	std::string sizes = "M,L,XL";

	virtual void setSize(std::string size) { this->size = size; };
	virtual std::string getSize() { return size; };
	virtual std::string getSizes() { return sizes; };
};