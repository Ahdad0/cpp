#pragma once

#include <iostream>
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(std::string const & type);
        Cure(const Cure& obj);
        Cure& operator=(const Cure& obj);
        ~Cure();
        Cure* clone() const;
        void use(ICharacter& target);
};