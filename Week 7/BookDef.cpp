#include "Book.h"

// Default constructor
Book::Book() : isbn(""), author(""), title(""), edition(0), publisher(""), price(0.0) {}

// Parameterized constructor
Book::Book(std::string isbn, std::string author, std::string title, int edition, std::string publisher, double price)
    : isbn(isbn), author(author), title(title), edition(edition), publisher(publisher), price(price) {}

// Getter for ISBN
std::string Book::getISBN() const {
    return isbn;
}

// Setter for price
void Book::setPrice(double newPrice) {
    price = newPrice;
}

// Print book details
void Book::printBook() const {
    std::cout << std::left << std::setw(15) << isbn
              << std::setw(20) << author
              << std::setw(40) << title
              << std::setw(4) << edition
              << std::setw(5) << publisher
              << "$" << std::setw(8) << std::fixed << std::setprecision(2) << price
              << std::endl;
}

bool Book::operator==(const Book& other) const {
    return this->getISBN() == other.getISBN();
}