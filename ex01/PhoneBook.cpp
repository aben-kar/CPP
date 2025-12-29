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

    std::cout << "=== Contact added successfully! ===" << std::endl;
}

// #include <iomanip>
// #include <sstream>
// ...existing code...

std::string IsValide(const std::string &value)
{
    if (value.length() <= 10)
        return value;
    else
        return value.substr(0, 9) + ".";
}

void PhoneBook::SearchContact() const
{
    if (contactCount == 0)
    {
        std::cout << "No contacts available. Please add contacts first." << std::endl;
        return;
    }

    std::cout << "\n=== Contact List ===" << std::endl;
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "LastName" << "|"
              << std::setw(10) << "NickName" << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << IsValide(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << IsValide(contacts[i].getLastName()) << "|"
                  << std::setw(10) << IsValide(contacts[i].getNickName()) << std::endl;
    }

    std::string input;
    std::cout << "Enter the index of the contact to view details: ";
    if (!std::getline(std::cin, input))
        return;

    if (!std::isdigit(input[0]) || input.length() != 1)
        std::cout << "Invalid Index. Please enter a valid Index." << std::endl;
    else
    {
        int index = atoi(input.c_str());
        
        // check index range
        if (index < 0 || index >= contactCount)
        {
            std::cout << "Index out of range." << std::endl;
            return;
        }
        
        else
        {
            // display full contact info
            std::cout << std::setw(10) << "Contact Details:" << std::endl;
            std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
            std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
            std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
            std::cout << "=== End of contact data ===" << std::endl;
        }

    }
}