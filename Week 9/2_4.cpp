#include <iostream>

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Operation op;

    Calculator(Operation operation) : op(operation) {}

    int calculate(int a, int b) {
        switch (op) {
            case Operation::Add: return a + b;
            case Operation::Subtract: return a - b;
            case Operation::Multiply: return a * b;
            case Operation::Divide:
                return (b != 0) ? (a / b) : 0;
        }
        return 0;
    }
};

int main() {
    // Different Initialization Methods
    Calculator calc1(Operation::Add);             // Direct Initialization
    Calculator calc2{Operation::Subtract};        // Uniform Initialization
    Calculator calc3 = Calculator(Operation::Multiply);  // Copy Initialization
    Calculator calc4 = {Operation::Divide};       // Assignment after declaration
    Calculator* calc5 = new Calculator(Operation::Add);  // Dynamic Allocation
    Calculator calc6 = [](Operation op) { return Calculator(op); }(Operation::Multiply);  // Lambda Function Initialization

    // Testing
    std::cout << "Addition (3 + 2): " << calc1.calculate(3, 2) << std::endl;
    std::cout << "Subtraction (10 - 5): " << calc2.calculate(10, 5) << std::endl;
    std::cout << "Multiplication (4 * 6): " << calc3.calculate(4, 6) << std::endl;
    std::cout << "Division (20 / 4): " << calc4.calculate(20, 4) << std::endl;
    std::cout << "Lambda Multiplication (8 * 3): " << calc6.calculate(8, 3) << std::endl;

    delete calc5;  // Free dynamically allocated memory

    return 0;
}
