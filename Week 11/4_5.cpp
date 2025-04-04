#include <iostream>
#include <chrono>
#include <thread>  // For sleep_for

class TimerClass {

public:
    TimerClass(const char *name)
        : m_timestamp{ std::chrono::steady_clock::now() },
          m_name{ name } { }

    ~TimerClass() {
        auto current = std::chrono::steady_clock::now() - m_timestamp;
        std::cout << m_name << ": "
                  << std::chrono::duration_cast<std::chrono::microseconds>(current).count()
                  << " microseconds\n";
    }

    // Copy constructor
    TimerClass(const TimerClass &rhs) noexcept
        : m_timestamp{ rhs.m_timestamp },
          m_name{ rhs.m_name } { }

    // Copy assignment
    TimerClass& operator=(const TimerClass &rhs) noexcept {
        if (this == &rhs) return *this;
        m_timestamp = rhs.m_timestamp;
        m_name = rhs.m_name;
        return *this;
    }

    // Move constructor
    TimerClass(TimerClass &&rhs) noexcept
        : m_timestamp{ rhs.m_timestamp },
          m_name{ rhs.m_name } { }

    // Move assignment
    TimerClass& operator=(TimerClass &&rhs) noexcept {
        if (this == &rhs) return *this;
        m_timestamp = rhs.m_timestamp;
        m_name = rhs.m_name;
        return *this;
    }

private:
    std::chrono::steady_clock::time_point m_timestamp;
    const char *m_name{};
};

int main() {
    std::cout << "Creating timer T1...\n";
    TimerClass t1("T1");

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Copying T1 to T2...\n";
    TimerClass t2 = t1;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "Moving T1 to T3...\n";
    TimerClass t3 = std::move(t1);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "End of main, destructors will now run...\n";
    return 0;
}
