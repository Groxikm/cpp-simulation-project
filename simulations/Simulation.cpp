#include "Simulation.hpp"
//#include "constructors/instantiateObject_constructors.hpp"
#include <iostream>
//#include <vector>
#include <memory>
#include <cmath>

Simulation::Simulation(float time_coeff, float gravity_coeff, float reaction_coeff, bool ceiling, float ground_width, float walls_height, long id)
           :  m_timeCoefficient(m_timeCoefficient), m_gravityCoefficient(m_gravityCoefficient), m_reactionCoefficient(m_reactionCoefficient), m_ceiling(m_ceiling), m_groundWidth(m_groundWidth), m_wallsHeight(m_wallsHeight), m_ID(m_ID) {
    }
// Field logic methods (12)
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

// Physical logic methods (4)
void Simulation::applyForce(std::shared_ptr<MassCell> cell, float fx, float fy) {
    cell->applyForce(fx, fy);
}

void Simulation::instantiateMassCell(std::shared_ptr<MassCell> cell) {
    //auto massCell = std::make_shared<MassCell>(id, x, y, mass, speed, direction);
    pointers.push_back(cell);
    std::cout << "MassCell instantiated. Total objects: " << pointers.size() << std::endl;
}

void Simulation::handleCollisions(float elasticity) {
    for (size_t i = 0; i < pointers.size(); ++i) {
        for (size_t j = i + 1; j < pointers.size(); ++j) {
            auto cell1 = pointers[i];
            auto cell2 = pointers[j];
            float dx = cell2->getX() - cell1->getX();
            float dy = cell2->getY() - cell1->getY();
            float distance = sqrt(dx * dx + dy * dy);

            // Assuming cells are circular and have the same radius for simplicity
            float radius = 1.0; // Adjust as needed
            if (distance < 2 * radius) {
                // Calculate collision response
                float nx = dx / distance;
                float ny = dy / distance;

                float kx = (cell1->getSpeed() * cos(cell1->getDirection()) - cell2->getSpeed() * cos(cell2->getDirection()));
                float ky = (cell1->getSpeed() * sin(cell1->getDirection()) - cell2->getSpeed() * sin(cell2->getDirection()));
                float p = 2.0 * (nx * kx + ny * ky) / (cell1->getMass() + cell2->getMass());

                float v1x = cell1->getSpeed() * cos(cell1->getDirection()) - p * cell2->getMass() * nx;
                float v1y = cell1->getSpeed() * sin(cell1->getDirection()) - p * cell2->getMass() * ny;
                float v2x = cell2->getSpeed() * cos(cell2->getDirection()) + p * cell1->getMass() * nx;
                float v2y = cell2->getSpeed() * sin(cell2->getDirection()) + p * cell1->getMass() * ny;

                // Apply elasticity
                v1x *= elasticity;
                v1y *= elasticity;
                v2x *= elasticity;
                v2y *= elasticity;

                cell1->setVelocity(sqrt(v1x * v1x + v1y * v1y), atan2(v1y, v1x));
                cell2->setVelocity(sqrt(v2x * v2x + v2y * v2y), atan2(v2y, v2x));
            }
        }
    }
}

void Simulation::run(float time_step) {
    //std::cout << "Running simulation..." << std::endl;

    // Apply gravity to all cells
    for (const auto& cell : pointers) {
        applyForce(cell, 0, m_gravityCoefficient);
    }

    // Update all cells
    for (const auto& cell : pointers) {
        cell->move(time_step);
        std::cout << "Moved MassCell with ID: " << cell->getID() << " to position (" << cell->getX() << ", " << cell->getY() << ")" << std::endl;
    }

    // Handle collisions
    handleCollisions(m_reactionCoefficient);
}