#include "../lib/mass/MassCell.cpp"
#include "../simulations/Simulation.cpp"
#include "../console-interface/Output-in-Console.cpp"


#include <iostream>
#include <memory>
#include <vector>

int main() {
    Simulation simulation(0.1f, 9.8f, 0.5f, true, 100.0f, 50.0f, 1);

    std::shared_ptr<MassCell> cell1 = std::make_shared<MassCell>(1, 0.0f, 0.0f, 1.0f, 2.0f, 0.0f);
    //std::shared_ptr<MassCell> cell2 = std::make_shared<MassCell>(2, 1.0f, 1.0f, 1.0f, 2.0f, 3.14f);
    for (int i = 0; i < 3; i++){

        std::cout << "MassCell1 has coordinates x: " << cell1->getX()<< " y: " << cell1->getY() << " and speed: " << cell1->getSpeed() << std::endl;
        simulation.run(0.1f);
        //std::cout << "MassCell2 has coordinates x: " << cell2->getX()<< " y: " << cell2->getY() << " and speed: " << cell2->getSpeed() << std::endl;
    }


    return 0;
}