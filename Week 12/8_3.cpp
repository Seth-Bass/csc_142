#include "FibonacciIterator.h"
#include "PrimeNumberRange.h"
#include "FibonacciRange.h"

#include <iostream>

 int main() {
    std::cout << "Fibonacci: ";
    for (const auto& i : FibonacciRange{ 5000 }) {
        std::cout << i << ' ';
    }

    std::cout << "\n\nPrime: ";
    PrimeNumberRange prime{ 5000 };

    while (true) {
        int n = prime.getCurrent();
        if (n < 0) break;

        std::cout << n << ' ';

        ++prime;
    }

    std::cout << '\n';
    return 0;
}
