/*
    File Name: Exams.cpp
    Description: This program prompts the user to input their name and three exam scores, calculates the average of the scores, and displays all the input data along with the calculated average formatted to two decimal places.
    Author: Seth Bassett
    Date: February 5, 2025
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Declare variables for name, exam scores, and average
    string name;
    int score1, score2, score3;
    double average;

    // Prompt the user to input their name
    cout << "Please enter your name: ";
    getline(cin, name);

    // Prompt the user to input three exam scores
    cout << "Enter the first exam score: ";
    cin >> score1;

    cout << "Enter the second exam score: ";
    cin >> score2;

    cout << "Enter the third exam score: ";
    cin >> score3;

    // Calculate the average of the exam scores
    average = (score1 + score2 + score3) / 3.0;

    // Display the input data and the calculated average with appropriate formatting
    cout << fixed << setprecision(2); // Format the average to 2 decimal places
    cout << "\nStudent Name: " << name << endl;
    cout << "Exam 1 Score: " << score1 << endl;
    cout << "Exam 2 Score: " << score2 << endl;
    cout << "Exam 3 Score: " << score3 << endl;
    cout << "Average Score: " << average << endl;

    return 0;
}
