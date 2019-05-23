#include "DrawManager.h"

void DrawManager::draw()
{
    Engine::getInstance().window()->clear();
  
    for (Renderer* rend : renderers)
    {
        rend->drawRenderer();
    }
    Engine::getInstance().window()->display();
    return;
}

void DrawManager::display()
{
    Engine::getInstance().window()->display();
    return;
}

void DrawManager::registerRenderer(Renderer* X)
{
    std::cout << "registerRenderer" <<std::endl;
    renderers.push_back(X);
    std::cout << "size of draw manager is " << (renderers).size() << std::endl;
}
