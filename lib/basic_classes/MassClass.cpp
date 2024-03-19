#include "MassClass.hpp"

RigidityClass::RigidityClass(double mass, const std::vector<double>& vector)
    : m_mass(mass), m_vector(vector) {}

double RigidityClass::getMass() const {
    return m_mass;
}

void RigidityClass::setMass(double mass) {
    m_mass = mass;
}
