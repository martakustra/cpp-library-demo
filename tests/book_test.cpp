#include <gtest/gtest.h>
#include <sstream>
#include "../src/Book.h"

TEST(BookTests, CtorAndGetters) {
    Book b("Pan Tadeusz", "Adam Mickiewicz", 1834);
    EXPECT_EQ(b.getTitle(), "Pan Tadeusz");
    EXPECT_EQ(b.getAuthor(), "Adam Mickiewicz");
    EXPECT_EQ(b.getYear(), 1834);
}

TEST(BookTests, OStreamOperatorFormatsOutput) {
    Book b("Tajemnica tajemnic", "Dan Brown", 2025);
    std::ostringstream oss;
    oss << b; // to woła operator<< z Book.cpp
    EXPECT_EQ(oss.str(),
        "Tytuł: Tajemnica tajemnic, Autor: Dan Brown, Rok: 2025");
}

TEST(BookTests, PrintInfoDelegatesToOperatorOStream) {
    Book b("Rok 1984", "George Orwell", 1984);
    std::ostringstream oss;
    auto* old = std::cout.rdbuf(oss.rdbuf());
    b.printInfo(); // to woła definicję z Book.cpp
    std::cout.rdbuf(old);
    EXPECT_EQ(oss.str(),
        "Tytuł: Rok 1984, Autor: George Orwell, Rok: 1984\n");
}
