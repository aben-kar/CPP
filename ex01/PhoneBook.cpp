/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:19:49 by acben-ka          #+#    #+#             */
/*   Updated: 2025/12/30 00:13:52 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UtilsPhoneBook.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), NextIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

// Add a new contact
void PhoneBook::AddContact()
{
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    std::cout << GREEN "\n=== Adding New Contact ===" << RESET << std::endl;

    if (!getContactFields(firstName, lastName, nickName, phoneNumber, darkestSecret))
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

    std::cout << GREEN "=== Contact added successfully! ===" << RESET << std::endl;
}

void PhoneBook::SearchContact() const
{
    if (contactCount == 0)
    {
        std::cout << RED "No contacts available. Please add contacts first." << RESET << std::endl;
        return;
    }

    std::cout << GREEN "\n=== Contact List ===" << RESET << std::endl;
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
    std::cout << GREEN "Enter the index of the contact to view details: " << RESET;
    std::getline(std::cin, input);
    if (std::cin.eof() == true)
        exit(0);

    if (!std::isdigit(input[0]) || input.length() != 1)
        std::cout << RED "Invalid Index. Please enter a valid Index." << RESET << std::endl;
    else
    {
        int index = atoi(input.c_str());
        if (index < 0 || index >= contactCount)
        {
            std::cout << RED "Index out of range." << RESET << std::endl;
            return;
        }

        // display full contact info
        std::cout << std::setw(10) << GREEN "Contact Details:" << RESET << std::endl;
        std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
        std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
        std::cout << GREEN "=== End of contact data ===" << RESET << std::endl;
    }
}