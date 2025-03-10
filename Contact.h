#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <optional>
#include <iostream>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::optional<std::string> phone_number;

public:
    /*
     * Constructor with efficient parameter passing (using const references and move semantics)
     * std::nullopt is available from C++ 17
     *
     */
    Contact(const std::string& first, const std::string& last, std::optional<std::string> phone = std::nullopt);

    // Getters (marked as const for safety)
    const std::string& getFirstName() const { return first_name; }
    const std::string& getLastName() const { return last_name; }
    const std::optional<std::string>& getPhoneNumber() const { return phone_number; }

    // Print contact details (marked as const)
    void print() const;
};

#endif // CONTACT_H
