#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

// Function to check if a number is even
bool isEven(int n) {
    return (n % 2 == 0);
}

int main() {
    srand(time(0)); // Seed the random number generator

    const int TOTAL_NUMBERS = 1000;
    int evenCount = 0, oddCount = 0;

    // Generate 1000 random numbers in range [0, 100]
    for (int i = 0; i < TOTAL_NUMBERS; i++) {
        int randomNum = rand() % 101; // Random number in range [0, 100]

        if (isEven(randomNum)) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    // Display the results in a "creative" format
    std::cout << "🌟 Random Number Analysis 🌟\n";
    std::cout << "---------------------------------\n";
    std::cout << "Total numbers generated: " << TOTAL_NUMBERS << "\n";
    std::cout << "Even numbers count: " << evenCount << " 🎉\n";
    std::cout << "Odd numbers count: " << oddCount << " 🔥\n";
    std::cout << "Even percentage: " << (evenCount * 100.0 / TOTAL_NUMBERS) << "% 📏\n";
    std::cout << "Odd percentage: " << (oddCount * 100.0 / TOTAL_NUMBERS) << "% 📏\n";
    std::cout << "---------------------------------\n";
    std::cout << "Even or odd, every number has its own magic! ✨\n";

    return 0;
}
