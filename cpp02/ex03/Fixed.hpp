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
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);
        bool operator>(const Fixed& obj);
        bool operator<(const Fixed& obj);
        bool operator>=(const Fixed& obj);
        bool operator<=(const Fixed& obj);
        bool operator==(const Fixed& obj);
        bool operator!=(const Fixed& obj);
        Fixed operator+(const Fixed& obj);
        Fixed operator-(const Fixed& obj);
        Fixed operator*(const Fixed& obj);
        Fixed operator/(const Fixed& obj);
        static Fixed& max(Fixed& obj0, Fixed& obj1);
        static const Fixed& max(const Fixed& obj0, const Fixed& obj1);
        static Fixed& min(Fixed& obj0, Fixed& obj1);
        static const Fixed& min(const Fixed& obj0, const Fixed& obj1);
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