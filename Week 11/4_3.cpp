#include <iostream>
#include <chrono>
#include <thread>  // for std::this_thread::sleep_for

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

    // Copy constructor
    TimerClass(const TimerClass &rhs)
        : m_timestamp{ rhs.m_timestamp }
    { }

    // Copy assignment
    TimerClass& operator=(const TimerClass &rhs) {
        if (this == &rhs) return *this;
        m_timestamp = rhs.m_timestamp;
        return *this;
    }

private:
    std::chrono::steady_clock::time_point m_timestamp;
};

int main() {
    std::cout << "Creating timer t1...\n";
    TimerClass t1;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Copying t1 to t2 using copy constructor...\n";
    TimerClass t2 = t1;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Assigning t1 to t2 using copy assignment...\n";
    t2 = t1;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Exiting main, destructors will print elapsed time...\n";

    return 0;
}
