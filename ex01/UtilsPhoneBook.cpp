/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsPhoneBook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-kar <aben-kar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:30:30 by aben-kar          #+#    #+#             */
/*   Updated: 2025/12/31 20:50:59 by aben-kar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UtilsPhoneBook.hpp"

void getContact(std::string &firstName, std::string &lastName,
                      std::string &nickName, std::string &phoneNumber,
                      std::string &darkestSecret)
{
    getNonEmptyInput("First name: ", firstName);
    getNonEmptyInput("Last name: ", lastName);
    getNonEmptyInput("Nickname: ", nickName);
    getNonEmptyInput("Phone number: ", phoneNumber);
    getNonEmptyInput("Darkest secret: ", darkestSecret);
}

bool isEmpty(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
            return false;
    }
    return true;
}


std::string trim(std::string &str)
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && (str[start] == ' ' || str[start] == '\t'))
        start++;

    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
        end--;

    return str.substr(start, end - start);
}

bool IsNumber(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' || str[i] == '\t')
            continue;
        else if (!isdigit(str[i]))
            return false;
    }
    return true;
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
        if (prompt == "Phone number: ")
        {
            if (!IsNumber(input))
            {
                std::cout << RED "Invalid phone number." RESET << std::endl;
                continue;
            }
            else
            {
                trimmed = trim(input);
                result = trimmed;
                return true;
            }
        }
        trimmed = trim(input);
        if (isEmpty(trimmed))
            std::cout << RED "Field cannot be empty." RESET << std::endl;
        else
        {
            result = trimmed;
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

void PrintListContacts()
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "LastName" << "|"
              << std::setw(10) << "NickName" << std::endl;
}