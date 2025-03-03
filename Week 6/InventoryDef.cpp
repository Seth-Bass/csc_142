#include "Inventory.h"


// Constructor: Dynamically allocates an array of 'size' Book objects
Inventory::Inventory(int size) : length(size), nextEntry(0) {
    books = new Book[length]; // Allocate array of Book objects
}

// Destructor: Deletes the dynamically allocated array
Inventory::~Inventory() {
    delete[] books;
}

// Add a book to the inventory
bool Inventory::addBook(const Book& theBook) {
    if (nextEntry >= length) {
        return false; // Inventory is full
    }
    books[nextEntry] = theBook;
    nextEntry++;
    return true;
}

// Change the price of a book given its ISBN
void Inventory::changePrice(std::string isbn, double newPrice) {
    for (int i = 0; i < nextEntry; i++) {
        if (books[i].getISBN() == isbn) {
            books[i].setPrice(newPrice);
            return;
        }
    }
}

// Print the entire inventory
void Inventory::printInventory() const {
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::cout << "ISBN            AUTHOR              TITLE                                   ED  PUB   PRICE\n";
    std::cout << "---------------------------------------------------------------------------------------\n";
    for (int i = 0; i < nextEntry; i++) {
        books[i].printBook();
    }
    std::cout << "---------------------------------------------------------------------------------------\n";
}
