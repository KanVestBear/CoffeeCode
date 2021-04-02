//kanDevEngine.cpp

//#include <iostream>

#include "kanDevEngine.h"

kanDevEngine::kanDevEngine(){

	sf::Vector2f resolution;

	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	gameWindow.create(sf::VideoMode(resolution.x, resolution.y), "KenDev Game Engine", sf::Style::Fullscreen);

	sf::Vector2i localPosition = sf::Mouse::getPosition(gameWindow);
	sf::Mouse::setPosition(sf::Vector2i(100, 200), gameWindow);

	//

	scoreTexture.loadFromFile("assets/graphics/asset.png");
	scoreSprite.setTexture(scoreTexture);
	scoreSprite.setTextureRect(sf::IntRect(0, 512, 128, 128));
	scoreSprite.setScale(2, 2);
	scoreSprite.setPosition(0, 0);

	//

	font.loadFromFile("assets/fonts/pixeboy.ttf");
	scoreText.setFont(font);
	
	std::ostringstream heroScoreString;
	heroScoreString << hero.score;

	scoreText.setString(heroScoreString.str());
	scoreText.setCharacterSize(64);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setPosition(100, 90);


	// buttons

	startButtonTexture.loadFromFile("assets/graphics/asset.png");
	startButtonSprite.setTexture(startButtonTexture);
	startButtonSprite.setTextureRect(sf::IntRect(0, 448, 64, 64));

	startButtonSprite.scale(3.5f, 3.5f);
	startButtonSprite.setPosition(85, 50);

	//

	settingsButtonTexture.loadFromFile("assets/graphics/asset.png");
	settingsButtonSprite.setTexture(settingsButtonTexture);
	settingsButtonSprite.setTextureRect(sf::IntRect(64, 448, 64, 64));

	settingsButtonSprite.scale(3.5f, 3.5f);
	settingsButtonSprite.setPosition(85, 165);

	//

	aboutButtonTexture.loadFromFile("assets/graphics/asset.png");
	aboutButtonSprite.setTexture(aboutButtonTexture);
	aboutButtonSprite.setTextureRect(sf::IntRect(128, 448, 64, 64));

	aboutButtonSprite.scale(3.5f, 3.5f);
	aboutButtonSprite.setPosition(85, 280);

	// background in game

	gameBackgroundTexture.loadFromFile("assets/graphics/gameBackground.png");

	gameBackgroundSprite.setTexture(gameBackgroundTexture);
	gameBackgroundSprite.scale(2, 2);

	// background in menu

	menuBackgroundTexture[0].loadFromFile("assets/graphics/menuBackground1.png");
	menuBackgroundTexture[1].loadFromFile("assets/graphics/menuBackground2.png");
	menuBackgroundTexture[2].loadFromFile("assets/graphics/menuBackground3.png");
	menuBackgroundTexture[3].loadFromFile("assets/graphics/menuBackground4.png");
	menuBackgroundTexture[4].loadFromFile("assets/graphics/menuBackground5.png");
	menuBackgroundTexture[5].loadFromFile("assets/graphics/menuBackground6.png");
	menuBackgroundTexture[6].loadFromFile("assets/graphics/menuBackground7.png");
	menuBackgroundTexture[7].loadFromFile("assets/graphics/menuBackground8.png");
	menuBackgroundTexture[8].loadFromFile("assets/graphics/menuBackground9.png");

	for (int cadrKey = 0; cadrKey < 9; cadrKey++){ 
		menuBackgroundSprite[cadrKey].setTexture(menuBackgroundTexture[cadrKey]);
		menuBackgroundSprite[cadrKey].setScale(2, 2);
	}

}

void kanDevEngine::openGameMenu(){

	while (gameWindow.isOpen())
	{

		sf::Vector2i localPosition = sf::Mouse::getPosition(gameWindow);

		for (float engineKeyCount = 0; engineKeyCount <= 8; engineKeyCount += 0.0078125){


			int checkKey = 1;

			input(checkKey);

			drawMenu(engineKeyCount);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				start();

			}

			if (((localPosition.x >= 42 * 3.5 && localPosition.x <= 188 * 3.5) && (localPosition.y >= 80 * 3.5 && localPosition.y <= 24 * 3.5))){

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{

					start();

				}

			}

		}
	}

};

void kanDevEngine::start(){

	sf::Clock clock;

	while (gameWindow.isOpen())
	{

			if (((programmer.getEnemyCoordinate().x < -100) && (programmer.enemyWayBool == 1)) || ((programmer.getEnemyCoordinate().x > 1450) && (programmer.enemyWayBool == 0))){
				programmer.resetEnemyState();
			}

			int checkKey;

			sf::Time dt = clock.restart();

			float dtAsSeconds = dt.asSeconds();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
				openGameMenu();
			}

			input(checkKey = 2);
			update(dtAsSeconds);


			if (((programmer.getEnemyCoordinate().y) >= (hero.getHeroCoordinate().y + 145)) && ((programmer.getEnemyCoordinate().y) <= (hero.getHeroCoordinate().y + 155))){

				if (((programmer.enemyWayBool == 0) && (hero.getHeroCoordinate().x >= programmer.getEnemyCoordinate().x)) || ((programmer.enemyWayBool == 1) && (hero.getHeroCoordinate().x <= programmer.getEnemyCoordinate().x)))
				{
					programmer.setAngryState();
				}

			}

			if (((programmer.getEnemyCoordinate().y) >= (hero.getHeroCoordinate().y + 145)) && ((programmer.getEnemyCoordinate().y) <= (hero.getHeroCoordinate().y + 155))){

				if (((programmer.enemyWayBool == 0) && (hero.getHeroCoordinate().x <= programmer.getEnemyCoordinate().x)) || ((programmer.enemyWayBool == 1) && (hero.getHeroCoordinate().x >= programmer.getEnemyCoordinate().x)))
				{
					if (programmer.angryState == false){ programmer.setCalmState(); }
				}

			}

			//if (hero.eKeyPressed == true) { std::cout << "--------------------------e-key pressed" << std::endl; }

			//std::cout << std::endl << "(hero) [y: " << hero.getHeroCoordinate().y << " x: " << hero.getHeroCoordinate().x << "]" << std::endl;
			//std::cout << std::endl << "(CoffeeBean) [y: " << coffeeBean.getObjectCoordinate().y << " x: " << coffeeBean.getObjectCoordinate().x << "]" << std::endl;

			if (((coffeeBean.getObjectCoordinate().y) <= (hero.getHeroCoordinate().y + 256)) && ((coffeeBean.getObjectCoordinate().y) >= (hero.getHeroCoordinate().y + 200)) && ((coffeeBean.getObjectCoordinate().x) >= (hero.getHeroCoordinate().x + 64)) && ((coffeeBean.getObjectCoordinate().x) <= (hero.getHeroCoordinate().x + 128))){

				coffeeBean.restart = true;

				hero.score++;

				std::ostringstream heroScoreString;

				heroScoreString << hero.score;

				scoreText.setString(heroScoreString.str());

			}


		drawGame();

	}
}