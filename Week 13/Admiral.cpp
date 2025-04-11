#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Inputs
    double distance, fuel, spaceship_weight, life_support;
    int crew_size;

    std::cout << "Enter distance to planet (million km): ";
    std::cin >> distance;

    std::cout << "Enter fuel available (tons): ";
    std::cin >> fuel;

    std::cout << "Enter crew size: ";
    std::cin >> crew_size;

    std::cout << "Enter spaceship weight (tons): ";
    std::cin >> spaceship_weight;

    std::cout << "Enter life support duration (days): ";
    std::cin >> life_support;

    // Calculations
    // 1. Fuel efficiency (%)
    double efficiency = (fuel / spaceship_weight) * 100;

    // 2. Travel speed (km/day)
    double speed = (fuel * 10000) / (crew_size * spaceship_weight);

    // 3. Travel time (days), rounded up
    double travel_time = (distance * 1000000) / speed;
    int travel_days = static_cast<int>(std::ceil(travel_time));

    // 4. Check viability
    bool is_viable = (efficiency >= 20.0) &&
                     (life_support >= travel_days + 10) &&
                     (crew_size >= 2 && crew_size <= 8) &&
                     (spaceship_weight < 500);

    // Outputs
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nFuel efficiency: " << efficiency << "%\n";

    std::cout << std::setprecision(0);
    std::cout << "Estimated speed: " << speed << " km/day\n";
    std::cout << "Estimated travel time: " << travel_days << " days\n";

    std::cout << "\nMission Status: ";
    if (is_viable) {
        std::cout << "VIABLE\n";
    } else {
        std::cout << "NOT VIABLE\n";
    }

    return 0;
}
