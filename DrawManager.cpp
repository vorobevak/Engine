#include "DrawManager.h"

void DrawManager::draw()
{
    Engine::getInstance().window()->clear();
    for (Renderer* rend : renderers)
    {
        rend->drawRenderer();
        
    }
    return;
}

void DrawManager::display()
{
    Engine::getInstance().window()->display();
    return;
}
