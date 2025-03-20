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
};

int main() {
    // Create a Calculator instance with Operation::Multiply
    Calculator calc(Operation::Multiply);

    // Check which operation was set
    if (calc.op == Operation::Multiply) {
        std::cout << "The calculator is set to Multiply." << std::endl;
    }

    return 0;
}
