/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acben-ka <acben-ka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:22:25 by acben-ka          #+#    #+#             */
/*   Updated: 2025/12/29 22:31:54 by acben-ka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>


class Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
    public:
        Contact();
        void setFirstName(std::string fn);
        std::string getFirstName() const;
        void setLastName(std::string ln);
        std::string getLastName() const;
        void setNickName(std::string nn);
        std::string getNickName() const;
        void setPhoneNumber(std::string pn);
        std::string getPhoneNumber() const;
        void setDarkestSecret(std::string ds);
        std::string getDarkestSecret() const;
        ~Contact();
};

#endif