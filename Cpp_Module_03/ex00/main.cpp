#include "ClapTrap.hpp"

int main()
{
    ClapTrap trappy("FR4G-TP");

    trappy.attack("Bandit");
    trappy.takeDamage(5);
    trappy.beRepaired(3);
    
    // Force energy depletion
    for (int i = 0; i < 10; i++)
        trappy.attack("an annoying fly");

    return 0;
}