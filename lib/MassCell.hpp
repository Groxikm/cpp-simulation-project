#ifndef MASSCELL_HPP
#define MASSCELL_HPP

#include "MovableInterface.hpp"
#include "AbstractCell.hpp"


class MassCell : public AbstractCell, public MovableInterface {
public:
    MassCell(float x, float y, float mass, float speed, float direction)
    //: m_ID(id), m_x(x), m_y(y), m_mass(mass), m_speed(speed), m_direction(direction)
    {

    }

    MassCell();
    //abstract methods
    long giveID() override { this->m_ID; } //yes for now it does nothing
    long getID() override { return m_ID; }
    void setX(float x) override { this->m_x = x; }
    float getX() const override { return m_x; }
    void setY(float y) override { this->m_y = y; }
    float getY() const override { return m_y; }
    //mass methods
    void setMass(float mass) { m_mass = mass; }
    float getMass() const { return m_mass; }
    //moveable methods
    void move() override;
    /*float getSpeed();
    void getDirection();//the methods aren't needed to be redifined */
    void setVelocity(float speed, float direction);

protected:
    float m_mass;
    float m_x;
    float m_y;
    float m_speed;
    float m_direction;
private:
    long m_ID;
};

#endif // MASSCELL_HPP
