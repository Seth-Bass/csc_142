/*
    File Name: SpeedTrap.cpp
    Description: This program checks whether a driver is speeding based on the given speed limit and the driver's speed. 
                 If the driver's speed exceeds the limit, they will receive a speeding ticket; otherwise, their speed is legal.
    Author: Seth Bassett
    Date: February 5, 2025
*/

#include <iostream>
using namespace std;

int main() {
    // Declare variables for speed limit and driver's speed
    int speedLimit;
    double driverSpeed;

    // Prompt the user to enter the speed limit
    cout << "Enter the speed limit: ";
    cin >> speedLimit;

    // Prompt the user to enter the driver's speed
    cout << "Enter the driver's speed: ";
    cin >> driverSpeed;

    // Check if the driver is speeding
    if (driverSpeed > speedLimit) {
        cout << "You are speeding! You will receive a ticket." << endl;
    } else {
        cout << "Your speed is legal. No ticket." << endl;
    }

    return 0;
}
