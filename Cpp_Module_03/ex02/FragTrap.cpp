#include "FragTrap.hpp"


FragTrap::FragTrap()
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap" << this->Name << "Default Constructor" << std::endl;
}


FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << this->Name << " constructed." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->Name << " destroyed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->Name << " positive high-fives request on the standard output." << std::endl;
}
