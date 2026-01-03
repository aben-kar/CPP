#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed Zombie")
{
    // Constructor body (if needed)
}

Zombie::Zombie(std::string name) : name(name)
{
    // Constructor body (if needed)
}
Zombie::~Zombie()
{
    std::cout << this->name << " is destroyed." << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": Braiiiiiiinnnssss..." << std::endl;
}
