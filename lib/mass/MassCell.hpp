#ifndef MASSCELL_HPP
#define MASSCELL_HPP

class MassCell {
public:
    MassCell(long id, float x, float y, float mass, float speed, float direction);
    MassCell(const MassCell& other);
    ~MassCell();

    long getID();
    float getX();
    void setX(float x);
    float getY();
    void setY(float y);
    float getMass();
    void setMass(float mass);
    float getSpeed();
    float getDirection();
    void setVelocity(float speed, float direction);

    void move(float time_step);
    void applyForce(float fx, float fy);


    MassCell& operator+=(const MassCell& other);

private:
    long m_ID;
    float m_x;
    float m_y;
    float m_mass;
    float m_speed;
    float m_direction;
    float m_vx;
    float m_vy;
    float m_ax;
    float m_ay;
};

#endif // MASSCELL_HPP