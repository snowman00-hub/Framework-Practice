#pragma once
#include "SpriteGo.h"
class Cloud : public SpriteGo
{
protected:

public:
	Cloud(const std::string& texId = "", const std::string& name = "");

	float speed = 0.f;
	sf::Vector2f direction;

	void setSide(Sides side);

	void reset() override;
	void update(float dt) override;
};

