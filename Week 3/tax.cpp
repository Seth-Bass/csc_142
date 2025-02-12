/*
    File: tax.cpp
    Description: This program calculates the sales tax and total amount of a retail purchase.
               The user inputs the description and cost of the purchase, and the program
               computes the sales tax, total amount, and displays the results.
               The user can then decide whether to enter another purchase or quit the program.
    Author: Seth Bassett
    Date: February 2, 2025
 */

#include <iostream>
#include <string>
#include <iomanip> // For setting the output format

int main() {
    // Constant for sales tax rate (6%)
    const double SALES_TAX_RATE = 0.06;

    // Boolean variable to control the loop
    bool keepGoing = true;

    // Loop to keep accepting purchases until user chooses to quit
    while (keepGoing) {
        std::string description;
        std::string inputCost;
        double cost;

        // Step 1: Ask for the purchase description
        std::cout << "Enter the description of the purchase: ";
        std::getline(std::cin, description);

        // Step 2: Ask for the cost of the purchase and validate that it is non-negative
        do {
            std::cout << "Enter the cost of the purchase (in dollars and cents): ";
            std::getline(std::cin, inputCost);

            // Convert input string to double
            cost = std::stod(inputCost);

            if (cost < 0) {
                std::cout << "Invalid input. Cost cannot be negative. Please try again.\n";
            }
        } while (cost < 0);

        // Step 3: Calculate sales tax
        double salesTax = cost * SALES_TAX_RATE;

        // Step 4: Calculate total amount (cost + sales tax)
        double totalAmount = cost + salesTax;

        // Step 5: Display results with proper formatting
        std::cout << "\nPurchase Details:\n";
        std::cout << "Description: " << description << "\n";
        std::cout << "Cost: $" << std::fixed << std::setprecision(2) << cost << "\n";
        std::cout << "Sales Tax (6%): $" << std::fixed << std::setprecision(2) << salesTax << "\n";
        std::cout << "Total Amount: $" << std::fixed << std::setprecision(2) << totalAmount << "\n\n";

        // Step 6: Ask if the user wants to enter another purchase
        std::string userResponse;
        std::cout << "Would you like to enter another purchase? (Yes/No): ";
        std::getline(std::cin, userResponse);

        // Convert the response to lowercase for easier comparison
        for (char& c : userResponse) {
            c = std::tolower(c);
        }

        if (userResponse == "no") {
            keepGoing = false;
        }
    }

    // End of program
    std::cout << "\nThank you for using the Tax Calculator. Goodbye!\n";
    return 0;
}
