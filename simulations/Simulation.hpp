#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <memory>
#include "../lib/mass/MassCell.hpp"

class Simulation {
public:
    Simulation(float time_coeff, float gravity_coeff, float reaction_coeff, bool ceiling, float ground_width, float walls_height, long ID);

    // Field logic methods (12)
    float getTimeCoefficient();
    void setTimeCoefficient(float time_coeff);
    float getGravityCoefficient();
    void setGravityCoefficient(float gravity_coeff);
    float getReactionCoefficient();
    void setReactionCoefficient(float reaction_coeff);
    bool isCeiling();
    void setCeiling(bool ceiling);
    float getGroundWidth();
    void setGroundWidth(float ground_width);
    float getWallsHeight();
    void setWallsHeight(float walls_height);
    long getID();

    // Physical logic methods (4+1)
    void applyForce(std::shared_ptr<MassCell> cell, float fx, float fy);
    void applyForce( float force, float angle, std::shared_ptr<MassCell> cell);
    void instantiateMassCell(std::shared_ptr<MassCell> cell);
    void handleCollisions(float elasticity);
    void run(float time_step);

    void calculateDistances();

private:
    float m_timeCoefficient;
    float m_gravityCoefficient;
    float m_reactionCoefficient;
    bool m_ceiling;
    float m_groundWidth;
    float m_wallsHeight;
    long m_ID;
    std::vector<std::shared_ptr<MassCell>> pointers;
};

#endif // SIMULATION_HPP