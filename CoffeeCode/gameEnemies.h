#include <SFML/Graphics.hpp>
#include <ctime>

class Enemy{

public:

	Enemy();

	bool enemyWayBool = rand() % 2 == 0;

	int enemyType = 1;

	void setSprite(int type = 1);

	sf::Sprite getSprite();
	float& zOrder();

	sf::Vector2f getEnemyCoordinate();

	bool angryState = false;
	void setAngryState();
	void setCalmState();
	void resetEnemyState();

	void update(float elapsedTime);

private:

	int enemySpeed;

	sf::Image asset;
	float CurrentFrame = 0;

	int typeKey;

	sf::Vector2f enemyPosition;

	sf::Sprite enemySprite;
	sf::Texture enemyTexture;


};