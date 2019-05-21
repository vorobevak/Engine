#ifndef __EVENTMANAGER__
#define __EVENTMANAGER__
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Engine;
class DataStorage;

class EventManager
{
public:
    void pollEvents();
    void clearEvents();

};

#endif
