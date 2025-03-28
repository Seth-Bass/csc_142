#include <iostream>

// Uses a reference to increase hero's HP

void drinkPotion(int& hp, int healing) {
    hp += healing;

hp = hp + healing;
}

// Uses a pointer to reduce hero's HP

void damageHero(int* hp, int damage) {
    *hp -= damage;
}

int main() {
    int heroHP = 20;

    std::cout << "Hero's starting HP: " << heroHP << std::endl;

    std::cout << "Hero drinks a healing potion (+5 HP)." << std::endl;
    drinkPotion(heroHP, 5);
    std::cout << "Hero's current HP: " << heroHP << std::endl;

    std::cout << "Hero takes damage from a goblin (-12 HP)." << std::endl;
    damageHero(&heroHP, 12);
    std::cout << "Hero's current HP: " << heroHP << std::endl;

    return 0;
}
