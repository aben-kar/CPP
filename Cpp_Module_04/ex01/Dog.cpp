#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructed!" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog()
{
    // delete this->brain;
    std::cout << "Dog destructed!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = NULL;
    if (other.brain)
        this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other)
    {
        if (this->brain)
        {
            delete this->brain;
            this->brain = NULL;
        }
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl; 
}
