#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructed!" << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat destructed!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = NULL;
    if (other._brain) // avoid copying NULL
        this->_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other)
    {
        if (this->_brain)
        {
            delete this->_brain;
            this->_brain = NULL;
        }
        this->_brain = new Brain(*other._brain);
        this->type = other.type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}
