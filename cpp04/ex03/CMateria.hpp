#pragma once

#include <iostream>
#include "ICharacter.hpp"

class CMateria : public AMateria
{
    protected:
    public:
        CMateria(std::string const & type);
        std::string const& getType() const; //Returns the materia type
        virtual CMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};