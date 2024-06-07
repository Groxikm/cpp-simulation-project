#include "MassCell.hpp"
#include <cmath>
#include <iostream>

// CopyConstructor
MassCell::MassCell(const MassCell& other)
        : m_ID(other.m_ID), m_x(other.m_x), m_y(other.m_y), m_mass(other.m_mass), m_speed(other.m_speed), m_direction(other.m_direction) {
    std::cout << "MassCell copied with ID: " << other.m_ID << std::endl;
}

// destructor
MassCell::~MassCell() {
    std::cout << "MassCell with ID: " << m_ID << " is destroyed" << std::endl;
}

//mass methods
void MassCell::setMass(float mass) {
    m_mass = mass;
}


// movable methods
void MassCell::move() {
    m_x += m_speed * std::cos(m_direction);
    m_y += m_speed * std::sin(m_direction);
}
