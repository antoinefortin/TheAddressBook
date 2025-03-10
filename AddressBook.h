#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include "Contact.h"
#include <vector>
#include <algorithm>
#include <cctype>

class AddressBook {
private:
    std::vector<Contact> contacts;
    static bool noCapital(const std::string& str, const std::string& substr);

public:
    // Use the default constructor by the  compiler
    AddressBook() = default;

    void addContact(const Contact& contact);

    void removeContact(const std::string& first_name, const std::string& last_name);
    const std::vector<Contact>& getContacts() const;
    /*
     I tought about those function to return a new std::vector<Contact> wich the sorted value
     but instead I decided to internally modify vector of contact 
    */
    void sortContactsByFirstName();
    void sortContactsByLastName();
    std::vector<Contact> searchContacts(const std::string& search_term) const;
    void printContacts() const;
};

#endif