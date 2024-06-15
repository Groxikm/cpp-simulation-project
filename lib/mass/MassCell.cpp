#include "MassCell.hpp"
#include <cmath>
#include <iostream>

MassCell::MassCell(long id, float x, float y, float mass, float speed, float direction)
        : m_ID(m_ID), m_x(m_x), m_y(m_y), m_mass(m_mass), m_speed(m_speed), m_direction(m_direction), m_vx(m_vx), m_vy(m_vy), m_ax(m_ax), m_ay(m_ay) {
    std::cout << "MassCell created with ID: " << m_ID << std::endl;
}
MassCell::MassCell(const MassCell& other)
        : m_ID(other.m_ID), m_x(other.m_x), m_y(other.m_y), m_mass(other.m_mass), m_speed(other.m_speed), m_direction(other.m_direction), m_vx(other.m_vx), m_vy(other.m_vy), m_ax(other.m_ax), m_ay(other.m_ay) {
    std::cout << "MassCell copied with ID: " << other.m_ID << std::endl;
}

MassCell::~MassCell() {
    std::cout << "MassCell with ID: " << m_ID << " is destroyed" << std::endl;
}

long MassCell::getID() {return m_ID;}
float MassCell::getX() {return m_x;}
void MassCell::setX(float x) { m_x = x;}
float MassCell::getY() {return m_y;}
void MassCell::setY(float y) { m_y = y;}
float MassCell::getMass()  {return m_mass;}
void MassCell::setMass(float mass) { m_mass = mass;}
float MassCell::getSpeed() { return m_speed;}
float MassCell::getDirection() {return m_direction;}

void MassCell::setVelocity(float speed, float direction) {
    m_speed = speed;
    m_direction = direction;
    m_vx = speed * cos(direction);
    m_vy = speed * sin(direction);
}

void MassCell::move(float time_step) {
    m_vx += m_ax * time_step;
    m_vy += m_ay * time_step;
    m_x += m_vx * time_step;
    m_y += m_vy * time_step;
}

void MassCell::applyForce(float fx, float fy) {
    m_ax += fx / m_mass;
    m_ay += fy / m_mass;
}

