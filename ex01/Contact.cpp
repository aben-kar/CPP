/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-kar <aben-kar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:20:09 by acben-ka          #+#    #+#             */
/*   Updated: 2025/12/31 16:06:31 by aben-kar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    FirstName = "";
    LastName = "";
    NickName = "";
    PhoneNumber = "";
    DarkestSecret = "";
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
