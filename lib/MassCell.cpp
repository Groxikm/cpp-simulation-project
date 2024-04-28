#include "MassCell.hpp"
#include <cmath>

MassCell :: MassCell ( long id , float x , float y , float mass , float speed , float direction )
{
    this->m_ID= id;
    this->m_x = x;
    this->m_y= y ;
    this->m_mass = mass;
    this->m_speed = speed;
    this->m_direction = direction;
}
MassCell :: ~MassCell(){};

void MassCell::move() {
    m_x += m_speed * cos(m_direction);
    m_y += m_speed * sin(m_direction);
}

float MassCell::getX() { return m_x; }

float MassCell::getY() { return m_y; }
//mass methods
void MassCell::setMass(float mass) { m_mass = mass; }
float MassCell::getMass() { return m_mass; }