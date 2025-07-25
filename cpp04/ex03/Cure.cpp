#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(std::string const & type) : AMateria("cure")
{
    (void)type;
}

Cure::Cure(const Cure& obj)
{
    *this = obj;
}

Cure& Cure::operator=(const Cure& obj)
{
    if (this != &obj)
        AMateria::operator=(obj);
    return *this;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

Cure* Cure::clone() const
{
    Cure *curr = new Cure(*this);
    return curr;
}

Cure::~Cure()
{
}
