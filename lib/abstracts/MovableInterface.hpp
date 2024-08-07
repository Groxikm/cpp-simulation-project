// MovableInterface.hpp
#ifndef MOVABLEINTERFACE_HPP
#define MOVABLEINTERFACE_HPP

class MovableInterface {
public:
    //virtual ~MovableInterface() = default; //no obvious sense in having a destructor in such interface
    virtual float getSpeed() = 0;
    virtual float getDirection() = 0;
    virtual void setVelocity(float speed, float direction) = 0;
    virtual void move(float time_step) = 0;
    virtual float getVx() = 0;
    virtual float getVy() = 0;
};

#endif // MOVABLEINTERFACE_HPP

