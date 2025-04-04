#include <iostream>
#include <chrono>
#include <thread>  // for std::this_thread::sleep_for (optional, for demo delay)

class TimerClass {

public:
    TimerClass()
        : m_timestamp{ std::chrono::steady_clock::now() }
    { }

    ~TimerClass() {
        auto current = std::chrono::steady_clock::now() - m_timestamp;
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(current).count();
        std::cout << " microseconds\n";
    }

private:
    std::chrono::steady_clock::time_point m_timestamp;
};

int main() {
    {
        TimerClass timer;
        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } // TimerClass goes out of scope here and prints the elapsed time

    return 0;
}
