#include <iostream>
#include <string>

// Answer
// Define enumeration (pages 49-51)
enum class CharacterClass { Warrior, Mage, Archer, Rogue };

// User-defined structure. Struct can also be called class(page 52)
struct Character {
    std::string name;
    CharacterClass type;
    int health;
    float strength;
};

// Helper function to convert enum to string for printing. Switch command p.50-51
// It shows how to handle printing enums in a readable format
std::string classToString(CharacterClass type) {
    switch(type) {
        case CharacterClass::Warrior: return "Warrior";
        case CharacterClass::Mage:    return "Mage";
        case CharacterClass::Archer:  return "Archer";
        case CharacterClass::Rogue:   return "Rogue";
        default:                      return "Unknown";
    }
}

int main() {
    // Array of characters initialization (pages 42-45, 52)
    Character characters[4]{
      
        {"Ares",  CharacterClass::Warrior, 100, 90.5f},
        {"Zeus", CharacterClass::Mage,    120, 75.0f},
        {"Athena", CharacterClass::Archer,   85, 80.0f},
        {"Zagreus",   CharacterClass::Rogue,    80, 60.5f}
    };

    // Display characters details
    std::cout << "Characters:\n------------\n";

                      for (int i = 0; i < 4; i++) {
        std::cout << "Name: " << characters[i].name << ", Type: " << classToString(characters[i].type)
                  << ", Health: " << characters[i].health
                  << ", Strength: " << characters[i].strength
                  << std::endl;
    }

    // Calculate average health
    int sumHealth = 0;
    for (int i = 0; i < 4; i++) {
        sumHealth += characters[i].health;
    }
    // static_cast explicitly converts one data type into another. (Page 152)
    float avgHealth = static_cast<float>(sumHealth) / 4.0f;
    
    std::cout << "\nAverage Health: " << avgHealth << std::endl;


    return 0;
}
