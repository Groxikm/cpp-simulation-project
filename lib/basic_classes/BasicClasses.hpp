#ifndef IDENTITYCLASS_HPP
#define IDENTITYCLASS_HPP

class IdentityClass {
public:
    IdentityClass(long int id, float x,float y,float z, float size);
    long int getID() const;
    Coordinates getCoordinates() const;
    float getSize();
    void setCoordinates(const Coordinates& coordinates);

private:
    long int m_id;
    float m_x,m_y,m_z;
    float m_size;
};

#endif // IDENTITYCLASS_HPP

#ifndef RIGIDITYCLASS_HPP
#define RIGIDITYCLASS_HPP

class MassClass {
public:
    RigidityClass(double mass = 0.0);

    double getMass() const;

    void setMass(double mass);

private:
    double m_mass;
};

#endif // RIGIDITYCLASS_HPP
