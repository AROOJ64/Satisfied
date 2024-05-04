#include "Product.h"

Product::Product(const sf::Texture& texture, float x, float y) { 
    this->sprite.setTexture(texture);    
    this->sprite.setPosition(x, y);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 130, 130));
    this->sprite.setScale(0.8, 0.8);
}

sf::Vector2f Product::getPosition() {
    return sprite.getPosition();
}

bool Product::isColliding(const sf::FloatRect& playerBounds) {
    return sprite.getGlobalBounds().intersects(playerBounds);
}

void Product::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Product::animate()
{
    currentFrame += 0.035;
    if (currentFrame > 7) {
        currentFrame -= 7;
    }
    sprite.setTextureRect(sf::IntRect(130 * int(currentFrame), 0, 130, 130));
}
