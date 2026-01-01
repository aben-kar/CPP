/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsAdd.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:30:30 by aben-kar          #+#    #+#             */
/*   Updated: 2026/01/01 17:01:01 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UtilsAdd.hpp"

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
        else if (!std::isdigit(str[i]))
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
