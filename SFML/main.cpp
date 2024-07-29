
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <filesystem>
#include <iostream>
#include "Util.h"

static sf::RenderWindow window;

class Boundaries
{
public:
	float leftBoundary;
	float rightBoundary;
	float topBoundary;
	float bottomBoundary;
	float thickness;

	sf::RectangleShape topRect;
	sf::RectangleShape bottomRect;
	sf::RectangleShape leftRect;
	sf::RectangleShape rightRect;

	bool isBoundaryCollisions = false;

	Boundaries(sf::RenderWindow& window, float left, float right, float top, float bottom)
	{
		this->leftBoundary = left;
		this->rightBoundary = window.getSize().x - right;
		this->topBoundary = top;
		this->bottomBoundary = window.getSize().y - bottom;
		this->thickness = 10.0f;
	}

	void draw(sf::RenderWindow& window)
	{
		topRect.setSize(sf::Vector2f(rightBoundary - leftBoundary, thickness));
		topRect.setPosition(leftBoundary, topBoundary);
		topRect.setFillColor(sf::Color::Red);

		bottomRect.setSize(sf::Vector2f(rightBoundary - leftBoundary, thickness));
		bottomRect.setPosition(leftBoundary, bottomBoundary - thickness);
		bottomRect.setFillColor(sf::Color::Red);

		leftRect.setSize(sf::Vector2f(thickness, bottomBoundary - topBoundary));
		leftRect.setPosition(leftBoundary, topBoundary);
		leftRect.setFillColor(sf::Color::Red);

		rightRect.setSize(sf::Vector2f(thickness, bottomBoundary - topBoundary));
		rightRect.setPosition(rightBoundary - thickness, topBoundary);
		rightRect.setFillColor(sf::Color::Red);

		window.draw(topRect);
		window.draw(bottomRect);
		window.draw(leftRect);
		window.draw(rightRect);

	}

	bool checkBoundariesCollision(sf::Sprite& object)
	{
		isBoundaryCollisions = false;

		sf::FloatRect globalBounds = object.getGlobalBounds();
		sf::FloatRect topRectBounds = topRect.getGlobalBounds();

		if (Util::checkCollision(globalBounds, topRect.getGlobalBounds())
			|| Util::checkCollision(globalBounds, bottomRect.getGlobalBounds())
			|| Util::checkCollision(globalBounds, leftRect.getGlobalBounds())
			|| Util::checkCollision(globalBounds, rightRect.getGlobalBounds()))
		{
			isBoundaryCollisions = true;
		}

		return isBoundaryCollisions;
	}

	void handleMovement(sf::Sprite& gameObject)
	{
		float DeltaX = 0.0f;
		float DeltaY = 0.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			DeltaY = -10.0f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			DeltaY = 10.0f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			DeltaX = 10.0f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			DeltaX = -10.0f;
		}
		else
		{
			return;
		}

		const sf::Vector2f oldPosition = gameObject.getPosition();
		gameObject.setPosition(oldPosition.x + DeltaX, oldPosition.y + DeltaY);

		if (checkBoundariesCollision(gameObject))
		{
			gameObject.setPosition(oldPosition);
		}

	}

	void handleRotation(sf::Sprite& gameObject)
	{
		const float rotationSpeed = 3.0f;
		float DeltaRotation = 0.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			DeltaRotation = -rotationSpeed;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			DeltaRotation = rotationSpeed;
		}
		else
		{
			return;
		}

		float oldRotation = gameObject.getRotation();

		gameObject.setRotation(gameObject.getRotation() + DeltaRotation);

		if (checkBoundariesCollision(gameObject))
		{
			gameObject.setRotation(oldRotation);
		}	
	}

	void handleScale(sf::Sprite& gameObject)
	{
		const float scaleSpeed = 0.02f;
		float Scale = 0.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			Scale = scaleSpeed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			Scale = -scaleSpeed;
		}

		sf::Vector2f oldScale = gameObject.getScale();

		gameObject.setScale(gameObject.getScale().x + Scale, gameObject.getScale().y + Scale);

		if (checkBoundariesCollision(gameObject))
		{
			gameObject.setScale(oldScale);	
		}
	}
};

int main()
{
	window.create(sf::VideoMode::getDesktopMode(), "SFML");
	
	Boundaries boundaries(window, 40.0f, 40.0f, 40.0f, 40.0f);

	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("character_male.png"))
	{
		std::cerr << "Error loading texture\n";
		return -1;
	}

	sf::Sprite player;
	player.setTexture(playerTexture);

	sf::Vector2f centerPoint = { window.getSize().x / 2.0f, window.getSize().y / 2.0f };

	player.setPosition(centerPoint.x, centerPoint.y / 2.0f);
	player.setOrigin(player.getGlobalBounds().width / 2.0f, player.getGlobalBounds().height / 2.0f);

	sf::Texture boxTexture;
	if (!boxTexture.loadFromFile("bear.png"))
	{
		std::cerr << "Error loading texture\n";
		return -1;
	}

	sf::Sprite box;
	box.setTexture(boxTexture);
	box.setPosition(centerPoint);
	box.setOrigin(box.getGlobalBounds().width / 2.0f, box.getGlobalBounds().height / 2.0f);

	sf::Font DefaultGameFont;
	DefaultGameFont.loadFromFile("arial.ttf");

	sf::Text myText;
	myText.setFont(DefaultGameFont);
	myText.setString("SFML");
	myText.setOrigin(myText.getGlobalBounds().width / 2.0f, myText.getGlobalBounds().height / 2.0f);
	myText.setPosition(window.getSize().x / 2.0f, 3.0f);
	myText.setCharacterSize(40);
	myText.setFillColor(sf::Color::Blue);

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		boundaries.checkBoundariesCollision(player);

		boundaries.handleMovement(player);
		boundaries.handleRotation(player);
		boundaries.handleScale(player);
		Util::handleCollision(player, box);

		window.clear(sf::Color(0, 255, 0));

		window.draw(player);
		window.draw(box);
		window.draw(myText);
		boundaries.draw(window);

		window.display();
	}
	return 0;
}
