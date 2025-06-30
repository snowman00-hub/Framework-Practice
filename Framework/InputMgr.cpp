#include "stdafx.h"
#include "InputMgr.h"

std::list<sf::Keyboard::Key> InputMgr::downKeys;
std::list<sf::Keyboard::Key> InputMgr::holdKeys;
std::list<sf::Keyboard::Key> InputMgr::upKeys;

void InputMgr::init()
{
}

void InputMgr::clear()
{
	downKeys.clear();
	upKeys.clear();
}

void InputMgr::updateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
		case sf::Event::KeyPressed:
			if (!contain(holdKeys, ev.key.code))
			{
				downKeys.push_back(ev.key.code);
				holdKeys.push_back(ev.key.code);
			}
			break;
		case sf::Event::KeyReleased:
			remove(holdKeys, ev.key.code);
			upKeys.push_back(ev.key.code);
			break;
	}
}

void InputMgr::update(float dt)
{

}

bool InputMgr::getKeyDown(sf::Keyboard::Key key)
{
	return contain(downKeys, key);
}

bool InputMgr::getKeyUp(sf::Keyboard::Key key)
{
	return contain(upKeys, key);
}

bool InputMgr::getKeyHold(sf::Keyboard::Key key)
{
	return contain(holdKeys, key);
}

bool InputMgr::contain(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	return std::find(list.begin(), list.end(), key) != list.end();
}

void InputMgr::remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}
