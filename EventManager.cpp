#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EventManager.h"
#include <iostream>
#include "Engine.h"
#include "DataStorage.h"
#include "Input.h"

void EventManager::pollEvents()
{
    sf::Event event;
    while(Engine::getInstance().window()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Engine::getInstance().window()->close();

        if (event.type == sf::Event::KeyPressed)
        {
            //std::cout  << "key pressed " << event.key.code << std::endl;
            Input::getInstance().keyPressed(event.key.code);
            
        }
        if (event.type == sf::Event::KeyReleased)
        {
           // std::cout << "key released " << event.key.code << std::endl;
            Input::getInstance().keyReleased(event.key.code);
        }
        newEvents.push_back(event);
        

    }
 
}

void EventManager::clearEvents()
{
    newEvents.clear();
}

std::vector <sf::Event> EventManager::getEventsOfType(sf::Event::EventType type)
{
    std::vector <sf::Event> eventsOfType;
    for (sf::Event event : newEvents)
    {
        if (event.type == type)
        {
            eventsOfType.push_back(event);
        }
    }
    return eventsOfType;
}


