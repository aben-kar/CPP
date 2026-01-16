#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
    Name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "Default Constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) :
    Name(_name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap " << this->Name << " constructed." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->Name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string&target)
{
    if (this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        this->EnergyPoints--;
        std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing "
                    << this->AttackDamage << " points of damage! " << std::endl;
    }
    else
        return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoints == 0)
        return;

    if (amount >= this->HitPoints)
        this->HitPoints = 0;
    else
        this->HitPoints -= amount;

    std::cout << "ClapTrap " << this->Name << " takes " << amount 
              << " points of damage! Remaining HP: " << this->HitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HitPoints > 0 && this-> EnergyPoints > 0)
    {
        this->EnergyPoints--;
        this->HitPoints += amount;
        std::cout << "ClapTrap " << this->Name << " repairs itself, regaining " 
                  << amount << " hit points! Current HP: " << this->HitPoints << std::endl;
    }
    else
        return;
}

