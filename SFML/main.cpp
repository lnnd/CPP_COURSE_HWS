
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <filesystem>

#include <iostream>

int main() {
	
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML works!");
	
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("character_male.png")) {
        std::cerr << "Error loading texture\n";
        return -1;
    }

    sf::Sprite player;
    player.setTexture(playerTexture);

    sf::Vector2f playerPosition = {window.getSize().x / 2.0f, window.getSize().y / 2.0f};
    player.setPosition(playerPosition);
    player.setOrigin(player.getGlobalBounds().width / 2.0f, player.getGlobalBounds().height / 2.0f);

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

        window.clear(sf::Color(0, 255, 0));

        window.draw(player);

        window.display();
    }

	return 0;
}