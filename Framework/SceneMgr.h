#pragma once
#include "Singleton.h"

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	SceneMgr() = default;
	~SceneMgr() = default;

	std::vector<Scene*> scenes;

	SceneIds startScene = SceneIds::Game;
	SceneIds currentScene = SceneIds::None;
	SceneIds nextScene = SceneIds::None;

public:
	void init();
	void release();

	Scene* getCurrentScene() { return scenes[(int)currentScene]; }
	SceneIds getCurrentSceneId() const { return currentScene; }
	void changeScene(SceneIds id);

	void update(float dt);
	void draw(sf::RenderWindow& window);
};

#define SCENE_MGR (SceneMgr::instance())