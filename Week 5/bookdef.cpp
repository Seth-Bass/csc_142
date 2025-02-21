#include "Book.h"

// Constructor definition
Book::Book(std::string cn, std::string au, std::string ti, int ed, std::string pc, double pr) {
    codeNum = cn;
    author = au;
    title = ti;
    edition = ed;
    pubCode = pc;
    price = pr;
}

// Accessor methods
std::string Book::getISBN() const { return codeNum; }
std::string Book::getAuthor() const { return author; }
std::string Book::getTitle() const { return title; }
int Book::getEdition() const { return edition; }
std::string Book::getPubCode() const { return pubCode; }
double Book::getPrice() const { return price; }

// Mutator method
void Book::changePrice(double newPrice) { price = newPrice; }
