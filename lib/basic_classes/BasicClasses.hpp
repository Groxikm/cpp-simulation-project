#ifndef IDENTITYCLASS_HPP
#define IDENTITYCLASS_HPP

class IdentityClass {
public:
    IdentityClass(long int id);
    long int getID() const;

private:
    long int m_id;           
};

#endif // IDENTITYCLASS_HPP

#ifndef RIGIDITYCLASS_HPP
#define RIGIDITYCLASS_HPP

#include <vector>

class RigidityClass {
public:
    RigidityClass(double mass = 0.0, const std::vector<double>& vector = std::vector<double>());

    double getMass() const;
    const std::vector<double>& getVector() const;

    void setMass(double mass);
    void setVector(const std::vector<double>& vector);

private:
    double m_mass;
    std::vector<double> m_vector;
};

#endif // RIGIDITYCLASS_HPP
