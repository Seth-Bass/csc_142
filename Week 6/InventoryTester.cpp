#include "Inventory.h"


int main() {
    // Step 1: Create an Inventory object of size 10
    Inventory inventory(10);

    // Step 2: Add books
    Book books[] = {
        Book("013478796X", "Tony Gaddis", "Starting Out With Java: From Control Structures through Data Structures", 4, "PE", 121.75),
        Book("0321409493", "John Lewis", "Java Software Solutions: Foundations of Program Design", 5, "AW", 94.00),
        Book("0134743350", "Harvey Deitel", "Java How to Program, Early Objects", 12, "PE", 134.84),
        Book("002360692X", "Richard Johnsonbaugh", "Algorithms", 1, "PH", 109.00),
        Book("1593276036", "Eric Matthes", "Python Crash Course", 1, "NS", 39.95),
        Book("0143067889", "Ray Kurzweil", "The Singularity is Near", 1, "PG", 17.70)
    };

    for (const auto& book : books) {
        if (!inventory.addBook(book)) {
            std::cerr << "Failed to add book: " << book.getISBN() << std::endl;
        }
    }

    // Step 3: Print initial inventory
    std::cout << "\nInitial Inventory:\n";
    inventory.printInventory();

    // Step 4: Change book prices
    inventory.changePrice("013478796X", 50.00);
    inventory.changePrice("0143067889", 9.95);
    inventory.changePrice("0134743350", 100.00);

    // Step 5: Print final inventory
    std::cout << "\nFinal Inventory After Price Changes:\n";
    inventory.printInventory();

    return 0;
}
