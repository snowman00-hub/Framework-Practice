#include "stdafx.h"
#include "SpriteGo.h"

SpriteGo::SpriteGo(const std::string& texId, const std::string& name)
	: GameObject(name), textureId(texId)
{
}

void SpriteGo::setPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position);
}

void SpriteGo::setRotation(float r)
{
	rotation = r;
	sprite.setRotation(rotation);
}

void SpriteGo::setScale(const sf::Vector2f& s)
{
	scale = s;
	sprite.setScale(scale);
}

void SpriteGo::setOrigin(const sf::Vector2f& o)
{
	originPreset = Origins::Custom;
	origin = o;
	sprite.setOrigin(o);
}

void SpriteGo::setOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::setOrigin(sprite, originPreset);
	}
}

void SpriteGo::init()
{
}

void SpriteGo::release()
{
}

void SpriteGo::reset()
{
	sprite.setTexture(TEXTURE_MGR.get(textureId));
	Utils::setOrigin(sprite, originPreset);
}

void SpriteGo::update(float dt)
{
}

void SpriteGo::draw(sf::RenderWindow& window)
{
	if (active)
	{
		window.draw(sprite);
	}
}