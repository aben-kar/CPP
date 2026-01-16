#ifndef SCARVTRAP_HPP
#define SCARVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string _name);
        ~ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap& operator=(const ScavTrap &other);
        void attack(const std::string& target);
        void guardGate();
};

#endif