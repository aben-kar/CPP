#include "FragTrap.hpp"
#include "ScavTrap.hpp"


int	main() {
	ScavTrap	talin("Talin");
	ScavTrap	mogrus("Mogrus");
	FragTrap	jagar("Jagar");

	talin.attack("Mogrus");
	mogrus.takeDamage(20);
	mogrus.attack("Talin");
	talin.takeDamage(20);
	talin.beRepaired(20);
	talin.attack("Mogrus");
	mogrus.takeDamage(20);
	jagar.highFivesGuys();
}