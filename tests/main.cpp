
#include "../lib/mass/MassCell.cpp"
#include "../lib/mass/MassCell.hpp"
#include "../console-interface/just-an-output.cpp"

int main() {
    ConsoleOutput org_output("speed", 21, "direction", 95.2);
    std::cout << org_output.how_many_outputs_called();
    return 0;
}
