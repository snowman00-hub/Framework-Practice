#pragma once
#include "Scene.h"

class SceneGame : public Scene
{
protected:

public:
	SceneGame();
	~SceneGame() override;

	void init() override;

	void enter() override;
	void exit() override;
};

