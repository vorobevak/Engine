#ifndef __PHYS__
#define __PHYS__
#include <list>
class BoxCollider : public Component
{
public:
    
    double height = 0;
    double width = 0;
    std::list <GameObject*> opponents;

    bool onCollide = false;
    
    BoxCollider() : Component()
    {
        name = typeid(BoxCollider).name();
        //objPtr->addComponent<Coords>();
        std::list <GameObject*> opponents;
     
    }
    
    std::list <std::vector<double>> givePoints()
    {
        std::list <std::vector<double>> points;
        
        std::vector <double> bodyPosition = objPtr->getComponent<Coords>()->rectCoords;
        double bodyx = bodyPosition[0];
        double bodyy = bodyPosition[1];
        
        std::vector <double> xsizes = {0,width/2 , -width/2};
        std::vector <double> ysizes = {0, height/2, -height/2};
        
        for (double x : xsizes)
        {
            for (double y : ysizes)
            {
                if((x!=0) || (y!=0))
                {
                    std::vector <double> point = {bodyx + x, bodyy + y};
                    points.push_back(point);
                }
            }
        }
        return points;
        
    }

    

};

class RigitBody : public Component
{
public:
    RigitBody() : Component()
    {
        name = typeid(RigitBody).name();
        std::vector <double> velocity = {0,0};
        int mass = 0;
        bool isGravity = false;
        bool isDynamic = false;

    };
    
    int mass = 0;
    bool isGravity = false;

    std::vector <double> velocity = {0,0}; 
    double angularVelocity = 0;
    
    void invertVelocity()
    {
        velocity[0] = -velocity[0];
        velocity[1] = -velocity[1];
    }
    
};

class PhysicsManager
{
public:
    std::list <BoxCollider*> colliders;
    std::list <RigitBody*> rigitBodies;

    void registerBoxCollider(BoxCollider* B)
    {
        colliders.push_back(B);
    }
    void registerRigitBody(RigitBody* R)
    {
        rigitBodies.push_back(R);
    }
    
    
    PhysicsManager()
    {
        std::list <BoxCollider*> colliders;
        std::list <RigitBody*> rigitBodies;
    }
    
    
    void updatePhysics()
    {

        clearCollisions();
        updateGravity();
        updatePosition();
        pollCollisions();
        
    }
    
    void updateGravity()
    {
        for (RigitBody* rb : rigitBodies)
        {
            if (rb->isGravity)
            {

                rb->velocity[1] -= 0.0001;
            }  
        }
    }
    
    void updatePosition()
    {
        for (RigitBody* rb : rigitBodies)
        {
            rb->objPtr->getComponent<Coords>()->rectCoords[0] += rb->velocity[0];
            rb->objPtr->getComponent<Coords>()->rectCoords[1] += rb->velocity[1];
            rb->objPtr->getComponent<Coords>()->angle += rb->angularVelocity;
        }
    }
    
    void pollCollisions()
    {

        for (BoxCollider* c1 : colliders)
        {
            for (BoxCollider* c2 : colliders)
            {
                if (c1 != c2 && isCollision(c1,c2))
                {
                   // std::cout << "collision between " << c1->objPtr->name << " " << c2-> objPtr->name << std::endl;
                    c1->onCollide = true;
                    c1->opponents.push_back(c2->objPtr);
                    c2->onCollide = true;
                    c2->opponents.push_back(c1->objPtr);
                    operateCollision(c1,c2);
                }
            }
        }
    }
    void clearCollisions()
    {
        for (BoxCollider* c : colliders)
        {
            c->onCollide = false;
            c->opponents.clear();
        }
    }
    bool isCollision(BoxCollider* c1, BoxCollider* c2)
    {
        double X1center = c1->objPtr->getComponent<Coords>()->rectCoords[0];
        double Y1center = c1->objPtr->getComponent<Coords>()->rectCoords[1];
        
        double width1 = c1->width;
        double height1 = c1->height;
        
        double X2center = c2->objPtr->getComponent<Coords>()->rectCoords[0];
        double Y2center = c2->objPtr->getComponent<Coords>()->rectCoords[1];
        
        double width2 = c2->width;
        double height2 = c2->height;        
        
        if ((abs(X1center - X2center) <= (width1 + width2)/2) && (abs(Y1center - Y2center) <= (height1 + height2)/2))
        {
            return true;
        }
        return false;
    }
    
    bool isPointInCollider(std::vector<double> point,BoxCollider* c )
    {

        double Xcenter = c->objPtr->getComponent<Coords>()->rectCoords[0];
        double Ycenter = c->objPtr->getComponent<Coords>()->rectCoords[1];

        if ((abs(point[0] - Xcenter) <= (c->width)/2) && (abs(point[1] - Ycenter) <= (c->height)/2))
        {
            //std::cout << "is Point in collider" <<std::endl;
            return true;
        }
        return false;
    }
    
    void operateCollision(BoxCollider* c1, BoxCollider* c2)
    {
        std::list <std::vector<double>> points1 = c1->givePoints();
        std::list <std::vector<double>> points2 = c2->givePoints();
        
                    // std::cout << "operateCollision" << std::endl;
        if (c1->objPtr->getComponent<RigitBody>() != nullptr) // если скорость надо рассчитывать
        {
            
            for (std::vector<double> p1 : points1)
            {
                if(isPointInCollider(p1,c2)) // если точка первого тела вошла во второе
                {
                    double X1center = c1->objPtr->getComponent<Coords>()->rectCoords[0];
                    double Y1center = c1->objPtr->getComponent<Coords>()->rectCoords[1];
                    
                    c1->objPtr->getComponent<RigitBody>()->velocity[0] -= 0.001*(p1[0] - X1center);
                    c1->objPtr->getComponent<RigitBody>()->velocity[1] -= 0.001*(p1[1] - Y1center);
                }
            }
        }
        //std::cout << "operating collision" << std::endl;
        if (c2->objPtr->getComponent<RigitBody>() != nullptr) // если скорость надо рассчитывать
        {
            //std::cout << "calculating collision between" << c1->objPtr->name << " "<< c2->objPtr->name << std::endl;
            for (std::vector<double> p2 : points2)
            {
                if(isPointInCollider(p2,c1)) // если точка второго тела вошла в первое
                {
                    double X2center = c2->objPtr->getComponent<Coords>()->rectCoords[0];
                    double Y2center = c2->objPtr->getComponent<Coords>()->rectCoords[1];
                    
                    c2->objPtr->getComponent<RigitBody>()->velocity[0] -= 0.001*(p2[0] - X2center);
                    c2->objPtr->getComponent<RigitBody>()->velocity[1] -= 0.001*(p2[1] - Y2center);
                }
            }
        }
        //std::cout << "end operating" <<std::endl;
        
    }
};

#endif
