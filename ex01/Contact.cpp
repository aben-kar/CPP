/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:20:09 by acben-ka          #+#    #+#             */
/*   Updated: 2025/12/29 22:32:58 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
    : FirstName(""), LastName(""), NickName(""), PhoneNumber(""), DarkestSecret("")
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string fn)
{
    FirstName = fn;
}

std::string Contact::getFirstName() const
{
    return FirstName;
}

void Contact::setLastName(std::string ln)
{
    LastName = ln;
}

std::string Contact::getLastName() const
{
    return LastName;
}

void Contact::setNickName(std::string nn)
{
    NickName = nn;
}

std::string Contact::getNickName() const
{
    return NickName;
}

void Contact::setPhoneNumber(std::string pn)
{
    PhoneNumber = pn;
}

std::string Contact::getPhoneNumber() const
{
    return PhoneNumber;
}

void Contact::setDarkestSecret(std::string ds)
{
    DarkestSecret = ds;
}

std::string Contact::getDarkestSecret() const
{
    return DarkestSecret;
}
