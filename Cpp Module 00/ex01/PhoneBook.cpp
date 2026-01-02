/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:19:49 by acben-ka          #+#    #+#             */
/*   Updated: 2025/12/31 22:52:42 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UtilsAdd.hpp"
#include "UtilsSearch.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contactCount = 0;
    NextIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

// Add a new contact
void PhoneBook::AddContact()
{
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    std::cout << GREEN "\nAdding New Contact:" << RESET << std::endl;
    
    // Get contact
    getContact(firstName, lastName, nickName, phoneNumber, darkestSecret);

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

    std::cout << GREEN "Contact added successfully!\n" << RESET << std::endl;
}

void PhoneBook::SearchContact() const
{
    int index;
    if (contactCount == 0)
    {
        std::cout << RED "No contacts available. Please add contacts first." << RESET << std::endl;
        return;
    }

    std::cout << GREEN "\nContact List:" << RESET << std::endl;
    PrintListContacts();
    _PrintContacts(contactCount, contacts);
    CheackIndex(contactCount, index);

    // display full contact info
    std::cout << GREEN "\nContact Details:" RESET << std::endl;
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    std::cout << GREEN "End of contact data\n" << RESET << std::endl;
}
