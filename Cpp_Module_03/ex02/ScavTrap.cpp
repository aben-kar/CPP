#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap " << this->Name << " Default Constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << this->Name << " constructed." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->Name << " destroyed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

void ScavTrap::attack(const std::string& target)
{
    if (this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        this->EnergyPoints--;
        std::cout << "ScavTrap " << this->Name << " ferociously attacks " << target 
                  << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
    }
    else
        return;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode." << std::endl;
}