#pragma once
#include "Drink.h"
#include <string>

class Tea : public Drink
{
public:
	virtual int getCost() = 0;
	virtual void prepare() = 0;

	virtual void setSize(std::string size) = 0;
	virtual std::string getSize() = 0;
	virtual std::string getSizes() = 0;
};

class BlackTea : public Tea
{
public:
	int cost;
	BlackTea(int cost) { this->cost = cost; }
	virtual int getCost() { return cost; };
	virtual void prepare();

	std::string size;
	std::string sizes = "M,L";

	virtual void setSize(std::string size) { this->size = size; };
	virtual std::string getSize() { return size; };
	virtual std::string getSizes() { return sizes; };
};

class GreenTea : public Tea
{
public:
	int cost;
	GreenTea(int cost) { this->cost = cost; }
	virtual int getCost() { return cost; };
	virtual void prepare();

	std::string size;
	std::string sizes = "M,L";

	virtual void setSize(std::string size) { this->size = size; };
	virtual std::string getSize() { return size; };
	virtual std::string getSizes() { return sizes; };
};

