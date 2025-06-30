#include "stdafx.h"
#include "SceneGame.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "Cloud.h"
#include "Tree.h"
#include "Bee.h"

SceneGame::SceneGame()
    : Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::init()
{
    textureIds.push_back("graphics/background.png");
    textureIds.push_back("graphics/cloud.png");
    textureIds.push_back("graphics/tree.png");
    textureIds.push_back("graphics/branch.png");
    textureIds.push_back("graphics/bee.png");

    addGameObject(new SpriteGo("graphics/background.png"));
    for (int i = 0; i < 3; i++)
    {
        addGameObject(new Cloud("graphics/cloud.png"));
    }
    addGameObject(new Tree());
    addGameObject(new Bee("graphics/bee.png"));

    Scene::init();
}

void SceneGame::enter()
{
    Scene::enter();
}

void SceneGame::exit()
{
    Scene::exit();
}