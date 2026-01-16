#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string Name;
        unsigned int HitPoints;
        unsigned int EnergyPoints;
        unsigned int AttackDamage;
    public:
        ClapTrap();
        ~ClapTrap();
        ClapTrap(std::string _name);
        ClapTrap (const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap &other);

        void attack(const std::string& target); // cheked
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount); // checked
};

#endif