#include "../lib/mass/MassCell.hpp"
#include "../simulations/Simulation.hpp"
#include "../console-interface/Output-in-Console.cpp"


#include <iostream>
#include <memory>
#include <vector>

int main() {
    Simulation simulation(0.1f, 9.8f, 0.5f, true, 100.0f, 50.0f, 1);

    //std::shared_ptr<MassCell> cell1 = std::make_shared<MassCell>(1, 0.0f, 0.0f, 1.0f, 2.0f, 0.0f);
    //std::shared_ptr<MassCell> cell2 = std::make_shared<MassCell>(2, 1.0f, 1.0f, 1.0f, 2.0f, 3.14f);
    //simulation.run(0.1f);

    return 0;
}