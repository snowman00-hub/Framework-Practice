#include "stdafx.h"
#include "Bee.h"

Bee::Bee(const std::string& texId, const std::string& name)
	: SpriteGo(texId, name)
{
}

void Bee::setSide(Sides side)
{
	sf::FloatRect bounds = FRAMEWORK.getWindowBounds();

	switch (side)
	{
		case Sides::Left:
			direction = { 1.f,0.f };
			setScale({ -1.f,1.f });
			setPosition({ -150, Utils::randomRange(700.f,750.f) });
			break;
		case Sides::Right:
			direction = { -1.f,0.f };
			setScale({ 1.f,1.f });
			setPosition({ 1920 + 150, Utils::randomRange(700.f,750.f) });
			break;
	}
	speed = Utils::randomRange(125.f, 150.f);
	time = 0.f;
}

void Bee::reset()
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

void Bee::update(float dt)
{
	time += dt;
	sf::Vector2f pos = getPosition();
	pos.x += direction.x * speed * dt;
	pos.y += direction.x * sinf(time) * speed * dt;
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