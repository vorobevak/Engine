#ifndef __COMPONENT__
#define __COMPONENT__
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

#endif
