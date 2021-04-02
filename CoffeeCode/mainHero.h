// mainHero.h

#pragma once
#include <SFML/Graphics.hpp>

class mainHero{

public:

	int score = 0, health = 40;

	mainHero();

	sf::Sprite getSprite();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();

	int shiftKeyValue = 1;
	void shiftOn();
	void shiftOff();

	void interact();
	void notInteract();
	bool eKeyPressed;

	void update(float elapsedTime);

	sf::Vector2f getHeroCoordinate();

private:

	int shiftKey;

	sf::Image asset;
	float CurrentFrame = 0;

	sf::Vector2f heroPosition;

	bool heroInBorder(sf::Vector2f heroPosition);

	sf::Sprite heroSprite;
	sf::Texture heroTexture;

	bool leftKeyPressed;
	bool rightKeyPressed;
	bool upKeyPressed;
	bool downKeyPressed;
	bool shiftKeyPressed;

	float heroSpeed;

};