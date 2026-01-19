#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat constructed!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructed!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
        this->type = other.type;
        
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}
