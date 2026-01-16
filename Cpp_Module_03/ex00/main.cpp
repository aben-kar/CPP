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