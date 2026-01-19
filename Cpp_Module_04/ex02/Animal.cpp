#include "Animal.hpp"

Animal::Animal() : type("Animal")
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

