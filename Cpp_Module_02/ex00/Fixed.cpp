#include "Fixed.hpp"

Fixed::Fixed() : Value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}


Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other) {
        this->Value = other.getRawBits();
    }
    return *this;
}

void Fixed::setRawBits(int value)
{
    this->Value = value;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->Value;
}
