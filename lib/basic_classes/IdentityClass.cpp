#include "IdentityClass.h"

IdentityClass::IdentityClass(const long int id)
: m_id(id), m_x(x), m_y(y), m_z(z), m_size(size) {}

long int IdentityClass::getID() const {
    return m_id;
}

Coordinates IdentityClass::getCoordinates() const {
    return {m_x, m_y, m_z};
}

void IdentityClass::setCoordinates(const Coordinates& coordinates) {
    m_x = coordinates.x;
    m_y = coordinates.y;
    m_z = coordinates.z;
}

Coordinates IdentityClass::getSize() const {
    return m_size;
}