#include "MassCell.hpp"
#include <cmath>
#include <iostream>

MassCell::MassCell(long id, float x, float y, float mass, float speed, float direction)
        : m_ID(id), m_x(x), m_y(y), m_mass(mass), m_speed(speed), m_direction(direction), m_vx(speed * cos(direction)), m_vy(speed * sin(direction)), m_ax(0), m_ay(0) {
    std::cout << "MassCell created with ID: " << id << std::endl;
}

MassCell::MassCell(const MassCell& other)
        : m_ID(other.m_ID), m_x(other.m_x), m_y(other.m_y), m_mass(other.m_mass), m_speed(other.m_speed), m_direction(other.m_direction), m_vx(other.m_vx), m_vy(other.m_vy), m_ax(other.m_ax), m_ay(other.m_ay) {
    std::cout << "MassCell copied with ID: " << other.m_ID << std::endl;
}

MassCell::~MassCell() {
    std::cout << "MassCell with ID: " << m_ID << " is destroyed" << std::endl;
}

void MassCell::setMass(float mass) {
    m_mass = mass;
}

void MassCell::applyForce(float fx, float fy) {
    m_ax += fx / m_mass;
    m_ay += fy / m_mass;
}

void MassCell::update(float time_step) {
    m_vx += m_ax * time_step;
    m_vy += m_ay * time_step;
    m_x += m_vx * time_step;
    m_y += m_vy * time_step;
    m_ax = 0;
    m_ay = 0;
}

void MassCell::move(float time_step) {
    update(time_step);
}

void MassCell::setVelocity(float speed, float direction) {
    m_speed = speed;
    m_direction = direction;
    m_vx = speed * cos(direction);
    m_vy = speed * sin(direction);
}
