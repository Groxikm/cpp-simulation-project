#include "RigidityClass.hpp"

RigidityClass::RigidityClass(double mass, const std::vector<double>& vector)
    : m_mass(mass), m_vector(vector) {}

double RigidityClass::getMass() const {
    return m_mass;
}

const std::vector<double>& RigidityClass::getVector() const {
    return m_vector;
}

void RigidityClass::setMass(double mass) {
    m_mass = mass;
}

void RigidityClass::setVector(const std::vector<double>& vector) {
    m_vector = vector;
}