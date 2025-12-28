/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:01:42 by acben-ka          #+#    #+#             */
/*   Updated: 2025/12/28 01:39:18 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
    private:
        Contact contacts[8];
        int contactCount;
        int NextIndex;
    public:
        PhoneBook();
        void AddContact();
        void SearchContact() const;
        ~PhoneBook();
};

#endif