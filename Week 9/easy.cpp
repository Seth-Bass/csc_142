#include <iostream>
#include <string>

int main() {
    // Step 1: Declare variables and get user input
    std::string name;
    int age;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your age: ";
    std::cin >> age;

    // Arithmetic operation (p. 32-35)
    int age_in_days = age * 365;

    // Output greeting and calculation (Chapters 1 & 2, pp. 4-5)
    std::cout << "\nHello, " << name 
              << "! You are approximately " 
              << age_in_days
 << " days old." << std::endl;

    return 0; // Indicates successful execution (p.4)
}
