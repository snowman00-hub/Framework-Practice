#pragma once
#include "GameObject.h"
class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;

public:
	SpriteGo(const std::string& texId = "", const std::string& name = "");
	~SpriteGo() override = default;

	std::string getTextureId() const { return textureId; }
	void setTextureId(const std::string& texId) { textureId = texId; }

	void setPosition(const sf::Vector2f& pos) override;
	void setRotation(float r) override;
	void setScale(const sf::Vector2f& s) override;
	void setOrigin(const sf::Vector2f& o) override;
	void setOrigin(Origins preset) override;

	void init() override;
	void release() override;
	void reset() override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};

