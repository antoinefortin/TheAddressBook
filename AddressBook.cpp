#include "AddressBook.h"
#include <iostream>


bool AddressBook::noCapital(const std::string& str, const std::string& substr) {
    auto it = std::search(str.begin(), str.end(), substr.begin(), substr.end(),
        []
        (char ch1, char ch2) 
        { return std::tolower(ch1) == std::tolower(ch2); }
    );
    return it != str.end(); 
}

void AddressBook::addContact(const Contact& contact) {
    contacts.push_back(contact);
}

void AddressBook::removeContact(const std::string& first_name, const std::string& last_name) {
    contacts.erase(
        std::remove_if(contacts.begin(), contacts.end(),
            [&](const Contact& contact) {
                return contact.getFirstName() == first_name && contact.getLastName() == last_name;
            }),
        contacts.end()
    );
}

const std::vector<Contact>& AddressBook::getContacts() const {
    return contacts;
}


void AddressBook::sortContactsByFirstName() {
    std::sort(contacts.begin(), contacts.end(),
        [](const Contact& a, const Contact& b) { return a.getFirstName() < b.getFirstName(); });
}

/*
    
*/
void AddressBook::sortContactsByLastName() {
    std::sort(contacts.begin(), contacts.end(),
        [](const Contact& a, const Contact& b) { return a.getLastName() < b.getLastName(); });
}

/*
    Here we return a whole std vector for every search called, 
    This is not optimized for a large entry where many humans can be called Johnny or Oliver
    In this function we create a new Matches ContactVector 
*/
std::vector<Contact> AddressBook::searchContacts(const std::string& search_term) const {
    std::vector<Contact> matches;
    for (const Contact& contact : contacts) {
        if (noCapital(contact.getFirstName(), search_term) ||
        noCapital(contact.getLastName(), search_term)) {
            matches.push_back(contact);
        }
    }
    return matches;
}


void AddressBook::printContacts() const {
    for (const Contact& contact : contacts) {
        contact.print();
        std::cout << std::endl;
    }
}