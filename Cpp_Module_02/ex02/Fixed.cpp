#include "Fixed.hpp"

Fixed::Fixed() : Value(0)
{
}

Fixed::Fixed(const int n)
{
    this->Value = n << this->Bits;
}

Fixed::Fixed(const float f)
{
    this->Value = roundf(f * (1 << this->Bits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
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

int Fixed::toInt(void) const
{
    return (this->Value >> this->Bits);
}

float Fixed::toFloat(void) const
{
    return ((float)this->Value / (1 << this->Bits));
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    return Fixed(this->getRawBits() + rhs.getRawBits());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    return Fixed(this->getRawBits() - rhs.getRawBits());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    if (rhs.getRawBits() == 0)
    {
        std::cout << "Error: Division by zero!" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->Value++;
    return *this;
}

Fixed &Fixed::operator--(void)
{
    this->Value--;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed temp(*this);
    this->Value++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->Value--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return o;
}
