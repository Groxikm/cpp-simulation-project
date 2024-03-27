#ifndef MOVEABLEINTERFACE_HPP
#define MOVEABLEINTERFACE_HPP

class MoveableInterface {
public:
    
    float getSpeed();
    float getDirection();
    
    setVelocity(float speed, float direction);
    move();

private:
    MoveableInterface();
    float speed, direction;
};

#endif // MOVEABLEINTERFACE_HPP
