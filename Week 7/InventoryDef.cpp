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
bool Inventory::addBook(const Book& newBook) {
    if (count >= MAX_BOOKS) return false;

    for (int i = 0; i < count; ++i) {
        if (books[i] == newBook) {
            return false; // Duplicate found
        }
    }

    books[count++] = newBook;
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
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    std::cout << "ISBN        AUTHOR          TITLE                                       ED  PUB     PRICE" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < count; ++i) {
        std::cout << books[i] << std::endl;
    }

    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
}