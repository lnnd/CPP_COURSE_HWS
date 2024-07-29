
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <filesystem>
#include <iostream>
#include "Util.h"

class Boundaries
{
public:
    float leftBoundary;
    float rightBoundary;
    float topBoundary;
    float bottomBoundary;
    float thickness = 10.0f; 

    sf::RectangleShape topRect;
    sf::RectangleShape bottomRect;
    sf::RectangleShape leftRect;
    sf::RectangleShape rightRect;

    Boundaries(sf::RenderWindow& window, float left, float right, float top, float bottom)
    {
        this->leftBoundary = left;
        this->rightBoundary = window.getSize().x - right;
        this->topBoundary = top;
        this->bottomBoundary = window.getSize().y - bottom;
        this->thickness = thickness;
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
};

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML");

    Boundaries boundaries(window, 40.0f, 40.0f, 40.0f, 40.0f); // Добавлен параметр толщины рамки

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

        Util::handleMovement(player);
        Util::handleRotation(player);
        Util::handleScale(player);
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
