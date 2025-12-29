/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsPhoneBook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:30:30 by aben-kar          #+#    #+#             */
/*   Updated: 2025/12/30 00:00:25 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UtilsPhoneBook.hpp"

bool getContactFields(std::string &firstName, std::string &lastName,
                      std::string &nickName, std::string &phoneNumber,
                      std::string &darkestSecret)
{
    if (!getNonEmptyInput("First name: ", firstName))
        return false;
    if (!getNonEmptyInput("Last name: ", lastName))
        return false;
    if (!getNonEmptyInput("Nickname: ", nickName))
        return false;
    if (!getNonEmptyInput("Phone number: ", phoneNumber))
        return false;
    if (!getNonEmptyInput("Darkest secret: ", darkestSecret))
        return false;
    return true;
}

bool isEmpty(const std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
            return false;
    }
    return true;
}

bool getNonEmptyInput(const std::string prompt, std::string &result)
{
    std::string input;
    
    while (1)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if(std::cin.eof() == true)
            exit(0);
        if (input.empty() || isEmpty(input))
            std::cout << RED "Field cannot be empty. Try again." << RESET << std::endl;
        else
        {
            result = input;
            return true;
        }
    }
}

std::string IsValide(const std::string value)
{
    if (value.length() <= 10)
        return value;
    else
        return value.substr(0, 9) + ".";
}
