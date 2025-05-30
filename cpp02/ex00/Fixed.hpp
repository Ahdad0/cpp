#pragma once

#include <iostream>
#include <cstring>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed& obj);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        ~Fixed();

    private:
        int fixed_point;
        const int fractional_bits;
};
