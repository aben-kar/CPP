#include "FragTrap.hpp"


FragTrap::FragTrap()
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << Name << "Default Constructor" << std::endl;
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
    ClapTrap::operator=(other);
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap class destructor called!" << std::endl;

}