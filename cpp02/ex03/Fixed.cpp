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

Fixed& Fixed::operator++()
{
    fixed_point++;

    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp;
    temp.fixed_point = fixed_point++;
    return temp;
}

Fixed& Fixed::operator--()
{
    fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp;
    temp.fixed_point = fixed_point--;
    return temp;
}

bool Fixed::operator>(const Fixed& obj)
{
    return this->fixed_point > obj.fixed_point;
}

bool Fixed::operator<(const Fixed& obj)
{
    return this->fixed_point < obj.fixed_point;
}

bool Fixed::operator>=(const Fixed& obj)
{
    return this->fixed_point >= obj.fixed_point;
}

bool Fixed::operator<=(const Fixed& obj)
{
    return this->fixed_point <= obj.fixed_point;
}

bool Fixed::operator==(const Fixed& obj)
{
    return this->fixed_point == obj.fixed_point;
}

bool Fixed::operator!=(const Fixed& obj)
{
    return this->fixed_point <= obj.fixed_point;
}

Fixed Fixed::operator+(const Fixed& obj)
{
    Fixed temp;

    temp.fixed_point = this->fixed_point + obj.fixed_point;
    return temp;
}

Fixed Fixed::operator-(const Fixed& obj)
{
    Fixed temp;

    temp.fixed_point = this->fixed_point - obj.fixed_point;
    return temp;
}

Fixed& Fixed::max(Fixed& obj0, Fixed& obj1)
{
    if (obj0.fixed_point > obj1.fixed_point)
        return obj0;
    else
        return obj1;
}

const Fixed& Fixed::max(const Fixed& obj0, const Fixed& obj1)
{
    if (obj0.fixed_point > obj1.fixed_point)
        return obj0;
    else
        return obj1;
}

Fixed& Fixed::min(Fixed& obj0, Fixed& obj1)
{
    if (obj0.fixed_point > obj1.fixed_point)
        return obj1;
    else
        return obj0;
}

const Fixed& Fixed::min(const Fixed& obj0, const Fixed& obj1)
{
    if (obj0.fixed_point > obj1.fixed_point)
        return obj1;
    else
        return obj0;
}

Fixed Fixed::operator*(const Fixed& obj)
{
    Fixed temp;

    temp.fixed_point = roundf((this->toFloat() * obj.toFloat()) * (1 << fractional_bits));
    return temp;
}

Fixed Fixed::operator/(const Fixed& obj)
{
    Fixed temp;
    
    if (obj.fixed_point == 0)
    {
        std::cerr << "shouldn't be division by 0\n";
        return temp;
    }
    temp.fixed_point = roundf((this->toFloat() / obj.toFloat()) * (1 << fractional_bits));
    return temp;
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
