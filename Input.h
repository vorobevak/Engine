#ifndef __INPUT__
#define __INPUT__
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EventManager.h"
enum KeyCode 
{
    W = sf::Keyboard::Key::W,
    A = sf::Keyboard::Key::A,
    S = sf::Keyboard::Key::S, 
    D = sf::Keyboard::Key::D,
    Space = sf::Keyboard::Key::Space
};

class Input 
{
    
private:
    Input();
    Input( const Input&);  
    Input& operator=( Input& );
public:
    std::map<KeyCode, bool> isKeyHold;
    std::map<KeyCode, bool> isPressedOnce;
    
    void keyPressed(sf::Keyboard::Key key);
    void keyReleased(sf::Keyboard::Key key);
    
    bool getKey(KeyCode key);
    bool getKeyDown(KeyCode key);
    bool getKeyUp(KeyCode key);
    
    KeyCode fromSfmlKey(sf::Keyboard::Key key);
    
    static Input& getInstance() 
    {
        static Input instance;
        return instance;
    } 
    
    
};



#endif
