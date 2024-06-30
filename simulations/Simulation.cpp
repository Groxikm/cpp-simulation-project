#include "Simulation.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>

Simulation::Simulation(float time_coeff, float gravity_coeff, float reaction_coeff, bool ceiling, float ground_width, float walls_height, long id)
        : m_timeCoefficient(time_coeff), m_gravityCoefficient(gravity_coeff), m_reactionCoefficient(reaction_coeff), m_ceiling(ceiling), m_groundWidth(ground_width), m_wallsHeight(walls_height), m_ID(id) {
}

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

void Simulation::applyForce(std::shared_ptr<MassCell> cell, float fx, float fy) {
    cell->applyForce(fx, fy);
}

void Simulation::applyForce(float force, float angle, std::shared_ptr<MassCell> cell) {
    float fx = force * cos(angle);
    float fy = force * sin(angle);
    cell->applyForce(fx, fy);
}

void Simulation::instantiateMassCell(std::shared_ptr<MassCell> cell) {
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

            float radius = 1.0; // example
            if (distance < 2 * radius) {
                float nx = dx / distance;
                float ny = dy / distance;
                float kx = (cell1->getSpeed() * cos(cell1->getDirection()) - cell2->getSpeed() * cos(cell2->getDirection()));
                float ky = (cell1->getSpeed() * sin(cell1->getDirection()) - cell2->getSpeed() * sin(cell2->getDirection()));
                float p = 2.0 * (nx * kx + ny * ky) / (cell1->getMass() + cell2->getMass());
                float v1x = cell1->getSpeed() * cos(cell1->getDirection()) - p * cell2->getMass() * nx;
                float v1y = cell1->getSpeed() * sin(cell1->getDirection()) - p * cell2->getMass() * ny;
                float v2x = cell2->getSpeed() * cos(cell2->getDirection()) + p * cell1->getMass() * nx;
                float v2y = cell2->getSpeed() * sin(cell2->getDirection()) + p * cell1->getMass() * ny;
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

void Simulation::calculateDistances() {
    auto distanceLambda = [](std::shared_ptr<MassCell> cell1, std::shared_ptr<MassCell> cell2) {
        float dx = cell2->getX() - cell1->getX();
        float dy = cell2->getY() - cell1->getY();
        return sqrt(dx * dx + dy * dy);
    };

    for (const auto& cell : pointers) {
        std::cout << "Distances from cell ID " << cell->getID() << " to other cells:" << std::endl;
        for (const auto& other : pointers) {
            if (cell != other) {
                std::cout << "  to cell ID " << other->getID() << ": " << distanceLambda(cell, other) << std::endl;
            }
        }
    }
}

void Simulation::initializeCSV(const std::string& filename) {
    m_csvFile.open(filename);
    if (m_csvFile.is_open()) {
        m_csvFile << "ID,Mass,X,Y,Speed,Direction\n";
    } else {
        std::cerr << "Failed to open CSV file for writing!" << std::endl;
    }
}

void Simulation::writeToCSV() {
    if (m_csvFile.is_open()) {
        for (const auto& cell : pointers) {
            m_csvFile << cell->getID() << ","
                      << cell->getMass() << ","
                      << cell->getX() << ","
                      << cell->getY() << ","
                      << cell->getSpeed() << ","
                      << cell->getDirection() << "\n";
        }
    } else {
        std::cerr << "CSV file is not open!" << std::endl;
    }
}

void Simulation::closeCSV() {
    if (m_csvFile.is_open()) {
        m_csvFile.close();
    }
}

void Simulation::run(float time_step) {
    for (const auto& cell : pointers) {
        applyForce(cell, 0, m_gravityCoefficient);
    }

    for (const auto& cell : pointers) {
        cell->move(time_step);
        std::cout << "Moved MassCell with ID: " << cell->getID() << " to position (" << cell->getX() << ", " << cell->getY() << ")" << std::endl;
    }

    handleCollisions(m_reactionCoefficient);
    calculateDistances();
    writeToCSV();
}

const std::vector<std::shared_ptr<MassCell>>& Simulation::getCells() const {
    return pointers;
}
