#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Type")
{
    std::cout << "WrongAnimal constructed!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

std::string &WrongAnimal::getType() const
{
    return (std::string&)this->type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Generic WrongAnimal Sound..." << std::endl;
}
