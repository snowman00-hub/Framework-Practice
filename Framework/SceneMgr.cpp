#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneGame.h"

void SceneMgr::init()
{
	scenes.push_back(new SceneGame());

	for (auto scene : scenes)
	{
		scene->init();
	}

	currentScene = startScene;
	scenes[(int)currentScene]->enter();
}

void SceneMgr::release()
{
	for (auto scene : scenes)
	{
		if (scene->Id == currentScene)
		{
			scene->exit();
		}
		scene->release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::changeScene(SceneIds id)
{
	nextScene = id;
}

void SceneMgr::update(float dt)
{
	if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->enter();
	}

	scenes[(int)currentScene]->update(dt);
}

void SceneMgr::draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->draw(window);
}