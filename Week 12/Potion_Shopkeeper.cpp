#include <iostream>
using namespace std;

int main() {
    int gold = 100;
    int potion_cost = 10;
    int potions;

    cout << "Welcome to the Potion Shop!\n";
    cout << "Each healing potion costs " << potion_cost << " gold pieces.\n\n";
    cout << "How many potions would you like to buy? ";
    cin >> potions;

    int total_cost = potions * potion_cost;

    if (total_cost <= gold) {
        gold -= total_cost;
        cout << "You bought " << potions << " potions for " << total_cost << " gold pieces.\n";
        cout << "You now have " << gold << " gold pieces left. Safe travels, adventurer!\n";
    } else {
        cout << "You do not have enough gold to buy " << potions << " potions.\n";
        cout << "You only have " << gold << " gold pieces.\n";
    }

    return 0;
}
