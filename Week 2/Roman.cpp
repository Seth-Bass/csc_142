/*
    File Name: Roman.cpp
    Description: This program prompts the user to input an integer in the range [1, 10] and converts the input into its Roman numeral equivalent.
                 The program ensures that invalid input is re-entered correctly.
    Author: [Your Name]
    Date: [Today's Date]
*/

#include <iostream>

int main() {
    int num;

    // Use a do-while loop to get a valid input in the range [1, 10]
    do {
        std::cout << "Please enter an integer between 1 and 10: ";
        std::cin >> num;

        // Check for valid input
        if (num < 1 || num > 10) {
            std::cout << "Invalid input! Please enter a number between 1 and 10.\n";
        }
    } while (num < 1 || num > 10); // Loop until valid input is entered

    // Convert the number to a Roman numeral using a single multi-branch if statement
    std::cout << "The Roman numeral for " << num << " is: ";
    if (num == 1)
        std::cout << "I";
    else if (num == 2)
        std::cout << "II";
    else if (num == 3)
        std::cout << "III";
    else if (num == 4)
        std::cout << "IV";
    else if (num == 5)
        std::cout << "V";
    else if (num == 6)
        std::cout << "VI";
    else if (num == 7)
        std::cout << "VII";
    else if (num == 8)
        std::cout << "VIII";
    else if (num == 9)
        std::cout << "IX";
    else if (num == 10)
        std::cout << "X";
    std::cout << std::endl;

    return 0;
}
