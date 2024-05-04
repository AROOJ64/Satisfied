#pragma once
#include <SFML/Graphics.hpp>

class Product{
	sf::Sprite sprite;
    float currentFrame = 0;

public:
    Product(const sf::Texture& texture, float x, float y);

    sf::Vector2f getPosition();
    bool isColliding(const sf::FloatRect& playerBounds);
    void draw(sf::RenderWindow& window);
    void animate();

};

