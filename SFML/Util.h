#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <filesystem>
#include <iostream>

class Util
{
public:
	bool static checkCollision(sf::Sprite& object1, sf::Sprite& object2);
	bool static checkCollision(sf::FloatRect object1, sf::FloatRect object2);
	void static handleCollision(sf::Sprite& object1, sf::Sprite& object2);
};

