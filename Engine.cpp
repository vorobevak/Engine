#include "Engine.h"
#include "DataStorage.h"
#include "EventManager.h"
#include "DrawManager.h"
#include "GameObject.h"
#include "PhysicsManager.h"
#include <cassert>

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
    GameObject* ptr = nullptr;
    auto Iter = dataStorage->gameObjects.find(name);
    if (Iter != dataStorage->gameObjects.end())
    {
        ptr =  &(Iter->second);
    }
    if (ptr == nullptr)
    {
        std::cout<< "There is no such object" << std::endl;
    }
    assert (ptr !=nullptr);
    return ptr;
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
        logicsManager = new LogicsManager();
        physicsManager = new PhysicsManager();
}


