#include <iostream>
#include <cmath>

// Constants
const double g = 9.81; // Acceleration due to gravity (m/s^2)

// Rocket class
class Rocket {
public:
    // Constructor to initialize rocket parameters
    Rocket(double initialVelocity, double launchAngle, double mass)
        : initialVelocity(initialVelocity), launchAngle(launchAngle), mass(mass) {}

    // Function to simulate rocket trajectory
    void simulate(double timeStep, double totalTime) {
        double t = 0.0;
        double x, y, vx, vy;

        // Initial conditions
        x = y = vx = vy = 0.0;
        vx = initialVelocity * cos(launchAngle);
        vy = initialVelocity * sin(launchAngle);

        // Simulation loop
        while (t <= totalTime) {
            // Update position and velocity
            x += vx * timeStep;
            y += vy * timeStep;
            vy -= g * timeStep; // Gravity

            // Output current state
            std::cout << "Time: " << t << "s - Position: (" << x << ", " << y << ") - ";

            // Print rocket trajectory using enhanced ASCII art
            printRocketTrajectory(y);

            // Check for impact
            if (y <= 0.0) {
                std::cout << "\nRocket impacted the ground.\n";
                break;
            }

            // Update time
            t += timeStep;
        }
    }

private:
    double initialVelocity;
    double launchAngle;
    double mass;

    // Function to print rocket trajectory using enhanced ASCII art
    void printRocketTrajectory(double altitude) {
        int numSpaces = static_cast<int>(altitude);
        for (int i = 0; i < numSpaces; ++i) {
            std::cout << " ";
        }

        // Print the rocket symbol
        std::cout << "*";

        std::cout << "\n";
    }
};

int main() {
    // User inputs
    double initialVelocity, launchAngle, mass, timeStep, totalTime;

    // Get user inputs
    std::cout << "Enter initial velocity (m/s): ";
    std::cin >> initialVelocity;

    std::cout << "Enter launch angle (degrees): ";
    std::cin >> launchAngle;
    launchAngle = launchAngle * M_PI / 180.0; // Convert to radians

    std::cout << "Enter rocket mass (kg): ";
    std::cin >> mass;

    std::cout << "Enter time step (s): ";
    std::cin >> timeStep;

    std::cout << "Enter total simulation time (s): ";
    std::cin >> totalTime;

    // Create rocket
    Rocket rocket(initialVelocity, launchAngle, mass);

    // Simulate rocket trajectory
    rocket.simulate(timeStep, totalTime);

    return 0;
}
