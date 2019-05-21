#include <string>
#include <list>
#include "GameObject.h"
#include "Renderer.h"

void GameObject::addComponent(Component &X)
{
    if (X.name == "Renderer")
    {   
        Coords mycoords;
        addComponent(mycoords);
    }
    
    X.objPtr = this;
    components.push_back(&X);
    return;
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
