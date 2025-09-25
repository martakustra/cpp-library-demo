#include <iostream>
#include "Book.h"

void Book::printInfo() const {
    //cout << "Tytuł: " << title << ", Autor: " << author << ", Rok: " << year << endl;
    std::cout << *this << '\n';
}

std::ostream &operator<<(std::ostream &os, const Book &b) {
    os << "Tytuł: " << b.getTitle() << ", Autor: " << b.getAuthor() << ", Rok: " << b.getYear();
    return os;
}