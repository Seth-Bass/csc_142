#include <iostream>
#include <chrono>

struct TimerClass {
public:
    TimerClass()
        : m_timestamp{ std::chrono::steady_clock::now() }
    { }

private:
    std::chrono::steady_clock::time_point m_timestamp;
};

int main() {
    TimerClass timer;
    std::cout << "Timer initialized!" << std::endl;
    return 0;
}
