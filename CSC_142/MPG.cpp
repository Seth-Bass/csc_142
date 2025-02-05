/*
    File Name: MPG.cpp
    Description: This program calculates the fuel efficiency of a vehicle in both miles per gallon (MPG)
                and liters per 100 kilometers (L/100km) based on user input. It prompts the user for the vehicle description, miles traveled,
                and gallons of fuel used, then computes and displays the fuel efficiency in both units.
    Author: [Your Name]
    Date: January 27, 2025
*/

#include <iostream>
#include <iomanip> // For setting decimal precision

int main() {
    // Constant declarations
    const double KM_PER_MILE = 1.60934;  // Conversion factor from miles to kilometers
    const double LITERS_PER_GALLON = 3.78541;  // Conversion factor from gallons to liters

    // Variable declarations
    std::string desc;
    int miles;
    double gallons;      
    double mpg;
    double km;
    double liters;
    double l_per_100km;

    // Prompt for user inputs
    std::cout << "Please enter a description of your car: ";
    std::getline(std::cin, desc);
    std::cout << "How many miles did you drive? ";
    std::cin >> miles;
    std::cout << "How many gallons of gas did you use? ";
    std::cin >> gallons;

    // Calculate the results
    mpg = miles / gallons;  // Calculate miles per gallon
    km = miles * KM_PER_MILE;  // Convert miles to kilometers
    liters = gallons * LITERS_PER_GALLON;  // Convert gallons to liters
    l_per_100km = (liters / km) * 100;  // Calculate liters per 100 kilometers

    // Print the user inputs and final results with 2 decimal places precision
    std::cout << "\nFuel efficiency of your " + desc + ":\n";
    std::cout << "You drove " << miles << " miles and used " << gallons << " gallons.\n";
    std::cout << "Your fuel efficiency is " << std::fixed << std::setprecision(2) << mpg << " miles per gallon.\n";
    std::cout << "Your fuel efficiency is also " << std::fixed << std::setprecision(2) << l_per_100km << " liters per 100 kilometers.\n";

    return 0;
}
