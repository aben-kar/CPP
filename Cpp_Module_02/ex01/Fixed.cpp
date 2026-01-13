#include "Fixed.hpp"

Fixed::Fixed() : Value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    this->Value = n << this->Bits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    this->Value = roundf(f * (1 << this->Bits));
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
    return this->Value;
}

int Fixed::toInt(void) const {
    return (this->Value >> this->Bits);
}

float Fixed::toFloat(void) const {
    return ((float)this->Value / (1 << this->Bits));
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}
