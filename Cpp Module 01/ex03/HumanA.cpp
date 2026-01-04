#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon) : name(_name), weapon(_weapon)
{
}

void HumanA::attack() const
{
    std::cout << this->name << " attacks with their " 
              << this->weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
}
