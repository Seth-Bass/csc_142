#include <iostream>
#include <string>

class MagicItem {
public:
    MagicItem(const std::string& name, const std::string& powerType, int charges)
        : name_{name}, powerType_{powerType}, charges_{charges} {
        std::cout << name_ << " (" << powerType_ << " power) created with " << charges_ << " charges!\n";
    }

    void use() {
        if (charges_ > 0) {
            charges_--;
            std::cout << name_ << " (" << powerType_ << " power) used! Charges left: " << charges_ << "\n";
        } else {
            std::cout << name_ << " (" << powerType_ << " power) has no charges left!\n";
        }
    }

private:
    std::string name_;
    std::string powerType_;
    int charges_;
};

int main() {
    MagicItem wand{"Wand of Khazan", "Hell", 3};
    wand.use();

    MagicItem sword{"Sword of He-Man", "GraySkull", 2};
    sword.use();
    sword.use();
    sword.use();

    MagicItem amulet{"Amulet of Berserker's Fury", "Rage", 1};
    amulet.use();

    return 0;
}
