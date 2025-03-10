#ifndef MENU_H
#define MENU_H

#include "AddressBook.h"
#include <iostream>

#include <iostream>
#include <string>
#include <algorithm>

class Menu {
public:
    Menu(AddressBook& address_book); // Constructor to initialize with an AddressBook

    void PrintMenu() const;
    void PrintOptions() const;
    void Run();

private:
    AddressBook& address_book;
    void ListEntries() const;
    void SearchEntries() const;
    void AddEntry();
    void DeleteEntry();
    void SortEntriesByFirstName();
    void SortEntriesByLastName();
};

#endif // MENU_H
