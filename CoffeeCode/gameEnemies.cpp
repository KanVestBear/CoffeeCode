#include "gameEnemies.h"

Enemy::Enemy()
{

	angryState = false;

	enemySpeed = 200;

	srand(time(NULL));

	//enemyType = rand() % 2;

	asset.loadFromFile("assets/graphics/asset.png");

	//enemySprite.setTextureRect(sf::IntRect(0, 192, 64, 64));

	enemySprite.setTexture(enemyTexture);

	enemyTexture.loadFromImage(asset);

	//float enemyScale = (rand() % 222)/100;
	//int scale = enemyScale;

	enemySprite.scale(2, 2);

	enemyPosition.x = 0 + (enemyWayBool * 1366);
	enemyPosition.y = 480 + ((rand() % 6)*16);

	if (enemyWayBool){ enemySprite.setTextureRect(sf::IntRect(0, 192, 64, 64)); }
	else{ enemySprite.setTextureRect(sf::IntRect(384, 192, 64, 64)); };

	//enemyPosition.x = 200;
	//enemyPosition.y = 100;

	enemySprite.setPosition(enemyPosition.x, enemyPosition.y);

}

sf::Vector2f Enemy::getEnemyCoordinate(){

	return enemyPosition;

}

sf::Sprite Enemy::getSprite(){

	return enemySprite;

}

void Enemy::setAngryState(){

	angryState = true;

}

void Enemy::setCalmState(){

	angryState = false;

}

void Enemy::update(float elapsedTime){

	if (enemyWayBool){ enemyPosition.x -= (enemySpeed + 200*angryState) * elapsedTime; }
	else{ enemyPosition.x += (enemySpeed + 200 * angryState) * elapsedTime; };

	CurrentFrame += (10 + angryState * 6 )* elapsedTime;

	if (angryState == 0){

		if (enemyWayBool){

			if (CurrentFrame > 3) CurrentFrame -= 4;
			enemySprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 192, 64, 64));

		}
		else{

			if (CurrentFrame > 3) CurrentFrame -= 3;
			enemySprite.setTextureRect(sf::IntRect(320 + 64 * int(CurrentFrame), 192, 64, 64));

		}

	}
	else{

		if (enemyWayBool){

			if (CurrentFrame > 2) CurrentFrame -= 3;
			enemySprite.setTextureRect(sf::IntRect(192 + 64 * int(CurrentFrame), 192, 64, 64));

		}
		else{

			if (CurrentFrame > 2) CurrentFrame -= 3;
			enemySprite.setTextureRect(sf::IntRect(512 + 64 * int(CurrentFrame), 192, 64, 64));

		}

	}

	enemySprite.setPosition(enemyPosition.x, enemyPosition.y);

}

void Enemy::resetEnemyState(){

	angryState = false;

	enemyWayBool = rand() % 2 == 0;

	enemyPosition.x = -50 + (enemyWayBool * 1500);
	enemyPosition.y = 480 + ((rand() % 6) * 16);

	if (enemyWayBool){ enemySprite.setTextureRect(sf::IntRect(0, 192, 64, 64)); }
	else{ enemySprite.setTextureRect(sf::IntRect(384, 192, 64, 64)); };

	enemySprite.setPosition(enemyPosition.x, enemyPosition.y);

}