#include "Fixed.hpp"

std::ostream& operator<<(std::ostream &os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}

float Fixed::toFloat( void ) const
{
    float num = static_cast<float>(fixed_point) / (1 << fractional_bits);
    return num;
} 

int Fixed::toInt( void ) const
{
    int num = fixed_point / (1 << fractional_bits);
    return num;
}

Fixed::Fixed() : fixed_point(0), fractional_bits(8)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : fractional_bits(8)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_point = num * (1 << fractional_bits);
}

Fixed::Fixed(const float num) : fractional_bits(8)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_point = roundf(num * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed& obj) : fractional_bits(obj.fractional_bits)
{
    std::cout << "Copy constructor called" << std::endl;
    fixed_point = obj.fixed_point;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        fixed_point = obj.fixed_point;
    }
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}