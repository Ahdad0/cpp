#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        // std::string const& getType() const; //Returns the materia type
        Ice* clone() const;
        // virtual void use(ICharacter& target);
};