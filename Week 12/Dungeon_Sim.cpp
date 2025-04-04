#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

int main() {
    srand(time(0));  // Seed random number generator

    int hero_HP = 20, hero_AC = 15;
    int goblin_HP = 10, goblin_AC = 12;

    cout << "Combat begins between Hero and Goblin!\n\n";

    while (hero_HP > 0 && goblin_HP > 0) {
        // Hero's turn
        cout << "-- Hero's turn --\n";
        int hero_roll = rollDice(20);
        cout << "Hero rolls a " << hero_roll;
        if (hero_roll >= goblin_AC) {
            int hero_damage = rollDice(8);
            goblin_HP -= hero_damage;
            cout << " and hits the Goblin!\n";
            cout << "Hero deals " << hero_damage << " damage. ";
            cout << "Goblin has " << (goblin_HP > 0 ? goblin_HP : 0) << " HP remaining.\n\n";
        } else {
            cout << " and misses!\n\n";
        }

        if (goblin_HP <= 0) break;

        // Goblin's turn
        cout << "-- Goblin's turn --\n";
        int goblin_roll = rollDice(20);
        cout << "Goblin rolls a " << goblin_roll;
        if (goblin_roll >= hero_AC) {
            int goblin_damage = rollDice(6);
            hero_HP -= goblin_damage;
            cout << " and hits!\n";
            cout << "Goblin deals " << goblin_damage << " damage. ";
            cout << "Hero has " << (hero_HP > 0 ? hero_HP : 0) << " HP remaining.\n\n";
        } else {
            cout << " and misses!\n\n";
        }
    }

    if (hero_HP > 0) {
        cout << "Goblin is defeated! Hero wins the battle!\n";
    } else {
        cout << "Hero has fallen! Goblin wins the battle!\n";
    }

    return 0;
}
