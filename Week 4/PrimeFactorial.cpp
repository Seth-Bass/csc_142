#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <limits>   // For numeric_limits

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to calculate factorial
double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    srand(time(0));  // Seed random number generator
    char choice;

    do {
        int randomNum = rand() % 50;  // Generate a random number < 50
        std::cout << "\nRandomly generated number: " << randomNum << std::endl;

        if (isPrime(randomNum)) {
            std::cout << "✅ " << randomNum << " is a prime number." << std::endl;
            std::cout << "Factorial of " << randomNum << " is: " << factorial(randomNum) << std::endl;
        } else {
            std::cout << "❌ " << randomNum << " is NOT a prime number." << std::endl;
        }

        // Ask the user if they want to repeat
        std::cout << "\nWould you like to try again? (y/n): ";
        std::cin >> choice;

        // Input validation (ensuring a valid response)
        while (std::cin.fail() || (choice != 'y' && choice != 'n')) {
            std::cin.clear();  // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no: ";
            std::cin >> choice;
        }

    } while (choice == 'y');

    std::cout << "Goodbye! 👋 Have a great day!\n";
    return 0;
}
