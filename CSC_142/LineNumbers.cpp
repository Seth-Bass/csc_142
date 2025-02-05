/*
    File Name: LineNumbers.cpp
    Description: This program reads an input file, adds line numbers to each line of text, and writes the output to a new file. The line numbers are right-justified in a field of 5 characters wide, followed by a period and a space, then the text of the line. Blank lines are preserved with appropriate line numbers.
    Author: Seth Bassett
    Date: February 5, 2025
*/

#include <iostream>
#include <fstream>
#include <iomanip>  // For formatting output with setw()

int main() {
    std::string inputFileName, outputFileName;
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string line;
    int lineNumber = 1;

    // Prompt for input file name
    std::cout << "Enter the name of the input file: ";
    std::getline(std::cin, inputFileName);

    // Open the input file for reading
    inputFile.open(inputFileName);
    if (!inputFile) {
        std::cerr << "Error: Could not open the input file " << inputFileName << std::endl;
        return 1;  // Exit if the input file can't be opened
    }

    // Prompt for output file name
    std::cout << "Enter the name of the output file: ";
    std::getline(std::cin, outputFileName);

    // Open the output file for writing
    outputFile.open(outputFileName);
    if (!outputFile) {
        std::cerr << "Error: Could not open the output file " << outputFileName << std::endl;
        return 1;  // Exit if the output file can't be opened
    }

    // Read each line from the input file, add line numbers, and write to the output file
    while (std::getline(inputFile, line)) {
        outputFile << std::setw(5) << std::right << lineNumber << ". " << line << std::endl;
        lineNumber++;  // Increment line number
    }

    // Close both files
    inputFile.close();
    outputFile.close();

    std::cout << "Line numbers have been added and written to the output file." << std::endl;

    return 0;
}
