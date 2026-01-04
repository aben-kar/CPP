#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << GREEN << "Zombie created." << RESET << std::endl;
}

Zombie::~Zombie()
{
    std::cout << RED << "Zombie " << this->name << " destroyed." << RESET << std::endl;
}

void Zombie::announce(void)
{
    std::cout << CYAN << this->name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
