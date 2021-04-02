#include <SFML/Graphics.hpp>
#include <ctime>

class Object{

public:

	Object();

	sf::Sprite getSprite();

	sf::Vector2f getObjectCoordinate();

	void update(float elapsedTime);

	bool restart = false;

private:

	sf::Image asset;
	float CurrentFrame = 0;
	float restartKey = 0;

	sf::Vector2f objectPosition;

	sf::Sprite objectSprite;
	sf::Texture objectTexture;

	bool eKeyPressed;

};