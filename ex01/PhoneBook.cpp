#include "AddContact.hpp"
#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook() : contactCount(0), NextIndex(0)
{
}

// Destructor
PhoneBook::~PhoneBook()
{
}

// Add a new contact
void PhoneBook::AddContact()
{
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
    
    std::cout << "\n=== Adding New Contact ===" << std::endl;
    
    if (!getNonEmptyInput("First name: ", firstName))
        return;
    if (!getNonEmptyInput("Last name: ", lastName))
        return;
    if (!getNonEmptyInput("Nickname: ", nickName))
        return;
    if (!getNonEmptyInput("Phone number: ", phoneNumber))
        return;
    if (!getNonEmptyInput("Darkest secret: ", darkestSecret))
        return;
    
    // Store in the contact at nextIndex
    contacts[NextIndex].setFirstName(firstName);
    contacts[NextIndex].setLastName(lastName);
    contacts[NextIndex].setNickName(nickName);
    contacts[NextIndex].setPhoneNumber(phoneNumber);
    contacts[NextIndex].setDarkestSecret(darkestSecret);
    
    // Update circular index
    NextIndex = (NextIndex + 1) % 8;
    
    // Update count (max 8)
    if (contactCount < 8)
        contactCount++;
    
    std::cout << "Contact added successfully!" << std::endl;
}

// #include <iomanip>
// #include <sstream>
// ...existing code...

namespace
{
    std::string formatColumn(const std::string &value)
    {
        if (value.length() <= 10)
            return value;
        std::string truncated = value.substr(0, 9);
        truncated += '.';
        return truncated;
    }
}

// ...existing code...

void PhoneBook::SearchContact() const
{
    if (contactCount == 0)
    {
        std::cout << "\nPhoneBook is empty. Add a contact first.\n";
        return;
    }

    std::cout << "\n=== PhoneBook Contacts ===\n";
    std::cout << std::setw(10) << "Index" << '|'
              << std::setw(10) << "First Name" << '|'
              << std::setw(10) << "Last Name" << '|'
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contactCount; ++i)
    {
        std::cout << std::setw(10) << i << '|'
                  << std::setw(10) << formatColumn(contacts[i].getFirstName()) << '|'
                  << std::setw(10) << formatColumn(contacts[i].getLastName()) << '|'
                  << std::setw(10) << formatColumn(contacts[i].getNickName()) << std::endl;
    }

    std::cout << "\nEnter the index of the contact to display: ";
    std::string line;
    if (!std::getline(std::cin, line))
    {
        std::cin.clear();
        std::cout << "Input aborted.\n";
        return;
    }
    if (line.empty())
    {
        std::cout << "No index provided.\n";
        return;
    }

    std::istringstream iss(line);
    int idx;
    char extra;
    if (!(iss >> idx) || (iss >> extra) || idx < 0 || idx >= contactCount)
    {
        std::cout << "Invalid index.\n";
        return;
    }

    const Contact &contact = contacts[idx];
    std::cout << "\n=== Contact Details ===\n";
    std::cout << "First name: " << contact.getFirstName() << std::endl;
    std::cout << "Last name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickName() << std::endl;
    std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}