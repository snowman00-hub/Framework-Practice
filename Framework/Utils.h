#pragma once
class Utils
{
public:
	static void init(); 

	// Random
	static float randomValue(); // 0.0f ~ 1.0f
	static int randomRange(int min, int maxExclude);
	static float randomRange(float min, float max);

	// Origin
	static sf::Vector2f setOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f setOrigin(sf::Text& obj, Origins preset);

};

