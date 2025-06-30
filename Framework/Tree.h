#pragma once
#include "GameObject.h"

class Tree : public GameObject
{
protected:
	sf::Sprite tree;
	std::vector<sf::Sprite> branches;
	std::vector<Sides> branchesSide;

	std::string textureIdTree;
	std::string textureIdBranches;

public:
	Tree() = default;
	~Tree() override = default;

	void setPosition(const sf::Vector2f& pos) override;
	void updateBranches();

	void init() override;
	void release() override;
	void reset() override;
	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};