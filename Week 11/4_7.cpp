#include <iostream>
#include <cstring>
#include <stdexcept>
#include <utility>

class SimpleString {
public:
    SimpleString();                                                  // Default constructor
    explicit SimpleString(size_t max_size);                          // One-argument constructor
    ~SimpleString();                                                 // Destructor

    SimpleString(const SimpleString &rhs) noexcept;                  // Copy constructor
    SimpleString& operator=(const SimpleString &rhs) noexcept;       // Copy assignment operator 

    SimpleString(SimpleString &&rhs) noexcept;                       // Move constructor
    SimpleString& operator=(SimpleString &&rhs) noexcept;            // Move assignment operator

    void print(const char *tag) const {
        std::cout << tag << ": " << m_buffer << '\n';
    }

    bool append_line(const char *x);                                 // Appends a new line to the buffer

private:
    size_t m_max_size;
    char  *m_buffer;
    size_t m_length;
};

// Default constructor
SimpleString::SimpleString()
    : m_max_size{ 256 }, m_buffer{ new char[256] }, m_length{} { }

// One-argument constructor
SimpleString::SimpleString(size_t max_size)
    : m_max_size{ max_size }, m_length{} {

    if (max_size == 0)
        throw std::runtime_error{ "Max size must be at least 1." };

    m_buffer = new char[max_size];
    m_buffer[0] = '\0';
}

// Destructor
SimpleString::~SimpleString() {
    delete[] m_buffer;
}

// Copy constructor
SimpleString::SimpleString(const SimpleString &rhs) noexcept
    : m_max_size{ rhs.m_max_size },
      m_buffer{ new char[rhs.m_max_size] },
      m_length{ rhs.m_length } {

    std::strncpy(m_buffer, rhs.m_buffer, m_max_size);
}

// Copy assignment operator
SimpleString& SimpleString::operator=(const SimpleString &rhs) noexcept {
    if (this == &rhs) return *this;

    delete[] m_buffer;
    m_buffer = new char[rhs.m_max_size];
    m_max_size = rhs.m_max_size;
    m_length = rhs.m_length;

    std::strncpy(m_buffer, rhs.m_buffer, m_max_size);
    return *this;
}

// Move constructor
SimpleString::SimpleString(SimpleString &&rhs) noexcept
    : m_max_size{ rhs.m_max_size },
      m_buffer{ rhs.m_buffer },
      m_length{ rhs.m_length } {

    rhs.m_buffer = nullptr;
    rhs.m_max_size = 0;
    rhs.m_length = 0;
}

// Move assignment operator
SimpleString& SimpleString::operator=(SimpleString &&rhs) noexcept {
    if (this == &rhs) return *this;

    delete[] m_buffer;
    m_buffer = rhs.m_buffer;
    m_max_size = rhs.m_max_size;
    m_length = rhs.m_length;

    rhs.m_buffer = nullptr;
    rhs.m_length = 0;
    rhs.m_max_size = 0;

    return *this;
}

// Append line to buffer
bool SimpleString::append_line(const char *x) {
    const auto x_len = strlen(x);

    if (x_len + m_length + 2 > m_max_size)
        return false;

    std::strncpy(m_buffer + m_length, x, m_max_size - m_length);
    m_length += x_len;
    m_buffer[m_length++] = '\n';
    m_buffer[m_length] = 0;

    return true;
}

// Main function
int main() {
    try {
        SimpleString a{ 50 };
        a.append_line("C++ is the better programming language!");

        SimpleString b{ 50 };
        b.append_line("No, Java is way better!");

        a.print("a ");
        b.print("b ");

        b = a; // Copy assignment to change b's mind

        a.print("a ");
        b.print("b ");
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
