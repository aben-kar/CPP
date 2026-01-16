#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string _name) :
    Name(_name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
}

ClapTrap::~ClapTrap()
{
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

// ClapTrap <name> attacks <target>, causing <damage> points of damage!
void ClapTrap::attack(const std::string&target)
{
    if (this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        this->EnergyPoints--;
        std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing "
                    << this->AttackDamage << " points of damage! " << std::endl;
    }
    else
    {
        std::cout << "ClapTrap is out of energy/dead" << std::endl;
        return;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{

}