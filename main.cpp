#include "stdafx.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "FrameWork Test!");

	TEXTURE_MGR.load("graphics/player.png");
    sf::Sprite s;
    s.setTexture(TEXTURE_MGR.get("graphics/player.png"));

    while (window.isOpen())
    {
        InputMgr::clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputMgr::updateEvent(event);
        }

        // Update
        InputMgr::update(0.f);

        // Draw
        window.clear();
        window.draw(s);
        window.display();
    }

	return 0;
}