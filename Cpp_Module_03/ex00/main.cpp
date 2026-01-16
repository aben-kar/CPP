#include "ClapTrap.hpp"

int main()
{
    ClapTrap trappy("FR4G-TP");

    trappy.attack("Bandit");
    trappy.takeDamage(5);
    trappy.beRepaired(10);
    trappy.takeDamage(5);
    trappy.beRepaired(3);
    trappy.takeDamage(13);
    trappy.beRepaired(3);
    return 0;
}

// ClapTrap FR4G-TP constructed.
// ClapTrap FR4G-TP attacks Bandit, causing 0 points of damage!
// ClapTrap FR4G-TP takes 5 points of damage!
// ClapTrap FR4G-TP repairs itself, regaining 10 hit points!
// ClapTrap FR4G-TP takes 5 points of damage!
// ClapTrap FR4G-TP repairs itself, regaining 3 hit points!
// ClapTrap FR4G-TP takes 13 points of damage!
// ClapTrap FR4G-TP is dead and cannot repair!
// ClapTrap FR4G-TP destroyed.