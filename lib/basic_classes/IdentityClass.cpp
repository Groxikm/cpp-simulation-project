#include "IdentityClass.h"

IdentityClass::IdentityClass(const long int id)
: m_id(id) {}

long int IdentityClass::getID() const {
    return m_id;
}