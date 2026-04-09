#include <iostream>
#include <fstream>
#include "Library.h"
using namespace std;

Library::Library() {
    count = 0;
    loadFromFile(); // 🔥 auto load
}

// ✅ Add Book
void Library::addBook() {
    cout << "Enter ID: ";
    cin >> books[count].id;

    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, books[count].title);

    cout << "Enter Author: ";
    getline(cin, books[count].author);

    cout << "Enter Quantity: ";
    cin >> books[count].quantity;

    count++;
    saveToFile();

    cout << "Book Added!\n";
}

// ✅ Display
void Library::displayBooks() {
    if (count == 0) {
        cout << "No books available\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\n----------------------\n";
        cout << "ID: " << books[i].id << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Quantity: " << books[i].quantity << endl;
    }
}

// ✅ Search
void Library::searchBook() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            cout << "Found: " << books[i].title << endl;
            return;
        }
    }
    cout << "Book Not Found\n";
}

// ✅ Update
void Library::updateBook() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {

            cin.ignore();

            cout << "New Title: ";
            getline(cin, books[i].title);

            cout << "New Author: ";
            getline(cin, books[i].author);

            cout << "New Quantity: ";
            cin >> books[i].quantity;

            saveToFile();

            cout << "Updated!\n";
            return;
        }
    }
    cout << "Book Not Found\n";
}

// ✅ Delete
void Library::deleteBook() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {

            for (int j = i; j < count - 1; j++) {
                books[j] = books[j + 1];
            }

            count--;
            saveToFile();

            cout << "Deleted!\n";
            return;
        }
    }
    cout << "Book Not Found\n";
}

// ✅ Save to File
void Library::saveToFile() {
    ofstream file("src/data/book.txt");

    for (int i = 0; i < count; i++) {
        file << books[i].id << endl;
        file << books[i].title << endl;
        file << books[i].author << endl;
        file << books[i].quantity << endl;
    }

    file.close();
}

// ✅ Load from File
void Library::loadFromFile() {
    ifstream file("src/data/book.txt");

    while (file >> books[count].id) {
        file.ignore();
        getline(file, books[count].title);
        getline(file, books[count].author);
        file >> books[count].quantity;
        count++;
    }

    file.close();
}