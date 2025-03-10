#include "Menu.h"
#include <iostream> 
#include <string>   
#include <algorithm> 

// Constructor
/*
    I pass the Address book as reference 
*/
Menu::Menu(AddressBook& address_book) : address_book(address_book)
{ 
}
void Menu::PrintMenu() const {
    std::cout << "########################" << std::endl;
    std::cout << "# Foundry Address Book #" << std::endl;
    std::cout << "########################" << std::endl;
}

void Menu::PrintOptions() const {
    std::cout << "1: Add an entry" << std::endl;
    std::cout << "2: List entries" << std::endl;
    std::cout << "3: Search for an entry" << std::endl;
    std::cout << "4: Delete an entry" << std::endl;
    std::cout << "5: Order by firstname" << std::endl;
    std::cout << "6: Order by last name" << std::endl;

    std::cout << "7: Exit" << std::endl;
}

void Menu::Run() {
    int choice = 0;
    while (true) {
        PrintMenu();
        PrintOptions();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                AddEntry();
                break;
            case 2:
                ListEntries();
                break;
            case 3:
                SearchEntries();
                break;
            case 4:
                DeleteEntry();
                break;
            case 5:
                SortEntriesByFirstName();
                break;
            case 6:
                SortEntriesByLastName();
                break;
            
            case 7:
                std::cout << "Quiting the app" << std::endl;
                return;
            default:
                std::cout << "Not valid, please enter a valid entry." << std::endl;
        }
    }
}

void Menu::AddEntry() {
    std::string first_name, last_name, phone_number;
    std::cout << "Enter first name: ";
    std::cin >> first_name;
    std::cout << "Enter last name: ";
    std::cin >> last_name;
    std::cout << "Enter phone number (optional, press Enter to skip): ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, phone_number);

    if (phone_number.empty()) {
        address_book.addContact(Contact(first_name, last_name));
    } else {
        address_book.addContact(Contact(first_name, last_name, phone_number));
    }
    std::cout << "Entry added successfully!" << std::endl;
}

// List all entries
void Menu::ListEntries() const {
    address_book.printContacts();
}

void Menu::SortEntriesByFirstName()
{
    address_book.sortContactsByFirstName();
    std::cout << "Sorted Contact by first name" << std::endl;
}

void Menu::SortEntriesByLastName()
{
    address_book.sortContactsByLastName();
    address_book.printContacts();
    std::cout << "Sorted Contact by last name" << std::endl;
}

// Search for entries
void Menu::SearchEntries() const {
    std::string search_term;
    std::cout << "Enter term: ";
    std::cin >> search_term;
    std::cout << "Resiults:" << std::endl;
    auto results = address_book.searchContacts(search_term);
    for (const auto& contact : results) {
        contact.print();
        std::cout << std::endl;
    }
}

// Delete an entry
void Menu::DeleteEntry() {
    std::string first_name, last_name;
    std::cout << "Enter first name of the entry to delete: ";
    std::cin >> first_name;
    std::cout << "Enter last name of the entry to delete: ";
    std::cin >> last_name;
    address_book.removeContact(first_name, last_name);
    std::cout << "Entry deleted successfully!" << std::endl;
}
