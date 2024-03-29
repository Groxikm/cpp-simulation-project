#ifndef MOVABLEINTERFACE_HPP
#define MOVABLEINTERFACE_HPP

class MovableInterface {
public:
    
    float getSpeed();
    float getDirection();
    
    setVelocity(float speed, float direction);
    move();

private:
    MovableInterface();
    float speed, direction;
};

#endif // MOVABLEINTERFACE_HPP
