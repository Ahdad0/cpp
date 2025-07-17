#include "Character.hpp"

Character::Character() : name("")
{
    int i = 0;
    while (i < 4)
    {
        amateria[i] = nullptr;
        i++;
    }
}

std::string const& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (m)
    {
        int i = 0;
        while (i < 4)
        {
            if (!amateria[i])
            {
                amateria[i] = m;
                break;
            }
            i++;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
    {
        if (amateria[idx])
        {
            amateria[idx] = NULL;
        }
    }
}

void Character::use(int idx, Character& target)
{
    if (idx >= 0 && idx <= 3)
    {
        if (amateria[idx])
        {
            amateria[idx]->use(target);
        }
    }
}
