#include "PhoneBook.hpp"
// #include <iostream>
// #include <string>
// #include <sstream>

// Helper function to check if string is empty or only whitespace
static bool isEmpty(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
            return false;
    }
    return true;
}

// Helper function to get non-empty input from user
static bool getNonEmptyInput(const std::string &prompt, std::string &result)
{
    std::string input;
    
    while (1)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return false;  // EOF (Ctrl+D)
        
        if (input.empty() || isEmpty(input))
            std::cout << "Field cannot be empty. Try again." << std::endl;
        else
        {
            result = input;
            return true;
        }
    }
}

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
