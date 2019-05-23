#include "Input.h"
#include "Engine.h"


Input::Input()
{
    
};

bool Input::getKey(KeyCode key)
{
    return isKeyHold[key];
}
/*
bool Input::getKeyDown(KeyCode key)
{
    std::vector <sf::Event> keyPressedEvents = Engine::getInstance().eventManager->getEventsOfType(sf::Event::KeyPressed);

    for (sf::Event event : keyPressedEvents) // по всем нажатым клавишам 
        if (event.key.code == key && isPressedOnce[key])
            return true;
            
    return false;
}

bool Input::getKeyUp(KeyCode key)
{
    std::vector <sf::Event> keyPressedEvents = Engine::getInstance().eventManager->getEventsOfType(sf::Event::KeyReleased);

    for (sf::Event event : keyPressedEvents)
        if (event.key.code == key)
            return true;

    return false;
}
*/
void Input::keyPressed(sf::Keyboard::Key key)
{
    KeyCode keyCode = fromSfmlKey(key);

    isPressedOnce[keyCode] = true;

    if (isKeyHold[keyCode])
        isPressedOnce[keyCode] = false;

    isKeyHold[keyCode] = true;
}

void Input::keyReleased(sf::Keyboard::Key key)
{
    KeyCode keyCode = fromSfmlKey(key);

    isPressedOnce[keyCode] = false;
    isKeyHold[keyCode] = false;
}

KeyCode Input::fromSfmlKey(sf::Keyboard::Key key)
{
    switch(key)
    {
        case KeyCode::W:        return W;
        case KeyCode::A:        return A;
        case KeyCode::S:        return S;
        case KeyCode::D:        return D;
        case KeyCode::Space:    return Space;
    }
}
