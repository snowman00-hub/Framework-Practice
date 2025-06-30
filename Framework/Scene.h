#pragma once

class Scene
{
protected:
	std::list<GameObject*> gameObjects;

	std::vector<std::string> textureIds;
	std::vector<std::string> fontIds;
	std::vector<std::string> soundIds;

public:
	const SceneIds Id;

	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void init();
	virtual void release();

	virtual void enter();
	virtual void exit();

	virtual void update(float dt);
	virtual void draw(sf::RenderWindow& window);

	GameObject* addGameObject(GameObject* go);
	void removeGameObject(GameObject* go);

	GameObject* findGameObject(const std::string& name);
};

