#include "stdafx.h"
#include "Framework.h"

void Framework::init(int w, int h, const std::string& t)
{
    window.create(sf::VideoMode(w, h), t);

    TEXTURE_MGR.load(textureIds);
    FONT_MGR.load(fontIds);
    SOUNDBUFFER_MGR.load(soundIds);

    Utils::init();
    InputMgr::init();
    SCENE_MGR.init();
}

void Framework::Do()
{
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        realDeltaTime = deltaTime = dt.asSeconds();
        deltaTime *= timeScale;
        time += deltaTime;
        realTime += realDeltaTime;

        InputMgr::clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputMgr::updateEvent(event);
        }

        // Update
        InputMgr::update(deltaTime);
        SCENE_MGR.update(deltaTime);

        // Draw
        window.clear();
        SCENE_MGR.draw(window);
        window.display();
    }
}

void Framework::release()
{
    SCENE_MGR.release();

    SOUNDBUFFER_MGR.unload(soundIds);
    FONT_MGR.unload(fontIds);
    TEXTURE_MGR.unload(textureIds);
}