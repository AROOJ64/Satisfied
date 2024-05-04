#include "Player.h"

Player::Player(const sf::Texture& texture, float x, float y)
    : isJumping(false), jumpDuration(0.0f) {
    this->sprite.setTexture(texture);
    this->sprite.setPosition(x, y);
    this->sprite.setTextureRect(sf::IntRect(0,0,128,245));
}

void Player::update(float deltaTime, float ground) {
    velocity.y += 0.3f * (2.2f + jumpDuration);
    sprite.move(velocity * deltaTime);

    if (sprite.getPosition().y >= ground) {
        sprite.setPosition(sprite.getPosition().x, ground);
        isJumping = false;
        jumpDuration = 0.0f; 
    }
    else {
        jumpDuration += deltaTime; 
    }
}

void Player::jump(float jumpSpeed) {
    if (!isJumping) {
        velocity.y = -jumpSpeed;
        isJumping = true;
        jumpDuration = 0.0f;
    }
}

void Player::move(float speed) {
    velocity.x = speed;
    if (speed > 0) {
        currentFrame += 0.025;
        if (currentFrame > 6) {
            currentFrame -= 6;
        }
        sprite.setTextureRect(sf::IntRect(128 * int(currentFrame), 0, 128, 245));
    }
    else if (speed < 0) {
        currentFrame += 0.025;
        if (currentFrame > 6) {
            currentFrame -= 6;
        }
        sprite.setTextureRect(sf::IntRect(128 * int(currentFrame) + 128, 0, - 128, 245));
    }
    else {
        sprite.setTextureRect(sf::IntRect(0, 0, 128, 245));
    }
    
}

sf::Vector2f Player::getPosition() {

    return this->sprite.getPosition();
}

void Player::setPosition(sf::Vector2f position)
{
    this->sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}