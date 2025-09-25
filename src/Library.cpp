#include "Library.h"
#include "Book.h"
#include <algorithm>
#include <cctype>

std::string toLower(std::string s) {
    for (char &c: s) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    return s;
}


void Library::add(const Book &b) {
    books.push_back(b);
}
        
std::size_t Library::size() const {
    return books.size();
}

void Library::listAll(std::ostream &os) const {
    for (const auto &book : books) {
        os << book << '\n';
    }
}

const Book* Library::findByTitle(const std::string &t) const {
    for (const auto &book : books) {
        if (book.getTitle() == t)
            return &book;
    }
    return nullptr;
}

std::vector<const Book*> Library::findByAuthorContains(const std::string &phrase) const {
    std::vector<const Book*> results;
    for (const auto &book : books) {
        if (book.getAuthor().find(phrase) != std::string::npos) {
            results.push_back(&book);
        }
    }
    return results;
}

std::vector<const Book*> Library::findByAuthorContainsCI(const std::string &phrase) const {
    std::vector<const Book *> results;
    std::string needle = toLower(phrase);
    for (const auto &book : books) {
        if(toLower(book.getAuthor()).find(needle) != std::string::npos) {
            results.push_back(&book);
        }
    }
    return results;
}

bool Library::removeByTitle(const std::string &t) {
    bool found = false;
    for (std::size_t idx = 0; idx < books.size(); idx++) {
        if(books[idx].getTitle() == t) {
            found = true;
            books.erase(books.begin() + idx);
            break;
        }
    }
    return found;
}

std::size_t Library::removeAllByTitle(const std::string &t) {
    const std::size_t oldSize = books.size();
    books.erase(std::remove_if(books.begin(), books.end(),
                                    [&](const Book &b) { return b.getTitle() == t; }),
                books.end());
    return oldSize - books.size();
}

void Library::sortByTitle() {
    std::sort(books.begin(), books.end(),
        [](const Book &a, const Book &b) { return a.getTitle() < b.getTitle(); });
}

void Library::sortByAuthorThenYear() {
    std::sort(books.begin(), books.end(),
        [](const Book &a, const Book &b) { 
            if (a.getAuthor() < b.getAuthor()) return true;
            if (b.getAuthor() < a.getAuthor()) return false;
            return a.getYear() < b.getYear();
        });
}
