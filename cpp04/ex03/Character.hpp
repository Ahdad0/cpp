#pragma once

#include "ICharacter.hpp"
#include <iostream>
#include <list>

struct MateriaNode
{
    AMateria* materia;
    MateriaNode* next;

    MateriaNode(AMateria* m) : materia(m), next(NULL) {}
};

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* amateria[4];
        MateriaNode* head;
    public:
        Character();
        Character(std::string const& name);
        Character(const Character& obj);
        Character& operator=(const Character& obj);
        ~Character();
        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void add_list(AMateria* m);
        void clear();
};
