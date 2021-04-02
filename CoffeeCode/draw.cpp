// draw.cpp

#include "kanDevEngine.h"
//#include "gameMap.h"

void kanDevEngine::drawGame(){

	gameWindow.clear(sf::Color::White);

	gameWindow.draw(gameBackgroundSprite);
	gameWindow.draw(scoreText);
	gameWindow.draw(coffeeBean.getSprite());

	if ((hero.getHeroCoordinate().y + 150) < programmer.getEnemyCoordinate().y){

		gameWindow.draw(hero.getSprite());
		gameWindow.draw(programmer.getSprite());

	}

	if((hero.getHeroCoordinate().y + 150) > programmer.getEnemyCoordinate().y){

		gameWindow.draw(programmer.getSprite());
		gameWindow.draw(hero.getSprite());

	}


	gameWindow.draw(scoreSprite);
	gameWindow.draw(scoreText);
	gameWindow.display();

}

void kanDevEngine::drawMenu(int key){

	gameWindow.clear(sf::Color::White);

	gameWindow.draw(menuBackgroundSprite[key]);

	gameWindow.draw(startButtonSprite);
	gameWindow.draw(settingsButtonSprite);
	gameWindow.draw(aboutButtonSprite);

	gameWindow.display();

}

