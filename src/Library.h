#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"


class Library {
private:
    Book books[100];
    int count;

public:
    Library();

    void addBook();
    void displayBooks();
    void searchBook();
    void updateBook();
    void deleteBook();

    void saveToFile();
    void loadFromFile();
};

#endif