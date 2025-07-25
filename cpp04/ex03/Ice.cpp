#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice& obj) : AMateria(obj)
{
}
Ice::Ice(std::string const & type) : AMateria("ice")
{
    (void)type;
}

Ice& Ice::operator=(const Ice& obj)
{
    if (this != &obj)
        AMateria::operator=(obj);
    return *this;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice* Ice::clone() const
{
    Ice *curr = new Ice(*this);
    return curr;
}

Ice::~Ice()
{
}