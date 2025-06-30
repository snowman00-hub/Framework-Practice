#include "stdafx.h"
#include "Scene.h"

Scene::Scene(SceneIds id)
	: Id(id)
{
}

void Scene::init()
{
	for (auto obj : gameObjects)
	{
		obj->init();
	}
}

void Scene::release()
{
	for (auto obj : gameObjects)
	{
		obj->release();
		delete obj;
	}
	gameObjects.clear();
}

void Scene::enter()
{
	TEXTURE_MGR.load(textureIds);
	FONT_MGR.load(fontIds);
	SOUNDBUFFER_MGR.load(soundIds);

	for (auto obj : gameObjects)
	{
		obj->reset();
	}
}

void Scene::exit()
{
	TEXTURE_MGR.unload(textureIds);
	FONT_MGR.unload(fontIds);
	SOUNDBUFFER_MGR.unload(soundIds);
}

void Scene::update(float dt)
{
	for (auto obj : gameObjects)
	{
		obj->update(dt);
	}
}

void Scene::draw(sf::RenderWindow& window)
{
	for (auto obj : gameObjects)
	{
		obj->draw(window);
	}
}

GameObject* Scene::addGameObject(GameObject* go)
{
	if (std::find(gameObjects.begin(), gameObjects.end(), go) == gameObjects.end())
	{
		gameObjects.push_back(go);
		return go;
	}
	return nullptr;
}

void Scene::removeGameObject(GameObject* go)
{
	gameObjects.remove(go);
}

GameObject* Scene::findGameObject(const std::string& name)
{
	for (auto obj : gameObjects)
	{
		if (obj->getName() == name)
		{
			return obj;
		}
	}
	return nullptr;
}
