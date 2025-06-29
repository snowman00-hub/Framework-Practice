#pragma once

class InputMgr
{
private:
	static std::list<sf::Keyboard::Key> downKeys;
	static std::list<sf::Keyboard::Key> holdKeys;
	static std::list<sf::Keyboard::Key> upKeys;

public:
	static void init();
	static void clear();

	static void updateEvent(const sf::Event& ev);
	static void update(float dt);

	static bool getKeyDown(sf::Keyboard::Key key);
	static bool getKeyUp(sf::Keyboard::Key key);
	static bool getKeyHold(sf::Keyboard::Key key);

	static bool contain(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);
	static void remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key);

};

