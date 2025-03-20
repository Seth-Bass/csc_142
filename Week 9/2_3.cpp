#include <iostream>

// Define the enum class Operation
enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

// Define the Calculator struct
struct Calculator {
    Operation op;  // Member variable to store the operation

    // Constructor
    Calculator(Operation operation) : op(operation) {}

    // Method to perform the calculation
    int calculate(int a, int b) {
        switch (op) {
            case Operation::Add:
                return a + b;
            case Operation::Subtract:
                return a - b;
            case Operation::Multiply:
                return a * b;
            case Operation::Divide:
                if (b != 0) {
                    return a / b;
                } else {
                    std::cerr << "Error: Division by zero!" << std::endl;
                    return 0; // Return 0 as a safe fallback
                }
            default:
                std::cerr << "Error: Unknown operation!" << std::endl;
                return 0;
        }
    }
};

int main() {
    // Create Calculator instances with different operations
    Calculator addCalc(Operation::Add);
    Calculator subCalc(Operation::Subtract);
    Calculator mulCalc(Operation::Multiply);
    Calculator divCalc(Operation::Divide);

    // Test calculations
    std::cout << "Addition (5 + 3): " << addCalc.calculate(5, 3) << std::endl;
    std::cout << "Subtraction (10 - 4): " << subCalc.calculate(10, 4) << std::endl;
    std::cout << "Multiplication (6 * 7): " << mulCalc.calculate(6, 7) << std::endl;
    std::cout << "Division (20 / 5): " << divCalc.calculate(20, 5) << std::endl;
    std::cout << "Division by zero (10 / 0): " << divCalc.calculate(10, 0) << std::endl;

    return 0;
}
