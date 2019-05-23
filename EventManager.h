#ifndef __EVENTMANAGER__
#define __EVENTMANAGER__
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
class Engine;
class DataStorage;

class EventManager
{
public:
    std::list <sf::Event> newEvents;
    void pollEvents();
    void clearEvents();
    std::vector <sf::Event> getEventsOfType(sf::Event::EventType);
    

};



#endif
