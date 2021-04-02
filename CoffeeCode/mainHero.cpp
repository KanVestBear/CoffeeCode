// mainHero.cpp

#include "mainHero.h"

mainHero::mainHero()
{

	heroSpeed = 250;

	asset.loadFromFile("assets/graphics/asset.png");

	heroTexture.loadFromImage(asset);
	heroSprite.setTexture(heroTexture);

	heroSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));

	heroSprite.scale(4, 4);

	heroPosition.x = 683;
	heroPosition.y = 400;

}

sf::Sprite mainHero::getSprite()
{
	return heroSprite;
}

void mainHero::moveLeft()
{

	leftKeyPressed = true;

}

void mainHero::moveRight()
{

	rightKeyPressed = true;

}

void mainHero::moveUp()
{

	upKeyPressed = true;

}

void mainHero::moveDown()
{

	downKeyPressed = true;

}

void mainHero::stopLeft()
{

	leftKeyPressed = false;

}

void mainHero::stopRight()
{

	rightKeyPressed = false;

}

void mainHero::stopUp()
{

	upKeyPressed = false;

}

void mainHero::stopDown()
{

	downKeyPressed = false;

	heroSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));

}

//

void mainHero::shiftOn(){

	shiftKeyPressed = true;

}

void mainHero::shiftOff(){

	shiftKeyPressed = false;

}

//

void mainHero::update(float elapsedTime){

	if (shiftKeyPressed){

		mainHero::shiftKeyValue = 2;

	}else{

		mainHero::shiftKeyValue = 1;

	}

	bool heroInBorder = 1;
	int shiftKey = 1;

	if (heroPosition.x + 10 <= -120){

		heroInBorder = 0;
		heroPosition.x++;

	}

	if (heroPosition.x + 10 >= 1240){

		heroInBorder = 0;
		heroPosition.x--;

	}

	if (heroPosition.y + 10 <= 335){

		heroInBorder = 0;
		heroPosition.y++;

	}

	if (heroPosition.y + 10 >= 430){

		heroInBorder = 0;
		heroPosition.y--;

	}

	//

	if (rightKeyPressed){

		if (heroInBorder){

			heroPosition.x += shiftKeyValue*heroSpeed * elapsedTime;

		}

		//

		CurrentFrame += 10 * elapsedTime;
		if (CurrentFrame > 10) CurrentFrame -= 10;
		heroSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 0, 64, 64));

		//

	}

	if (leftKeyPressed){

		//

		if (heroInBorder){

			heroPosition.x -= shiftKeyValue*heroSpeed * elapsedTime;

		}

		//

		CurrentFrame += 10 * elapsedTime;
		if (CurrentFrame > 10) CurrentFrame -= 10;
		heroSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 64, 64, 64));

		//

	}

	if (upKeyPressed){

		//

		if (heroInBorder){

			heroPosition.x += shiftKeyValue*0.832*heroSpeed * elapsedTime;
			heroPosition.y -= shiftKeyValue*0.555*heroSpeed * elapsedTime;

		}

		//

		CurrentFrame += 10 * elapsedTime;
		if (CurrentFrame > 10) CurrentFrame -= 10;
		heroSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 0, 64, 64));

		//

	}

	if (downKeyPressed){

		//

		CurrentFrame += 10 * elapsedTime;
		if (CurrentFrame > 10) CurrentFrame -= 10;
		heroSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 64, 64, 64));

		//

		if (heroInBorder){

			heroPosition.x -= shiftKeyValue*0.832*heroSpeed * elapsedTime;
			heroPosition.y += shiftKeyValue*0.555*heroSpeed * elapsedTime;

		}

		//

	}

	heroSprite.setPosition(heroPosition.x, heroPosition.y);

}

sf::Vector2f mainHero::getHeroCoordinate(){

	return mainHero::heroPosition;

}

void mainHero::interact(){

	eKeyPressed = true;

}

void mainHero::notInteract(){

	eKeyPressed = false;

}