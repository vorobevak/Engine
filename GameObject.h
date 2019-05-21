#ifndef __GAMEOBJ__
#define __GAMEOBJ__
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <cassert>
#include "Renderer.h"
#include "Component.h"

class GameObject
{
public:
    
    std::list <Component*> components; 
    void addComponent(Component  &X);



    template <typename T>
    T* getComponent()
    {
        assert (bool(std::is_base_of<Component, T>::value));
        for (auto component : components)
        {
            if (component->name == (std::string(typeid(T).name())).substr(1,-1))
            {
                T* casted = static_cast<T*>(component);
                return casted;
            }
        }
        return nullptr;
    }

    
    void deleteComponent(std::string componentName);
    std::string name;
    GameObject(std::string name)
    {
        this->name = name;
    }

};



#endif
