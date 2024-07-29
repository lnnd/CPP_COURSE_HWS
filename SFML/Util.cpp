#include "Util.h"

bool Util::checkCollision(sf::Sprite& object1, sf::Sprite& object2)
{
    if (object1.getGlobalBounds().intersects(object2.getGlobalBounds()))
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

void Util::handleScale(sf::Sprite& gameObject)
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

void Util::handleRotation(sf::Sprite& gameObject)
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

void Util::handleMovement(sf::Sprite& gameObject)
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


