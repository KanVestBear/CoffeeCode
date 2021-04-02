// input.cpp

#include "kanDevEngine.h"

void kanDevEngine::input(int checkKey){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		gameWindow.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		hero.moveLeft();
	}
	else
	{
		hero.stopLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		hero.moveRight();
	}
	else
	{
		hero.stopRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		hero.moveUp();
	}
	else
	{
		hero.stopUp();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		hero.moveDown();
	}
	else
	{
		hero.stopDown();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{

		hero.shiftOn();

	}
	else{

		hero.shiftOff();

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{

		hero.interact();

	}
	else{

		hero.notInteract();

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{

	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

	}
}