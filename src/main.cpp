#include <iostream>
#include "Library.h"

using namespace std;

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n1.Add\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: lib.addBook(); break;
        case 2: lib.displayBooks(); break;
        case 3: lib.searchBook(); break;
        case 4: lib.updateBook(); break;
        case 5: lib.deleteBook(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice\n";
        }

    } while (choice != 6);
}