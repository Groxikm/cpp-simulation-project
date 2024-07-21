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

void Simulation::applyGravity() {
    for (const auto& cell : pointers) {
        // Apply gravitational force downward
        cell->applyForce(0, -m_gravityCoefficient * cell->getMass());
    }
}

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
    float radius = 10.0; // Assume a fixed radius for simplicity
    float tolerance = -1.6f; //to allow some range of innacuracy for correct work
    // Handle cell-to-cell collisions
    for (size_t i = 0; i < pointers.size(); ++i) {
        for (size_t j = i + 1; j < pointers.size(); ++j) {
            auto cell1 = pointers[i];
            auto cell2 = pointers[j];

            float dx = cell2->getX() - cell1->getX();
            float dy = cell2->getY() - cell1->getY();
            float distance = sqrt(dx * dx + dy * dy);

            if (distance  < 2 * (radius ) ) {
                float overlap = 2 * radius - distance - tolerance;

                float nx = dx / distance;
                float ny = dy / distance;

                // Adjust positions to prevent overlap
                cell1->setX(cell1->getX() - nx * overlap / 2);
                cell1->setY(cell1->getY() - ny * overlap / 2);
                cell2->setX(cell2->getX() + nx * overlap / 2);
                cell2->setY(cell2->getY() + ny * overlap / 2);

                // Relative velocity
                float dvx = cell1->getVx() - cell2->getVx();
                float dvy = cell1->getVy() - cell2->getVy();
                float vn = dvx * nx + dvy * ny;

                //if (vn > 0) continue; // Ensure they are moving towards each other

                float impulse = (2.0f * vn) / (cell1->getMass() + cell2->getMass());

                // Update velocities considering elasticity
                float v1x = cell1->getVx() - impulse * cell2->getMass() * nx * elasticity;
                float v1y = cell1->getVy() - impulse * cell2->getMass() * ny * elasticity;
                float v2x = cell2->getVx() + impulse * cell1->getMass() * nx * elasticity;
                float v2y = cell2->getVy() + impulse * cell1->getMass() * ny * elasticity;

                cell1->setVelocity(sqrt(v1x * v1x + v1y * v1y), atan2(v1y, v1x));
                cell2->setVelocity(sqrt(v2x * v2x + v2y * v2y), atan2(v2y, v2x));
            }
        }

        auto cell = pointers[i];

        // Handle wall collisions

        if (cell->getX() - radius  < 0 ) {
            cell->setX(radius);
            float new_vx = -cell->getVx() * elasticity;
            float new_vy = cell->getVy();
            cell->setVelocity(sqrt(new_vx * new_vx + new_vy * new_vy), atan2(new_vy, new_vx));
        } else if (cell->getX() + radius > m_groundWidth ) {
            cell->setX(m_groundWidth - radius);
            float new_vx = -cell->getVx() * elasticity;
            float new_vy = cell->getVy();
            cell->setVelocity(sqrt(new_vx * new_vx + new_vy * new_vy), atan2(new_vy, new_vx));
        }

        if (m_ceiling && cell->getY() - radius < 0 ) {
            cell->setY(radius);
            float new_vx = cell->getVx();
            float new_vy = -cell->getVy() * elasticity;
            cell->setVelocity(sqrt(new_vx * new_vx + new_vy * new_vy), atan2(new_vy, new_vx));
        } else if (cell->getY() + radius > m_wallsHeight ) {
            cell->setY(m_wallsHeight - radius);
            float new_vx = cell->getVx();
            float new_vy = -cell->getVy() * elasticity;
            cell->setVelocity(sqrt(new_vx * new_vx + new_vy * new_vy), atan2(new_vy, new_vx));
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
    applyGravity(); // Apply gravity to all cells

    for (const auto& cell : pointers) {
        cell->move(time_step);
        std::cout << "Moved MassCell with ID: " << cell->getID() << " to position (" << cell->getX() << ", " << cell->getY() << ")" << std::endl;
    }

    handleCollisions(m_reactionCoefficient); // Handle collisions
    writeToCSV(); // Log to CSV
}

const std::vector<std::shared_ptr<MassCell>>& Simulation::getCells() const {
    return pointers;
}
