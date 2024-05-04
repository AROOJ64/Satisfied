#include "Weapon.h"

Weapon::Weapon(const sf::Texture& texture, float x, float y) {
    this->sprite.setTexture(texture);
    this->sprite.setPosition(x, y);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 130, 130));
}

sf::Vector2f Weapon::getPosition() {
    return sprite.getPosition();
}

void Weapon::setPosition(float x, float y)
{
    this->sprite.setPosition(x,y);
}

bool Weapon::isColliding(const sf::FloatRect& playerBounds) {
    return sprite.getGlobalBounds().intersects(playerBounds);
}

void Weapon::update(float deltaTime, sf::Vector2f targetPosition )
{
    velocity.y += 300.0f;
    sprite.move(velocity * deltaTime);

    if (sprite.getPosition().y >= targetPosition.y) {
        sprite.setPosition(this->sprite.getPosition().x, targetPosition.y);
    }
}

void Weapon::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Weapon::animate()
{
    currentFrame += 0.04;
    if (currentFrame > 7) {
        currentFrame -= 7;
    }
    sprite.setTextureRect(sf::IntRect(130 * int(currentFrame), 0, 130, 130));
}

void Weapon::move(float speed)
{
    velocity.y = speed;
}
