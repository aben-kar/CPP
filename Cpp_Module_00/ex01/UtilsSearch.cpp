/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsSearch.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-kar <aben-kar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 22:02:22 by acben-ka          #+#    #+#             */
/*   Updated: 2026/01/01 17:59:41 by aben-kar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UtilsSearch.hpp"

std::string IsValide(const std::string value)
{
    if (value.length() <= 10)
        return value;
    else
        return value.substr(0, 9) + ".";
}

void PrintListContacts()
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "LastName" << "|"
              << std::setw(10) << "NickName" << std::endl;
}

void _PrintContacts(int contactCount, const Contact contacts[8])
{
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << IsValide(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << IsValide(contacts[i].getLastName()) << "|"
                  << std::setw(10) << IsValide(contacts[i].getNickName()) << std::endl;
    }
}

void CheackIndex(int CountContact, int &Index)
{
    std::string input;
    while (1)
    {
        std::cout << GREEN "Enter the index of the contact to view details: " << RESET;
        std::getline(std::cin, input);
        if (std::cin.eof() == true)
            exit(0);
        if (!std::isdigit(input[0]))
            std::cout << RED "Invalid Index. Please enter a valid Index." << RESET << std::endl;
        else
        {
            Index = atoi(input.c_str());
            if (Index < 0 || Index >= CountContact)
            {
                std::cout << RED "Index out of range." << RESET << std::endl;
            }
            else
                break;
        }
    }
}