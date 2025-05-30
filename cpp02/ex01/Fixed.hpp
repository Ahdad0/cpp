#pragma once

#include <iostream>
#include <cstring>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed& obj);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        ~Fixed();

    private:
        int fixed_point;
        const int fractional_bits;
};

std::ostream& operator<<(std::ostream &os, const Fixed& obj);