#include "Character.hpp"

Character::Character() : name("NoName"), head(NULL)
{
    int i = 0;
    while (i < 4)
    {
        amateria[i] = NULL;
        i++;
    }
}

Character::Character(std::string const& name) : name(name), head(NULL)
{
    int i = 0;
    while (i < 4)
    {
        amateria[i] = NULL;
        i++;
    }
}

Character::Character(const Character& obj)
{
    *this = obj;
}

Character& Character::operator=(const Character& obj)
{
    if (this != &obj)
    {
        this->name = obj.name;
        int i = 0;
        while (i < 4)
        {
            if (this->amateria[i])
                delete this->amateria[i];
            if (this->amateria[i])
                this->amateria[i] = obj.amateria[i]->clone();
            else
                this->amateria[i] = NULL;
            i++;
        }
    }
    return *this;
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
                amateria[i] = m->clone();
                break;
            }
            i++;
        }
        if (m)
            delete m;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3)
    {
        if (amateria[idx])
        {
            add_list(amateria[idx]);
            amateria[idx] = NULL;
        }
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3)
    {
        if (amateria[idx])
            amateria[idx]->use(target);
    }
}

Character::~Character()
{
    int i = 0;
    while (i < 4)
    {
        if (amateria[i])
            add_list(amateria[i]);
        i++;
    }
    clear();
}

void Character::add_list(AMateria* m)
{
    MateriaNode* node = new MateriaNode(m);
    node->next = head;
    head = node;
}

void Character::clear()
{
    MateriaNode* temp;

    while (head)
    {
        temp = head;
        head = head->next;
        if (temp->materia)
            delete temp->materia;
        if (temp)
            delete temp;
    }
}