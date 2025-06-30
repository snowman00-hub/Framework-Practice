#include "stdafx.h"
#include "Cloud.h"

Cloud::Cloud(const std::string& texId, const std::string& name)
	: SpriteGo(texId, name)
{
}

void Cloud::setSide(Sides side)
{
	sf::FloatRect bounds = FRAMEWORK.getWindowBounds();

	switch (side)
	{
		case Sides::Left:
			direction = { 1.f,0.f };
			setScale({ -1.f,1.f });
			setPosition({ -150, Utils::randomRange(100.f,500.f) });
			break;
		case Sides::Right:
			direction = { -1.f,0.f };
			setScale({ 1.f,1.f });
			setPosition({ 1920 + 150, Utils::randomRange(100.f,500.f) });
			break;
	}
	speed = Utils::randomRange(200.f, 600.f);
}

void Cloud::reset()
{
	SpriteGo::reset();

	setOrigin(Origins::MC);
	if (Utils::randomValue() < 0.5f)
	{
		setSide(Sides::Left);
	}
	else
	{
		setSide(Sides::Right);
	}
}

void Cloud::update(float dt)
{
	sf::Vector2f pos = getPosition();
	pos += direction * speed * dt;
	setPosition(pos);

	sf::FloatRect bounds = FRAMEWORK.getWindowBounds();
	if (pos.x < -200.f || pos.x > bounds.width + 200.f)
	{
		if (Utils::randomValue() < 0.5f)
		{
			setSide(Sides::Left);
		}
		else
		{
			setSide(Sides::Right);
		}
	}
}
