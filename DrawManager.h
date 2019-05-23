#ifndef __DM__
#define __DM__
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DataStorage.h"
#include "EventManager.h"
#include "GameObject.h"
#include "Engine.h"
#include "Renderer.h"

class Renderer;

class DrawManager
{
public:
    std::list <Renderer*> renderers;
    void registerRenderer(Renderer* );
    void draw();
    void display();
}; 

#endif
