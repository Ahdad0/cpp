#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0), fractional_bits(8)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) : fractional_bits(obj.fractional_bits)
{
    std::cout << "Copy constructor called" << std::endl;
    fixed_point = obj.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        fixed_point = obj.getRawBits();
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