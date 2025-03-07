#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"

class Inventory {
private:
    Book* books;   // Pointer to dynamically allocated array of books
    int nextEntry; // Index where the next book will be added
    int length;    // Maximum size of the inventory

public:
    // Constructor
    Inventory(int size);

    // Destructor
    ~Inventory();

    // Add a book to the inventory
    bool addBook(const Book& theBook);

    // Change the price of a book given its ISBN
    void changePrice(std::string isbn, double newPrice);

    // Print the entire inventory
    void printInventory() const;
};

#endif
