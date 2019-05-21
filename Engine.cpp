#include "Engine.h"
#include "DataStorage.h"
#include "EventManager.h"
#include "DrawManager.h"
#include "GameObject.h"

sf::RenderWindow* Engine::window()
{
    return &(dataStorage->window);
}

void Engine::createGameObject(std::string name)
{
    dataStorage->gameObjects.insert(std::pair<std::string,GameObject>(name, GameObject(name)));

}

GameObject* Engine::getGameObject(std::string name)
{
    auto Iter = dataStorage->gameObjects.find(name);
    if (Iter != dataStorage->gameObjects.end())
    {
        return &(Iter->second);
    }
    else
    {
        
        return nullptr;
    }
}

void Engine::deleteGameObject(std::string name)
{
    auto Iter = dataStorage->gameObjects.find(name);
    if (Iter != dataStorage->gameObjects.end())
    {
        dataStorage->gameObjects.erase(Iter);
    }
    else
    {
        std::cout << "There is no such game object in data storage " << std::endl;
    }
}

Engine::Engine()
{
        drawManager = new DrawManager();
        eventManager = new EventManager();
        dataStorage = new DataStorage();
}


