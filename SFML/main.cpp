
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <filesystem>

#include <iostream>

bool checkCollision(sf::Sprite& object1, sf::Sprite& object2)
{
	if (object1.getGlobalBounds().intersects(object2.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

void handleCollision(sf::Sprite& object1, sf::Sprite& object2)
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

    gameObject.setScale(gameObject.getScale().x + Scale, gameObject.getScale().y + Scale);
}

void handleRotation(sf::Sprite& gameObject)
{
    const float rotationSpeed = 3.0f;
    float DeltaRotation = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        DeltaRotation = -rotationSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        DeltaRotation = rotationSpeed;
    }

    gameObject.setRotation(gameObject.getRotation() + DeltaRotation);

}

void handleMovement(sf::Sprite& gameObject)
{
    float DeltaX = 0.0f;
    float DeltaY = 0.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        DeltaY = -10.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        DeltaY = 10.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        DeltaX = 10.0f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        DeltaX = -10.0f;
    }
    const sf::Vector2f oldPosition = gameObject.getPosition();
    gameObject.setPosition(oldPosition.x + DeltaX, oldPosition.y + DeltaY);
}

int main() {
	
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!");
	
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("character_male.png")) {
        std::cerr << "Error loading texture\n";
        return -1;
    }

    sf::Sprite player;
    player.setTexture(playerTexture);

    sf::Vector2f centerPoint = {window.getSize().x / 2.0f, window.getSize().y / 2.0f};
    
    player.setPosition(centerPoint);
    player.setOrigin(player.getGlobalBounds().width / 2.0f, player.getGlobalBounds().height / 2.0f);

    sf::Texture boxTexture;
    if (!boxTexture.loadFromFile("bear.png")) {
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
    myText.setString("Hello World");
    myText.setCharacterSize(48);
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

        handleMovement(player);
        handleRotation(player);
        handleScale(player);
        handleCollision(player, box);

        window.clear(sf::Color(0, 255, 0));

        window.draw(player);
        window.draw(box);
		window.draw(myText);

        window.display();
    }

	return 0;
}