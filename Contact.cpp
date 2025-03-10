#include "Contact.h"

// Ctor of the contact
Contact::Contact(const std::string& first, const std::string& last, std::optional<std::string> phone) : 
    first_name(first), last_name(last), phone_number(std::move(phone))
{}

void Contact::print() const
{
    std::cout << "Name: " << first_name << " " << last_name;
    if(phone_number)
    {
        std::cout << " Phone: " << *phone_number;
    }
} 
