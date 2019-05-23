#ifndef __GAMEOBJ__
#define __GAMEOBJ__
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <map>
#include <cassert>
#include "Renderer.h"
#include "LogicsManager.h"
#include "Component.h"
#include "Script.h"

class Coords;
class Renderer;
class Script;
class Component;

class GameObject
{
public:
    
    std::map<std::string, Component*> components;
    std::string name;
    
    GameObject(std::string name)
    {
        this->name = name;
        std::map<std::string, Component*> components;
    }

    template <typename T>
    void addComponent();
    
    void deleteComponent(std::string);
    void addRenderer(Renderer*);
    void addScript(Script*);
    void addBoxCollider();
    void addRigitBody();
    
    
    template <typename T>
    T* getComponent()
    {
        T* ptr = nullptr;

        std::string compName = typeid(T).name();
       
        assert (bool(std::is_base_of<Component, T>::value));
        
        auto Iter = components.find(compName);
        if (Iter != components.end())
        {
            //std::cout << "I've found " << compName << std::endl;
            ptr =  static_cast<T*>(Iter->second);
            //std::cout << "pointer to " << compName << " is " << ptr << std::endl;
            return ptr;
        }
        else
        {
            return nullptr;
        }
        
        
    }

};

template <typename T>
void GameObject::addComponent()
{
    std::cout << "addComponent " << typeid(T).name() << std::endl;
    
    if (getComponent<T>() == nullptr)
    {
        T* t = new T;        // создать экземпляр
        components.insert(std::pair<std::string,Component*>(t->name, t)); // добавить в словарь
        t->objPtr = this;
        return;
    }
    
    else
    {
        std::cout << "Is already exist" << std::endl;
        return;
    }
}


#endif
