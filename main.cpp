#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cassert>
#include "Renderer.h"
#include "DataStorage.h"
#include "DrawManager.h"
#include "EventManager.h"
#include "GameObject.h"
#include "Engine.h"

int main()
{   

    /*
    Engine::getInstance().createGameObject("ball"); 
    Coords crds;
    Renderer rend;
    
    
    Engine::getInstance().getGameObject("ball")->addComponent(crds);
    Engine::getInstance().getGameObject("ball")->addComponent(rend);
    std::cout << Engine::getInstance().getGameObject("ball")->getComponent<Coords>() << std::endl;
    std::cout << Engine::getInstance().getGameObject("ball")->getComponent<Renderer>() << std::endl;
    */
    
    sf::Texture texture;
    texture.loadFromFile("red.png");
    sf::Sprite sprite(texture);
  
    Renderer birdRend;
    birdRend.addDrawable(sprite,0,0,0);
    
    Engine::getInstance().createGameObject("bird");
    Engine::getInstance().getGameObject("bird")->addComponent(birdRend);
    std::cout << "yes" << std::endl;
    Engine::getInstance().getGameObject("bird")->getComponent<Coords>();


    while(Engine::getInstance().window()->isOpen())
    {
        sf::Event event;
        while(Engine::getInstance().window()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Engine::getInstance().window()->close();

            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "Key pressed" << std::endl;
                fflush(0);
            }
        }

    }   
    Engine::getInstance().drawManager->draw();
    Engine::getInstance().drawManager->display();
    
    return 0;
    
}
