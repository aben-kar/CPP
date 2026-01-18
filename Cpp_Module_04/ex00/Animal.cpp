#include "Animal.hpp"

Animal::Animal() : type("Type")
{
    std::cout << "Animal constructed!" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructed!" << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Generic Animal Sound..." << std::endl;
}
