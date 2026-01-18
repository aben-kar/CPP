#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Type";
    std::cout << "Dog constructed!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructed!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl; 
}
