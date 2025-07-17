#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice* Ice::clone() const
{
    Ice *curr = new Ice(*this);
    return curr;
}
