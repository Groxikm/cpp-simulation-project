
#include "../lib/mass/MassCell.cpp"
#include "../simulations/Simulation.cpp"
#include "../console-interface/Output-in-Console.cpp"


#include <iostream>
#include <memory>
#include <vector>

int main() {
    // Create a Simulation object with some parameters
    Simulation simulation(0.1f, 9.8f, 0.5f, true, 100.0f, 50.0f, 1);

    // Instantiate some MassCell objects
    simulation.instantiateMassCell(1, 0.0f, 0.0f, 5.0f, 1.0f, 0.0f);
    simulation.instantiateMassCell(2, 10.0f, 10.0f, 10.0f, 2.0f, 3.14f / 4); // 45 degrees

    // Run the simulation
    simulation.run(0.1f); // Pass the time step

    return 0;
}