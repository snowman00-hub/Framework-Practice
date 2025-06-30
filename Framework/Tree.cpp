#include "stdafx.h"
#include "Tree.h"

void Tree::setPosition(const sf::Vector2f& pos)
{
	tree.setPosition(pos);
	for (int i = 0; i < branches.size(); i++)
	{
		branches[i].setPosition(pos.x, i * 150.f);
	}
}

void Tree::updateBranches()
{
	for (int i = branchesSide.size() - 1; i > 0; i--)
	{
		branchesSide[i] = branchesSide[i - 1];
	}
	branchesSide[0] = (Sides)Utils::randomRange(0, 3);

	for (int i = 0; i < branchesSide.size(); i++)
	{
		switch (branchesSide[i])
		{
			case Sides::Left:
				branches[i].setScale(-1.f, 1.f);
				break;
			case Sides::Right:
				branches[i].setScale(1.f, 1.f);
				break;
		}
	}
}

void Tree::init()
{
	textureIdTree = "graphics/tree.png";
	textureIdBranches = "graphics/branch.png";

	branches.resize(6);
	branchesSide.resize(6);
}

void Tree::release()
{
}

void Tree::reset()
{
	tree.setTexture(TEXTURE_MGR.get(textureIdTree), true);
	Utils::setOrigin(tree, Origins::TC);
	sf::FloatRect bounds = tree.getLocalBounds();

	for (int i = 0; i < branches.size(); i++)
	{
		branches[i].setTexture(TEXTURE_MGR.get(textureIdBranches));
		branches[i].setOrigin(bounds.width * -0.5f, 0.f);

		branchesSide[i] = (Sides)Utils::randomRange(0, 3);

		switch (branchesSide[i])
		{
			case Sides::Left:
				branches[i].setScale(-1.f, 1.f);
				break;
			case Sides::Right:
				branches[i].setScale(1.f, 1.f);
				break;
		}
	}
	branchesSide[branches.size() - 1] = Sides::None;

	sf::FloatRect windowBounds = FRAMEWORK.getWindowBounds();
	setPosition({ windowBounds.width * 0.5f,0.f });
}

void Tree::update(float dt)
{
	if (InputMgr::getKeyDown(sf::Keyboard::Left) || InputMgr::getKeyDown(sf::Keyboard::Right))
	{
		updateBranches();
	}
}

void Tree::draw(sf::RenderWindow& window)
{
	window.draw(tree);

	for (int i = 0; i < branches.size(); i++)
	{
		if (branchesSide[i] != Sides::None)
		{
			window.draw(branches[i]);
		}
	}
}
