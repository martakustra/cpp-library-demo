#pragma once
#include <iostream>
#include <string>
#include <vector>

class Book;

class Library {
    private:
        std::vector<Book> books;
    public:
        void add(const Book &b);
        std::size_t size() const;
        void listAll(std::ostream &os) const;
        const Book* findByTitle(const std::string &t) const;
        std::vector<const Book*> findByAuthorContains(const std::string &phrase) const;
        std::vector<const Book*> findByAuthorContainsCI(const std::string &phrase) const;
        bool removeByTitle(const std::string &t);
        std::size_t removeAllByTitle(const std::string &t);

        void sortByTitle();
        void sortByAuthorThenYear();
};