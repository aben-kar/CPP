/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-kar <aben-kar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:19:56 by acben-ka          #+#    #+#             */
/*   Updated: 2025/12/30 03:35:36 by aben-kar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    (void)av;
    PhoneBook phoneBook;
    if (ac == 1)
    {
        std::string input;;
        while (1)
        {
            std::cout << CYAN "Enter command (ADD, SEARCH, or EXIT): " RESET;

            if (!std::getline(std::cin, input))
                break;
            if (input == "ADD")
                phoneBook.AddContact();
            else if (input == "SEARCH")
                phoneBook.SearchContact();
            else if (input =="EXIT")
                break;
            else
                std::cout << RED "Error: Invalid argument. Please use ADD, SEARCH, or EXIT." << RESET << std::endl;
        }
    }
    else
        std::cout << RED "Error: This program does not take any arguments." << RESET << std::endl;
    return 0;
}