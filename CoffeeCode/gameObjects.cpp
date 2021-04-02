#include "gameObjects.h"


Object::Object(){

	asset.loadFromFile("assets/graphics/asset.png");

	objectTexture.loadFromImage(asset);
	objectSprite.setTextureRect(sf::IntRect(0, 320, 64, 64));

	objectSprite.setTexture(objectTexture);

	objectSprite.scale(0.5f, 0.5f);

	srand(time(NULL));

	objectPosition.x = 0 + (rand() % 48)*16;
	objectPosition.y = 640 - (rand() % 5) * 16;

}

sf::Sprite Object::getSprite(){

	return objectSprite;

}

sf::Vector2f Object::getObjectCoordinate(){

	return Object::objectPosition;

}

void Object::update(float elapsedTime){

	if (Object::restart == true){

		restartKey += 10 * elapsedTime;

		objectPosition.x = -64;
		objectPosition.y = -64;

		if (restartKey >= 120){
			srand(time(NULL));

			objectPosition.x = 0 + (rand() % 48) * 16;
			objectPosition.y = 640 - (rand() % 5) * 16;

			Object::restart = false;
			restartKey = 0;
			CurrentFrame = 0;

		}

	}

	CurrentFrame += 3.5*elapsedTime;

	if (CurrentFrame < 7){ objectSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 320, 64, 64)); }
	if (CurrentFrame == 40){ objectSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 320, 64, 64)); }

	objectSprite.setPosition(objectPosition);

}