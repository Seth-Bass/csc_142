#include <iostream>

// Define the enum class
enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

int main() {
    // Example usage
    Operation op = Operation::Add;

    if (op == Operation::Add) {
        std::cout << "The operation is Addition." << std::endl;
    }

    return 0;
}
