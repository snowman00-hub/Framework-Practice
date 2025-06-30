#include "stdafx.h"
#include "Utils.h"
#include <random>

void Utils::init()
{
	srand((int)time(0));
}

float Utils::randomValue()
{
	return (float)rand() / RAND_MAX;
}

int Utils::randomRange(int min, int maxExclude)
{
	return min + rand() % (maxExclude - min);
}

float Utils::randomRange(float min, float max)
{
	return min + (max - min) * rand() / RAND_MAX;
}

sf::Vector2f Utils::setOrigin(sf::Sprite& obj, Origins preset)
{
	sf::FloatRect rect = obj.getLocalBounds();
	sf::Vector2f newOrigin(rect.width, rect.height);

	newOrigin.x *= ((int)preset % 3) * 0.5f;
	newOrigin.y *= ((int)preset / 3) * 0.5f;

	obj.setOrigin(newOrigin);
	return newOrigin;
}

sf::Vector2f Utils::setOrigin(sf::Text& obj, Origins preset)
{
	sf::FloatRect rect = obj.getLocalBounds();
	sf::Vector2f newOrigin(rect.width, rect.height);

	newOrigin.x *= ((int)preset % 3) * 0.5f;
	newOrigin.y *= ((int)preset / 3) * 0.5f;

	obj.setOrigin(newOrigin);
	return newOrigin;
}
