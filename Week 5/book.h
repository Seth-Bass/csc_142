#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string codeNum;
    std::string author;
    std::string title;
    int edition;
    std::string pubCode;
    double price;

public:
    // Constructor
    Book(std::string cn, std::string au, std::string ti, int ed, std::string pc, double pr);

    // Accessor methods (getters)
    std::string getISBN() const;
    std::string getAuthor() const;
    std::string getTitle() const;
    int getEdition() const;
    std::string getPubCode() const;
    double getPrice() const;

    // Mutator method (setter)
    void changePrice(double newPrice);
};

#endif // BOOK_H
