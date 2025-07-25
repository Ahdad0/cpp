#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(std::string const & type);
        Ice(const Ice& obj);
        Ice& operator=(const Ice& obj);
        ~Ice();
        Ice* clone() const;
        void use(ICharacter& target);
};