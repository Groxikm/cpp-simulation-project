#include "../lib/mass/MassCell.cpp"
#include "../simulations/Simulation.cpp"
#include "../console-interface/Output-in-Console.cpp"

#include <cstdlib>
#include <ctime>
#include <memory>
#include <thread>
#include <mutex>

// Simulation parameters
const float timeCoefficient = 0.01f;
const float gravityCoefficient = -9.8f;
const float reactionCoefficient = 0.98f;
const bool ceilingEnabled = true;
const float groundWidth = 800.0f;
const float wallsHeight = 600.0f;
const long simulationID = 1;
const int numCells = 16;

const int maxInitialSpeed = 20;
const int maxInitialX = 800;
const int maxInitialY = 600;
const int maxMass = 300;

const int numSteps = 100;
const float timeStep = 0.1f;

const char* outputFilename = "output.csv";
const int csvLogIntervalMs = 100;

std::mutex mtx;
bool running = true;

void logToCSV(Simulation& sim, const std::string& filename) {
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(csvLogIntervalMs));
        std::lock_guard<std::mutex> lock(mtx);
        sim.writeToCSV();
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Initialize simulation
    Simulation sim(timeCoefficient, gravityCoefficient, reactionCoefficient, ceilingEnabled, groundWidth, wallsHeight, simulationID);
    sim.initializeCSV(outputFilename);

    // creating cells with random positions and velocities
    for (int i = 0; i < numCells; ++i) {
        float x = static_cast<float>(std::rand() % maxInitialX);
        float y = static_cast<float>(std::rand() % maxInitialY);
        float speed = static_cast<float>(std::rand() % maxInitialSpeed);
        float direction = static_cast<float>(std::rand()) / RAND_MAX * 2.0f * M_PI;
        float cellMass = static_cast<float>(std::rand() % maxMass);
        sim.instantiateMassCell(std::make_shared<MassCell>(i, x, y, cellMass, speed, direction));
    }

    // CSV logger thread
    std::thread csvLogger(logToCSV, std::ref(sim), outputFilename);

    // run
    for (int step = 0; step < numSteps; ++step) {
        sim.run(timeStep);
    }

    // stop logging and close CSV file
    {
        std::lock_guard<std::mutex> lock(mtx);
        running = false;
    }
    csvLogger.join();
    sim.closeCSV();

    return 0;
}
