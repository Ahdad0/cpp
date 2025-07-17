#pragma once

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* amateria[4];
    public:
        Character();
        Character(std::string name);
        ~Character();
        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, Character& target);
};
