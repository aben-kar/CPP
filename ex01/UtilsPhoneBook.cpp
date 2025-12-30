/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsPhoneBook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-kar <aben-kar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:30:30 by aben-kar          #+#    #+#             */
/*   Updated: 2025/12/30 03:49:45 by aben-kar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UtilsPhoneBook.hpp"

bool getContact(std::string &firstName, std::string &lastName,
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


std::string trim(const std::string &str)
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && (str[start] == '\t'))
        start++;

    while (end > start && (str[end - 1] == '\t'))
        end--;

    return str.substr(start, end - start);
}


bool getNonEmptyInput(const std::string prompt, std::string &result)
{
    std::string input;
    std::string trimmed;

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        trimmed = trim(input);
        if (isEmpty(trimmed))
            std::cout << RED "Field cannot be empty." RESET << std::endl;
        else if (trimmed != input)
            std::cout << RED "No leading or trailing spaces/tabs allowed." RESET << std::endl;
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
