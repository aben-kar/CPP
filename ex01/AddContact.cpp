/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AddContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-kar <aben-kar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:30:30 by aben-kar          #+#    #+#             */
/*   Updated: 2025/12/28 20:41:05 by aben-kar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AddContact.hpp"

// Helper function to check if string is empty or only whitespace
bool isEmpty(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
            return false;
    }
    return true;
}

// Helper function to get non-empty input from user
bool getNonEmptyInput(const std::string &prompt, std::string &result)
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