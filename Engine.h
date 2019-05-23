#ifndef __ENGINE__
#define __ENGINE__
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class DrawManager;
class EventManager;
class DataStorage;
class LogicsManager;
class PhysicsManager;
class GameObject;

class Engine
{
private:    
    Engine();
    Engine( const Engine&);  
    Engine& operator=( Engine& );
    
public:
    DrawManager* drawManager;
    EventManager* eventManager;
    DataStorage* dataStorage;
    LogicsManager* logicsManager;
    PhysicsManager* physicsManager;
    

    
    void createGameObject(std::string name);
    
    GameObject* getGameObject(std::string name);
    
    void deleteGameObject(std::string name);
    
    sf::RenderWindow * window();
    
    
    static Engine& getInstance() 
    {
        static Engine instance;
        return instance;
    } 
    

}; 


#endif
