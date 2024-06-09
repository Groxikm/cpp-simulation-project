#ifndef MASSCELL_HPP
#define MASSCELL_HPP

#include "../abstracts/MovableInterface.hpp"
#include "../abstracts/AbstractCell.hpp"
#include <iostream>
#include <cmath>

class MassCell : virtual public AbstractCell, virtual public MovableInterface {
public:
    MassCell(long id, float x, float y, float mass, float speed, float direction);
    MassCell();
    MassCell(const MassCell& other);
    ~MassCell();

    // Abstract methods
    float getX() override { return m_x; }
    void setX(float x) override { m_x = x; }
    long getID() override { return m_ID; }
    float getY() override { return m_y; }
    void setY(float y) override { m_y = y; }

    // Mass methods
    float getMass() const { return m_mass; }
    void setMass(float mass);

    // Movable methods
    void move(float time_step);
    void setVelocity(float speed, float direction) override;
    float getSpeed() override { return m_speed; }
    float getDirection() override { return m_direction; }

    // Force methods
    void applyForce(float fx, float fy);
    void update(float time_step);

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