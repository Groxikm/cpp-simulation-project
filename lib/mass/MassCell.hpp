#ifndef MASSCELL_HPP
#define MASSCELL_HPP

#include "../abstracts/MovableInterface.hpp"
#include "../abstracts/AbstractCell.hpp"


class MassCell : virtual public AbstractCell, virtual public MovableInterface {
public:
    MassCell(long id, float x, float y, float mass, float speed, float direction);
    //: m_ID(id), m_x(x), m_y(y), m_mass(mass), m_speed(speed), m_direction(direction)

    MassCell();
    //abstract methods
    float getX() override { return m_x; }
    void setX(float x) override { this->m_x = x; }
    long getID() override { return this->m_ID; }
    float getY() override { return m_y; };
    void setY(float y) override { this->m_y = y; }
    //mass methods
    virtual void setMass(float mass);
    virtual float getMass();
    //moveable methods
    virtual void move() override;
    void setVelocity(float speed, float direction) override {
        this->m_speed = speed;
        this->m_direction = direction;
    }
    float getSpeed() override { return this->m_speed;}
    float getDirection() override {return this->m_direction; }

    /*float getSpeed();
    void getDirection();//the methods aren't needed to be redifined */


private:
    long m_ID;
    float m_mass;
    float m_x;
    float m_y;
    float m_speed;
    float m_direction;
};

#endif // MASSCELL_HPP
