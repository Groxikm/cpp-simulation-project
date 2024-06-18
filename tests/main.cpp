
#include "../lib/mass/MassCell.cpp"
#include "../simulations/Simulation.cpp"
#include "../console-interface/Output-in-Console.cpp"


#include <iostream>
#include <memory>
#include <vector>

int main() {

    Simulation sim(0.1, 9.8, 0.9, false, 100.0, 50.0, 1);

    auto cell1 = std::make_shared<MassCell>(1, 10.0, 20.0, 5.0, 2.0, 0.0);
    auto cell2 = std::make_shared<MassCell>(2, 15.0, 25.0, 5.0, 1.0, 3.14/4);
    auto cell3 = std::make_shared<MassCell>(3, 30.0, 35.0, 5.0, 3.0, 3.14/2);

    sim.instantiateMassCell(cell1);
    sim.instantiateMassCell(cell2);
    sim.instantiateMassCell(cell3);

    sim.applyForce(cell1, 10.0, 0.0);
    sim.applyForce(15.0, 3.14/6, cell2); // using the overloaded function

    for (int i = 0; i < 3; ++i) {
        std::cout << "Time step: " << i << std::endl;
        sim.run(0.1); // Run the simulation with a time step of 0.1
    }

    return 0;
}