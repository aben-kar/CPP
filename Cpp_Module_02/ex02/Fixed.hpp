#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int Value;
        static const int Bits = 8;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed (const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        void setRawBits(int Value);
        int getRawBits() const;
        float toFloat( void ) const;
        int toInt( void ) const;
        bool operator>(const Fixed &rhs) const;
        bool operator<(const Fixed &rhs) const;
        bool operator>=(const Fixed &rhs) const;
        bool operator<=(const Fixed &rhs) const;
        bool operator==(const Fixed &rhs) const;
        bool operator!=(const Fixed &rhs) const;
        Fixed operator+(const Fixed &rhs) const;
        Fixed operator-(const Fixed &rhs) const;
        Fixed operator*(const Fixed &rhs) const;
        Fixed operator/(const Fixed &rhs) const;
        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);

};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
