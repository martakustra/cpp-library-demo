#include <iostream>
#include "Book.h"
#include "Library.h"

int main() {

    Book b1("Tajemnica tajemnic", "Dan Brown", 2025);
    Book b2("Pan Tadeusz", "Adam Mickiewicz", 1834);
    std::cout << b1 << '\n';
    std::cout << b2 << '\n';
    //b1.printInfo();
    //b2.printInfo();
    //b2.setAuthor("Anonim");
    b2.setYear(0);
    std::cout << b2 << '\n';
    // b2.printInfo();

    Library lib;
    lib.add(b1);
    lib.add(b2);
    std::cout << "Liczba: " << lib.size() << '\n';
    lib.listAll(std::cout);

    Book b3("Rok 1984", "George Orwell", 1984);
    lib.add(b3);

    std::cout << "Liczba po zmianach: " << lib.size() << '\n';
    lib.listAll(std::cout);

    std::cout << "Sprawdźmy czy jest ksiązka Pan Tadeusz\n";
    auto *wsk_book = lib.findByTitle("Pan Tadeusz");
    if (wsk_book != nullptr) {
        std::cout << *wsk_book << '\n';
    }

    std::cout << "Szukaj po Adam\n";
    auto matches = lib.findByAuthorContains("Adam");
    std::cout << "Znaleziono: " << matches.size() << '\n';
    for (const auto *book : matches) {
        std::cout << *book << '\n';
    }

    std::cout << "Szukaj po ADAm\n";
    auto matches2 = lib.findByAuthorContainsCI("ADAm");
    std::cout << "Znaleziono: " << matches2.size() << '\n';
    for (const auto *book : matches2) {
        std::cout << *book << '\n';
    }

    /*std::cout << "Usun Pan Tadeusz\n";
    lib.removeByTitle("Pan Tadeusz");
    std::cout << "Liczba po zmianach: " << lib.size() << '\n';
    lib.listAll(std::cout);*/

    Book b4("Pan Tadeusz", "Adam Mickiewicz", 1950);
    lib.add(b4);

    Book b5("Pan Tadeusz", "Adam Mickiewicz", 1830);
    lib.add(b5);

    std::cout << "Sortuj po tytule\n";
    lib.sortByTitle();
    lib.listAll(std::cout);

    std::cout << "Sortuj po autorze i roku wydania\n";
    lib.sortByAuthorThenYear();
    lib.listAll(std::cout);

    std::cout << "Usun wszystkie ksiązki o tytule Pan Tadeusz\n";
    std::size_t removed = lib.removeAllByTitle("Pan Tadeusz");
    std::cout << "Usunieto: " << removed << '\n';
    lib.listAll(std::cout);

    return 0;
}