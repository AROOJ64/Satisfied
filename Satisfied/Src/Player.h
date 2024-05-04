#pragma once
#include <SFML/Graphics.hpp>

class Player {	

	sf::Sprite sprite;
	sf::Vector2f velocity;
	bool isJumping;
	//bool Alive = true;
	float jumpDuration;
	float currentFrame = 0;

public:
	
	Player(const sf::Texture& texture, float x, float y);

	void update(float deltaTime, float ground);
	void jump(float jumpSpeed);
	void move(float speed);
	sf::FloatRect GetPlayerBounds() { return sprite.getGlobalBounds(); }
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);

};

