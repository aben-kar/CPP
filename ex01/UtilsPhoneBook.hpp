/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsPhoneBook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-kar <aben-kar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:36:54 by aben-kar          #+#    #+#             */
/*   Updated: 2025/12/30 03:47:53 by aben-kar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSPHONEBOOK_HPP
#define UTILSPHONEBOOK_HPP

#include <iostream>
#include <cstdlib>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

bool isEmpty(const std::string str);
bool getNonEmptyInput(const std::string prompt, std::string &result);
std::string IsValide(const std::string value);
bool getContact(std::string &firstName, std::string &lastName, 
                      std::string &nickName, std::string &phoneNumber, 
                      std::string &darkestSecret);

#endif