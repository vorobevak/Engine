#ifndef __DATASTORAGE__
#define __DATASTORAGE__
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Renderer.h"
#include "GameObject.h"


class GameObject;
class DataStorage
{
public:

    sf::RenderWindow window;
    std::map <std::string,GameObject> gameObjects;
    
    DataStorage()
    {
         window.create(sf::VideoMode(800, 600), "My window");
    }
}; 

#endif
