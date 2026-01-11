#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int Value;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed (const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        void setRawBits(int Value);
        int getRawBits() const;
};

#endif
