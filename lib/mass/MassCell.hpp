#ifndef MASSCELL_HPP
#define MASSCELL_HPP

#include "../abstracts/MovableInterface.hpp"
#include "../abstracts/AbstractCell.hpp"
#include <iostream>
#include <cmath>

class MassCell : virtual public AbstractCell, virtual public MovableInterface {
public:
    MassCell(long id, float x, float y, float mass, float speed, float direction);
    //MassCell(long id, float x, float y, float mass, float m_vx, float m_vy);
    //MassCell();
    MassCell(const MassCell& other);
    ~MassCell();

    // Abstract methods
    float getX() override;
    void setX(float x) override;
    long getID() override;
    float getY() override;
    void setY(float y) override;

    // Movable methods
    void move(float time_step) override;
    void setVelocity(float speed, float direction) override;
    float getSpeed() override;
    float getDirection() override;

    // Mass methods
    float getMass() ;
    void setMass(float mass);
    
    // Force methods
    void applyForce(float fx, float fy);

private:
    long m_ID;
    float m_mass;
    float m_x;
    float m_y;
    float m_speed;
    float m_direction;
    float m_vx;
    float m_vy;
    float m_ax;
    float m_ay;
};

#endif // MASSCELL_HPP
