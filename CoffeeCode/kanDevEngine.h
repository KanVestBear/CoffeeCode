// kanDevEngine.h

#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "mainHero.h"
#include "gameObjects.h"
#include "gameEnemies.h"

class kanDevEngine{
	 
public:

	kanDevEngine();

	void openGameMenu();
	void start();

	sf::Sprite scoreSprite;
	sf::Texture scoreTexture;
	sf::Font font;
	sf::Text scoreText;

	sf::Sprite startButtonSprite;
	sf::Texture startButtonTexture;
	sf::Sprite settingsButtonSprite;
	sf::Texture settingsButtonTexture;
	sf::Sprite aboutButtonSprite;
	sf::Texture aboutButtonTexture;

private:

	sf::RenderWindow gameWindow;

	sf::Image mapImage;

	sf::Texture menuBackgroundTexture[10];
	sf::Sprite menuBackgroundSprite[10];

	sf::Sprite gameBackgroundSprite;
	sf::Texture gameBackgroundTexture;

	int x, y;

	//создаём объекты классов

	mainHero hero;
	Object coffeeBean;
	Enemy programmer;

	void input(int checkKey);
	void update(float dtAsSeconds);
	void drawGame();
	void drawMenu(int n);

};