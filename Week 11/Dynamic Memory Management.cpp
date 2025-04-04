#include <iostream>
#include <string>

class Inventory {
private:
    std::string* items;
    int capacity;
    int count;

public:
    // Constructor
    Inventory(int cap = 10)
        : capacity(cap), count(0) {
        items = new std::string[capacity];
    }

    // Copy Constructor (Deep copy)
    Inventory(const Inventory& other)
        : capacity(other.capacity), count(other.count) {
        items = new std::string[capacity];
        for (int i = 0; i < count; i++) {
            items[i] = other.items[i];
        }
    }

    // Destructor
    ~Inventory() {
        delete[] items;
    }

    // Add an item
    void addItem(const std::string& item) {
        if (count < capacity) {
            items[count++] = item;
        } else {
            std::cout << "Inventory full! Cannot add more items." << std::endl;
        }
    }

    // Display inventory contents
    void showInventory() const {
        for (int i = 0; i < count; i++) {
            std::cout << "- " << items[i] << std::endl;
        }
    }
};

int main() {
    // Create first inventory and add items
    Inventory inventory1;
    inventory1.addItem("Demonic Sword");
    inventory1.addItem("Potion of Haste");

    // Use copy constructor to create a second inventory
    Inventory inventory2 = inventory1;
    inventory2.addItem("Bag of Cartoons");
    inventory2.addItem("Badge of the Raven");

    // Display inventories
    std::cout << "Inventory 1:" << std::endl;
    inventory1.showInventory();

    std::cout << "\nInventory 2:" << std::endl;
    inventory2.showInventory();

    return 0;
}
