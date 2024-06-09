#include "Simulation.hpp"
//#include "constructors/instantiateObject_constructors.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
Simulation::Simulation(float time_coeff, float gravity_coeff, float reaction_coeff, bool ceiling, float ground_width, float walls_height, long id)
        :  m_timeCoefficient(time_coeff), m_gravityCoefficient(gravity_coeff), m_reactionCoefficient(reaction_coeff), m_ceiling(ceiling), m_groundWidth(ground_width), m_wallsHeight(walls_height), m_ID(id) {
}
//field logic
float Simulation::getTimeCoefficient() { return m_timeCoefficient; }
void Simulation::setTimeCoefficient(float time_coeff) { m_timeCoefficient = time_coeff; }
float Simulation::getGravityCoefficient() { return m_gravityCoefficient; }
void Simulation::setGravityCoefficient(float gravity_coeff) { m_gravityCoefficient = gravity_coeff; }
float Simulation::getReactionCoefficient() { return m_reactionCoefficient; }
void Simulation::setReactionCoefficient(float reaction_coeff) { m_reactionCoefficient = reaction_coeff; }
bool Simulation::isCeiling() { return m_ceiling; }
void Simulation::setCeiling(bool ceiling) { m_ceiling = ceiling; }
float Simulation::getGroundWidth() { return m_groundWidth; }
void Simulation::setGroundWidth(float ground_width) { m_groundWidth = ground_width; }
float Simulation::getWallsHeight() { return m_wallsHeight; }
void Simulation::setWallsHeight(float walls_height) { m_wallsHeight = walls_height; }
long Simulation::getID() { return m_ID; }

//object logic, a default instantiation
//vector<shared_ptr<MassCell>> objects;
void Simulation::destroyObject(std::shared_ptr<MassCell> cell) {
    cell->~MassCell();
}


void Simulation::applyGravity(std::shared_ptr<MassCell> cell) {
        if (!cell) return;

        // Apply gravity to the vertical component of the velocity
        float vx = cell->getSpeed() * cos(cell->getDirection());
        float vy = cell->getSpeed() * sin(cell->getDirection());

        // Update vertical speed component
        vy += m_gravityCoefficient * m_timeCoefficient;

        // Calculate new speed and direction
        float newSpeed = sqrt(vx * vx + vy * vy);
        float newDirection = atan2(vy, vx);

        cell->setVelocity(newSpeed, newDirection);
    }

// Object logic, a default instantiation
void Simulation::instantiateMassCell(long id, float x, float y, float mass, float speed, float direction) {
    auto massCell = std::make_shared<MassCell>(id, x, y, mass, speed, direction); //using smart pointers
    this->pointers.push_back(massCell);
}

void Simulation::run() {
    std::cout << "Running simulation..." << std::endl;
    for (const auto& cell : pointers) {
        applyGravity(cell);
        cell->move();
        std::cout << "Moved MassCell with ID: " << cell->getID() << " to position (" << cell->getX() << ", " << cell->getY() << ")" << std::endl;
    }
}