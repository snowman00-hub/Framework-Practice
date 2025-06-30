#pragma once
#include "Singleton.h"

class Framework : public Singleton<Framework>
{
	friend class Singleton<Framework>;

protected:
	Framework() = default;
	~Framework() override = default;

	sf::RenderWindow window;

	sf::Clock clock;
	float timeScale = 1.f;

	float time = 0.f;
	float deltaTime = 0.f;

	float realTime = 0.f;
	float realDeltaTime = 0.f;

	std::vector<std::string> textureIds;
	std::vector<std::string> fontIds;
	std::vector<std::string> soundIds;

public:
	sf::RenderWindow& getWindow() { return window; }

	sf::Vector2u getWindowSize() const { return window.getSize(); }
	sf::Vector2f getWindowSizeF() const { return (sf::Vector2f)window.getSize(); }
	sf::FloatRect getWindowBounds() const
	{
		sf::Vector2f size = getWindowSizeF();
		return sf::FloatRect(0.f, 0.f, size.x, size.y);
	}

	float getTimeScale() const { return timeScale; }
	void setTimeScale(float scale) { timeScale = scale; }

	float getTime() const { return time; }
	float getDeltaTime() const { return deltaTime; }
	float getRealTime() const { return realTime; }
	float getRealDeltaTime() const { return realDeltaTime; }

	virtual void init(int w, int h, const std::string& t);
	virtual void Do();
	virtual void release();
};

#define FRAMEWORK (Framework::instance())