#include <string>
#include <list>
#include "GameObject.h"
#include "Renderer.h"
#include "PhysicsManager.h"

void GameObject::addRenderer(Renderer* R)
{
    std::cout << "addRenderer" << std::endl;
    if (getComponent<Renderer>() == nullptr)
    {
        components.insert(std::pair<std::string,Component*>(typeid(Renderer).name(), R)); // добавить в словарь
        R->objPtr = this;
        Engine::getInstance().drawManager->registerRenderer(R);
        return;
    }
    
    else
    {
        std::cout << "Renderer already exist" << std::endl;
        return;
    }
}

void GameObject::addScript(Script* S)
{
    std::cout << "addScript" << std::endl;
    if (getComponent<Script>() == nullptr)
    {
        components.insert(std::pair<std::string,Component*>(typeid(Script).name(), S)); // добавить в словарь
        S->objPtr = this;
            std::cout << "YES1" << std::endl;
        Engine::getInstance().logicsManager->registerScript(S);
        return;
    }
    
    else
    {
        std::cout << "Script already exist" << std::endl;
        return;
    }
}

void GameObject::addBoxCollider()
{
    std::cout << "addCollider" << std::endl;

    if (getComponent<BoxCollider>() == nullptr)
    {
        BoxCollider* b = new BoxCollider();
        components.insert(std::pair<std::string,Component*>(typeid(BoxCollider).name(), b)); // добавить в словарь
        b->objPtr = this;

        Engine::getInstance().physicsManager->registerBoxCollider(b);
        return;
    }
    
    else
    {
        std::cout << "BoxCollider already exist" << std::endl;
        return;
    }
    
}

void GameObject::addRigitBody()
{
    std::cout << "addRigitBody" << std::endl;

    if (getComponent<RigitBody>() == nullptr)
    {
        RigitBody* r = new RigitBody();
        components.insert(std::pair<std::string,Component*>(typeid(RigitBody).name(), r)); // добавить в словарь
        r->objPtr = this;

        Engine::getInstance().physicsManager->registerRigitBody(r);
        return;
    }
    
    else
    {
        std::cout << "RigitBody already exist" << std::endl;
        return;
    }
    
}

/*
void GameObject::deleteComponent(std::string componentName)
{
    Component * ptr = getComponent(componentName);
    if (ptr!=nullptr)
    {
        auto Iter = components.begin();
        for (int i = 0; i< components.size();++i)
        {
            if ((*Iter)->name == componentName)
            {
                components.erase(Iter);
                return;
            }
            ++Iter;
        }
    }
    return;
}

*/
