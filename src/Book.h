#pragma once 
#include <iostream>
#include <string>

class Book {
    private:
        std::string title;
        std::string author;
        int year;

    public:
        Book(const std::string &t, const std::string &a, int y)
            : title(t), author(a), year(y) {}
        void printInfo() const;
        const std::string &getTitle() const { return title; }
        const std::string &getAuthor() const { return author; }
        int getYear() const { return year; }
        void setTitle(const std::string &t) { title = t; }
        void setAuthor(const std::string &a) { author = a; }
        void setYear(int y) { year = (y < 0) ? 0 : y; }
};

std::ostream &operator<<(std::ostream &os, const Book &b);