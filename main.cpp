#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cassert>
#include "Renderer.h"
#include "DataStorage.h"
#include "DrawManager.h"
#include "EventManager.h"
#include "LogicsManager.h"
#include "GameObject.h"
#include "Engine.h"
#include "Script.h"
#include "Input.h"
#include "PhysicsManager.h"

class BirdScript : public Script
{
public:
    int score = 0;
    void start()
    {
        
    };
    void update()
    {
        std::cout << "SCORE IS " << score << std::endl;
        if (Input::getInstance().getKey(KeyCode::W))
        {
            objPtr->getComponent<RigitBody>()->velocity[1] += 0.001;            
        }
        if (Input::getInstance().getKey(KeyCode::A))
        {
            objPtr->getComponent<RigitBody>()->velocity[0] -= 0.001;            
        }
                if (Input::getInstance().getKey(KeyCode::D))
        {
            objPtr->getComponent<RigitBody>()->velocity[0] += 0.001;            
        }
                if (Input::getInstance().getKey(KeyCode::S))
        {
            objPtr->getComponent<RigitBody>()->velocity[1] -= 0.001;            
        }
        /*
        if(objPtr->getComponent<BoxCollider>()->onCollide)
        {
            objPtr->getComponent<RigitBody>()->invertVelocity();
        }*/
    }
    
    BirdScript() : Script() 
    {

    };
    ~BirdScript();
};

class PigScript: public Script
{
public:
    int damage = 0;
    void start()
    {}
    void update()
    {
        if (objPtr->getComponent<BoxCollider>()->onCollide)
        {
            damage+=1;
            for (GameObject* oponent : objPtr->getComponent<BoxCollider>()->opponents)
            {
                if (oponent->name == "bird")
                {
                    BirdScript* scr = static_cast<BirdScript*>(oponent->getComponent<Script>());
                    scr->score +=2;
                }
            }
        }
        
    }
    
    PigScript() : Script() {};
    ~PigScript();
};


BirdScript* birdScript = new BirdScript;
PigScript* pigScript = new PigScript;



void createWalls()
{
Engine::getInstance().createGameObject("wall1");
Engine::getInstance().getGameObject("wall1")->addComponent<Coords>();
Engine::getInstance().getGameObject("wall1")->getComponent<Coords>()->rectCoords = std::vector<double> {400,10};
Engine::getInstance().getGameObject("wall1")->addBoxCollider();
Engine::getInstance().getGameObject("wall1")->getComponent<BoxCollider>()->width = 799;
Engine::getInstance().getGameObject("wall1")->getComponent<BoxCollider>()->height = 100;

Engine::getInstance().createGameObject("wall2");
Engine::getInstance().getGameObject("wall2")->addComponent<Coords>();
Engine::getInstance().getGameObject("wall2")->getComponent<Coords>()->rectCoords = std::vector<double> {780,300};
Engine::getInstance().getGameObject("wall2")->addBoxCollider();
Engine::getInstance().getGameObject("wall2")->getComponent<BoxCollider>()->width = 100;
Engine::getInstance().getGameObject("wall2")->getComponent<BoxCollider>()->height = 599;

    Engine::getInstance().createGameObject("wall3");
Engine::getInstance().getGameObject("wall3")->addComponent<Coords>();
Engine::getInstance().getGameObject("wall3")->getComponent<Coords>()->rectCoords = std::vector<double> {-100,300};
Engine::getInstance().getGameObject("wall3")->addBoxCollider();
Engine::getInstance().getGameObject("wall3")->getComponent<BoxCollider>()->width = 100;
Engine::getInstance().getGameObject("wall3")->getComponent<BoxCollider>()->height = 600;

    Engine::getInstance().createGameObject("wall4");
Engine::getInstance().getGameObject("wall4")->addComponent<Coords>();
Engine::getInstance().getGameObject("wall4")->getComponent<Coords>()->rectCoords = std::vector<double> {400,600};
Engine::getInstance().getGameObject("wall4")->addBoxCollider();
Engine::getInstance().getGameObject("wall4")->getComponent<BoxCollider>()->width = 799;
Engine::getInstance().getGameObject("wall4")->getComponent<BoxCollider>()->height = 100;



}


int main()
{   
    createWalls();
    
    sf::Texture back;
    back.loadFromFile("back.png");
    sf::Sprite backsprite(back);
    
    Engine::getInstance().createGameObject("back");
    Engine::getInstance().getGameObject("back")->addComponent<Renderer>();
    Engine::getInstance().getGameObject("back")->getComponent<Renderer>()->addDrawable(backsprite,0,0,0);

    Engine::getInstance().getGameObject("back")->addComponent<Coords>();
    Engine::getInstance().getGameObject("back")->getComponent<Coords>()->rectCoords = std::vector<double> {0,600};
    Engine::getInstance().drawManager->registerRenderer(Engine::getInstance().getGameObject("back")->getComponent<Renderer>()); 
    
    
    
    
    sf::Texture texture;
    texture.loadFromFile("red.png");
    sf::Sprite sprite(texture);
    
    Engine::getInstance().createGameObject("bird");
    Engine::getInstance().getGameObject("bird")->addComponent<Renderer>();
    Engine::getInstance().getGameObject("bird")->getComponent<Renderer>()->addDrawable(sprite,0,0,45);

    Engine::getInstance().getGameObject("bird")->addComponent<Coords>();
    Engine::getInstance().getGameObject("bird")->getComponent<Coords>()->rectCoords = std::vector<double> {100,200};
    Engine::getInstance().drawManager->registerRenderer(Engine::getInstance().getGameObject("bird")->getComponent<Renderer>()); 

    Engine::getInstance().getGameObject("bird")->addScript(birdScript);
    
    Engine::getInstance().getGameObject("bird")->addBoxCollider();
    Engine::getInstance().getGameObject("bird")->getComponent<BoxCollider>()->width = 20;
    Engine::getInstance().getGameObject("bird")->getComponent<BoxCollider>()->height = 20;
    Engine::getInstance().getGameObject("bird")->addRigitBody();
    
    Engine::getInstance().getGameObject("bird")->getComponent<RigitBody>()->isGravity = true; 
    
    sf::Texture pigtexture;
    pigtexture.loadFromFile("pig.png");
    sf::Sprite pigsprite(pigtexture);
    
    Engine::getInstance().createGameObject("pig1");
    Engine::getInstance().getGameObject("pig1")->addComponent<Renderer>();
    Engine::getInstance().getGameObject("pig1")->getComponent<Renderer>()->addDrawable(pigsprite,0,0,45);
    Engine::getInstance().drawManager->registerRenderer(Engine::getInstance().getGameObject("pig1")->getComponent<Renderer>()); 
    
    Engine::getInstance().getGameObject("pig1")->addComponent<Coords>();
    Engine::getInstance().getGameObject("pig1")->getComponent<Coords>()->rectCoords = std::vector<double> {150,200};
    
    Engine::getInstance().getGameObject("pig1")->addScript(pigScript);
     
    Engine::getInstance().getGameObject("pig1")->addBoxCollider();
    Engine::getInstance().getGameObject("pig1")->getComponent<BoxCollider>()->width = 20;
    Engine::getInstance().getGameObject("pig1")->getComponent<BoxCollider>()->height = 20;
    Engine::getInstance().getGameObject("pig1")->addRigitBody();
    
    Engine::getInstance().getGameObject("pig1")->getComponent<RigitBody>()->isGravity = false; 
     
     
    
    
    
    

    


 
    
    while(Engine::getInstance().window()->isOpen())
    {

    Engine::getInstance().eventManager->pollEvents();
    Engine::getInstance().logicsManager->updateLogics();

    //Engine::getInstance().physicsManager->updateGravity();
   // Engine::getInstance().physicsManager->updatePosition();
  
    Engine::getInstance().physicsManager->updatePhysics();

    Engine::getInstance().drawManager->draw();

    Engine::getInstance().eventManager->clearEvents();



    }  
    


    return 0;
    
}
