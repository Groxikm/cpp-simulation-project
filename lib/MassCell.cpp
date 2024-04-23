#include "MassCell.hpp"
#include <cmath>


MassCell(float x = 0.0f, float y = 0.0f, float mass = 0.0f, float speed = 0.0f, float direction = 0.0f)
        : m_ID(id), m_x(x), m_y(y), m_mass(mass), m_speed(speed), m_direction(direction) {
    prinf("created a cell");
}

MassCell(){
    prinf("created a cell");
};

void MassCell::move() {
    m_x += m_speed * cos(m_direction);
    m_y += m_speed * sin(m_direction);
}

void MassCell::setVelocity(float speed, float direction) {
    m_speed = speed;
    m_direction = direction;
}