#pragma once

#include <iostream>
#include "ICharacter.hpp"

class Cure : public AMateria
{
    private:
        std::string type;
    public:
        Cure(std::string const & type);
        std::string const& getType() const; //Returns the materia type
        virtual Cure* clone() const = 0;
        virtual void use(ICharacter& target);
};