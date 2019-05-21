#include "Renderer.h"

void Renderer::drawRenderer()
{
    Coords* bodyPosition = objPtr->getComponent<Coords>();
    
    for (Drawable element : objectsToDraw)
    {
        Coords position = *bodyPosition + element.localCoords;
        element.setPosition(position.rectCoords[0], position.rectCoords[1]);
        Engine::getInstance().window()->draw(element);
    }
}
