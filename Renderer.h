#ifndef __RENDERER__
#define __RENDERER__
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "DataStorage.h"
#include "DrawManager.h"
#include "EventManager.h"
#include "Engine.h"
#include "GameObject.h"
#include "Component.h"
class GameObject;





class Coords : public Component
{
public:
    std::vector <int> rectCoords; 
    int angle;
    
    Coords operator+(Coords& other)
    {
        Coords* mycoords = new Coords;
        mycoords->rectCoords = {this->rectCoords[0]+ other.rectCoords[0], this->rectCoords[1] + other.rectCoords[1]};
        mycoords->angle = this->angle + other.angle;
        return *mycoords;

    }
    
    Coords() : Component() 
    {
        name = "Coords";
        rectCoords = std::vector <int> (3,0);
        angle = 0;
    };   
};

class Drawable : public sf::Sprite
{
public:

    Drawable() : Sprite()
    {}
    
    Drawable(sf::Sprite & X) : Sprite(X) {};
    
    Coords localCoords;
    
    void setLocalCoords(int x, int y, int a)
    {
        localCoords.rectCoords[0] = x;
        localCoords.rectCoords[1] = y;
        localCoords.angle = a;
    }
    


};

class Renderer : public Component
{
public:
    
    std::list <Drawable> objectsToDraw;
    
    Renderer() : Component() 
    {
        Engine::getInstance().drawManager->renderers.push_back(this);
        name = "Renderer";
    }
    
    void registerRenderer()
    {

        return;
    }
    
    void addDrawable(Drawable & X)
    {
        objectsToDraw.push_back(X);
    }
    
    void addDrawable(sf::Sprite & X, int locx, int locy, int a)
    {
        Drawable newDrawable = X;
        newDrawable.setLocalCoords(locx, locy, a);
        objectsToDraw.push_back(newDrawable);
        
    }
    
    void drawRenderer();

};







#endif
