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
    {
        std::cout << "Creating timer A\n";
        TimerClass a("Timer A");

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::cout << "Copying A to B\n";
        TimerClass b = a;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::cout << "Moving A to C\n";
        TimerClass c = std::move(a);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "End of main, destructors will now run.\n";
    return 0;
}
