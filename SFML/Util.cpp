#include "Util.h"

bool Util::checkCollision(sf::Sprite& object1, sf::Sprite& object2)
{
	if (object1.getGlobalBounds().intersects(object2.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

bool Util::checkCollision(sf::FloatRect object1, sf::FloatRect object2)
{
	if (object1.intersects(object2))
	{
		return true;
	}
	return false;
}

void Util::handleCollision(sf::Sprite& object1, sf::Sprite& object2)
{
	if (checkCollision(object1, object2))
	{
		object1.setColor(sf::Color::Red);
		object2.setColor(sf::Color::Red);
	}
	else
	{
		object1.setColor(sf::Color::White);
		object2.setColor(sf::Color::White);
	}
}




