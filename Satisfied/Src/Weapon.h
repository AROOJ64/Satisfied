#pragma once
#include <SFML/Graphics.hpp>

class Weapon
{
	sf::Sprite sprite;
    sf::Vector2f velocity;
    float currentFrame = 0;

public:
    Weapon(const sf::Texture& texture, float x, float y);

    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    bool isColliding(const sf::FloatRect& playerBounds);
    void update(float deltaTime, sf::Vector2f targetPosition);
    void draw(sf::RenderWindow& window);
    void animate();
    void move(float speed);

};

