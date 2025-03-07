#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <iomanip>

class Book {
private:
    std::string isbn;
    std::string author;
    std::string title;
    int edition;
    std::string publisher;
    double price;

public:
    // Default constructor
    Book();

    // Parameterized constructor
    Book(std::string isbn, std::string author, std::string title, int edition, std::string publisher, double price);

    // Getter for ISBN
    std::string getISBN() const;

    // Setter for price
    void setPrice(double newPrice);

    // Print book details
    void printBook() const;

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << std::left << std::setw(12) << book.getISBN()
           << std::setw(18) << book.getAuthor()
           << std::setw(45) << book.getTitle()
           << std::setw(4) << book.getEdition()
           << std::setw(4) << book.getPublisher()
           << "$" << std::fixed << std::setprecision(2) << std::setw(8) << book.getPrice();
        return os;
    
};

#endif