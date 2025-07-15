#pragma once

#include <iostream>
#include "ICharacter.hpp"

class IMateria : public AMateria
{
    protected:
        std::string type;
    public:
        IMateria(std::string const & type);
        std::string const & getType() const; //Returns the materia type
        virtual IMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};