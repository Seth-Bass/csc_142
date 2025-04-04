#include <iostream>
#include <chrono>
#include <exception>
#include <limits>

class TimerClass {
public:
    TimerClass(const char *name)
        : m_timestamp{ std::chrono::steady_clock::now() },
          m_name{ name } { }

    ~TimerClass() {
        auto current = std::chrono::steady_clock::now() - m_timestamp;
        std::cout << m_name << std::chrono::duration_cast<std::chrono::microseconds>(current).count();
        std::cout << " microseconds\n";
    }

    TimerClass(const TimerClass &rhs) noexcept
        : m_timestamp{ rhs.m_timestamp },
          m_name{ rhs.m_name } { }

    TimerClass& operator=(const TimerClass &rhs) noexcept {
        if (this == &rhs) return *this;
        m_timestamp = rhs.m_timestamp;
        m_name = rhs.m_name;
        return *this;
    }

    TimerClass(TimerClass &&rhs) noexcept
        : m_timestamp{ rhs.m_timestamp },
          m_name{ rhs.m_name } { }

    TimerClass& operator=(TimerClass &&rhs) noexcept {
        if (this == &rhs) return *this;
        m_timestamp = rhs.m_timestamp;
        m_name = rhs.m_name;
        return *this;
    }

private:
    std::chrono::steady_clock::time_point m_timestamp;
    const char *m_name;
};

void fibonacci(long long fib1, long long fib2, long long n, TimerClass &&timer) {
    if (n < 2) throw std::runtime_error{ "n must be at least 2." };

    std::cout << fib1 << ", " << fib2 << ", ";
    for (auto i{fib2}; i < n; ++i) {
        long long temp{ fib1 + fib2 };
        if (temp < 0) throw std::runtime_error{ "int overflow!" };
        fib1 = fib2;
        fib2 = temp;

        std::cout << fib2;
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << "\n\n";
}

int main() {
    try {
        std::cout << "How many fibonacci numbers do you want to see computed?\n";
        std::cout << "Enter -1 to quit.\n";

        while (true) {
            std::cout << "> ";
            long long n{};
            std::cin >> n;

            if (std::cin) {
                if (n == -1) break;

                std::cout << "fibonacci(" << n << "): ";
                fibonacci(1LL, 2LL, n, TimerClass{ "Time: " });
                std::cout << "\n\n";
            }
            else if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                std::cout << "Sorry, you didn't enter a number. Try again\n";
            }
            else {
                throw std::runtime_error{ "bad input" };
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << "exception: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "unknown exception caught\n";
        return 2;
    }

    return 0;
}
