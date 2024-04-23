// MovableInterface.hpp
#ifndef MOVABLEINTERFACE_HPP
#define MOVABLEINTERFACE_HPP

class MovableInterface {
public:
    virtual ~MovableInterface() = default;
    virtual void setX(float x) = 0;
    virtual float getX() const = 0;
    virtual void setY(float y) = 0;
    virtual float getY() const = 0;
    virtual float getSpeed() const = 0;
    virtual float getDirection() const = 0;
    virtual void setVelocity(float speed, float direction) = 0;
    virtual void move() = 0;
};

#endif // MOVABLEINTERFACE_HPP

