#include "../lib/mass/MassCell.cpp"
#include "../simulations/Simulation.cpp"
#include "../console-interface/Output-in-Console.cpp"

#include <cstdlib>
#include <ctime>
#include <memory>
#include <thread>
#include <mutex>

std::mutex mtx;
bool running = true;

void logToCSV(Simulation& sim, const std::string& filename) {
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(mtx);
        sim.writeToCSV();
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Simulation sim(0.1f, 9.8f, 0.98f, false, 800.0f, 600.0f, 1);
    sim.initializeCSV("output.csv");
    //setting values for random cells
    const int numCells = 10;
    const float mass = 1.0f;


    for (int i = 0; i < numCells; ++i) {
        float x = static_cast<float>(std::rand() % 800);
        float y = static_cast<float>(std::rand() % 600);
        float speed = static_cast<float>(std::rand() % 20);
        float direction = static_cast<float>(std::rand()) / RAND_MAX * 2.0f * M_PI;

        sim.instantiateMassCell(std::make_shared<MassCell>(i, x, y, mass, speed, direction));
    }

    std::thread csvLogger(logToCSV, std::ref(sim), "output.csv");

    for (int step = 0; step < 100; ++step) {
        sim.run(0.1f);
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        running = false;
    }
    csvLogger.join();
    sim.closeCSV();

    return 0;
}
