#ifndef __RENDERER__
#define __RENDERER__
#include "Component.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Input.h"
#include "DataStorage.h"
#include "DrawManager.h"
#include "EventManager.h"
#include "Engine.h"
#include "GameObject.h"


class GameObject;


class Component
{
public:
    GameObject * objPtr;
    std::string name;
    
    bool operator==(Component & other)
    {
        return this->name == other.name ? true : false ;
    }
    
    Component()
    {
        name = "Component";
    }
}; 


class Coords : public Component
{
public:
    std::vector <double> rectCoords; 
    int angle = 0;
    
    Coords operator+(Coords& other)
    {
        Coords* mycoords = new Coords;
        mycoords->rectCoords = {this->rectCoords[0]+ other.rectCoords[0], this->rectCoords[1] + other.rectCoords[1]};
        mycoords->angle = this->angle + other.angle;
        return *mycoords;

    }
    
    Coords() : Component() 
    {
        name = typeid(Coords).name();
        rectCoords = std::vector <double> {0,0};
        angle = 0;
    };   
    
    std::vector <int> toSfml()
    {
        std::vector <int> sfmlcoords = {0,0,0};
        sfmlcoords[0] = int(rectCoords[0])  ;
        sfmlcoords[1] =  int (300 -rectCoords[1]);
        sfmlcoords[2] = -angle;
        return sfmlcoords;
    }
};

class Drawable : public sf::Sprite
{
public:

    Drawable() : sf::Sprite()
    {
        
    }
    
    Drawable(sf::Sprite & X) : sf::Sprite(X) {};
    
    Coords localCoords;
    
    void setLocalCoords(double x, double y, double a)
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
        std::list <Drawable> objectsToDraw;
        name = typeid(Renderer).name();
    }
    

    
    void addDrawable(Drawable & X)
    {
        objectsToDraw.push_back(X);
    }
    
    void addDrawable(sf::Sprite & X, double locx, double locy, double a)
    {
       // std::cout << "addDrawable loc coords here are " << locx << " "<< locy << " " << std::endl;
        Drawable myDrawable = X;

        myDrawable.setLocalCoords(locx, locy, a);
        objectsToDraw.push_back(myDrawable);
        
    }
    
    void drawRenderer();

};


class Script : public Component
{
public:
    virtual void start() = 0;
    
    virtual void update() = 0;
    
    Script(): Component()
    {
        name = typeid(Script).name();
    }
    ~Script()
    {
        
    };
};





#endif
