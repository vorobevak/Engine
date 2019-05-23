#include "Renderer.h"
#include "Component.h"







void Renderer::drawRenderer()
{

   // std::cout << "drawRenderer" << objPtr << std::endl;

    std::vector <int> bodyPosition = objPtr->getComponent<Coords>()->toSfml();
    int bodyx = bodyPosition[0];
    int bodyy = bodyPosition[1];
    int bodya = bodyPosition[2];
    

    for (Drawable element : objectsToDraw)
    {
        std::vector <int> loc = element.localCoords.toSfml();
        int locx = loc[0];
        int locy = loc[1];
        int loca = loc[2];
        element.setPosition(bodyx + locx, bodyy + locy);
        element.setRotation(bodya + loca);
        Engine::getInstance().window()->draw(element);
    }
}


