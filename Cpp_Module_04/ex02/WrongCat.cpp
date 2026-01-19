#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "Wrong Cat";
    std::cout << "WrongCat constructed!" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "GRRRRRRRRRRRRRRRRR!" << std::endl;
}