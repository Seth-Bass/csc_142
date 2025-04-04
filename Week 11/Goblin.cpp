#include <iostream>

class Goblin {
public:
    // Constructor
    Goblin() {
        std::cout << "A Goblin has been summoned!" << std::endl;
    }

    // Destructor
    ~Goblin() {
        std::cout << "The Goblin has died!" << std::endl;
    }
};

int main() {
    {
        Goblin goblin;  // Goblin created here
    }  // Goblin goes out of scope here, destructor called

    return 0;
}
