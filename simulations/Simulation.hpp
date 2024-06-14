#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <memory>
#include "../lib/mass/MassCell.hpp"

class Simulation {
public:
    //Simulation(float time_coeff, float gravity_coeff, float reaction_coeff, bool ceiling, float ground_width, float walls_height, long ID);
    Simulation(float time_coeff, float gravity_coeff, float reaction_coeff, bool ceiling, float ground_width, float walls_height, long id)
            :  m_timeCoefficient(m_timeCoefficient), m_gravityCoefficient(m_gravityCoefficient), m_reactionCoefficient(m_reactionCoefficient), m_ceiling(m_ceiling), m_groundWidth(m_groundWidth), m_wallsHeight(m_wallsHeight), m_ID(m_ID) {
    }
    // Field logic methods
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

    // Simulation logic methods
    void applyForce(std::shared_ptr<MassCell> cell, float fx, float fy);
    void instantiateMassCell(std::shared_ptr<MassCell> cell);
    void run(float time_step);

private:
    //void applyGravity(std::shared_ptr<MassCell> cell);
    void handleCollisions(float elasticity);

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
