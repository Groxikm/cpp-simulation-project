#ifndef MASSCELL_HPP
#define MASSCELL_HPP

#include "../abstracts/MovableInterface.hpp"
#include "../abstracts/AbstractCell.hpp"

#include <cmath>
#include <iostream>

class MassCell : virtual MovableInterface, virtual AbstractCell {
public:
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
    float getVx() override;
    float getVy() override;

    MassCell(long id, float x, float y, float mass, float speed, float direction);
    MassCell(const MassCell& other);
    ~MassCell();
    float getMass();
    void setMass(float mass);
    void applyForce(float fx, float fy);

    MassCell& operator+=(const MassCell& other);

private:
    long m_ID;
    float m_x, m_y;
    float m_mass, m_speed, m_direction;
    float m_vx, m_vy;
    float m_ax, m_ay;
};

#endif
