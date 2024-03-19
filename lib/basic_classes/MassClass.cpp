#include "MassClass.hpp"

RigidityClass::RigidityClass(double mass)
    : m_mass(mass) {}

double RigidityClass::getMass() const {
    return m_mass;
}

void RigidityClass::setMass(double mass) {
    m_mass = mass;
}
