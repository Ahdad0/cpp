#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int i = 0;
    while (i < 4)
    {
        materia[i] = NULL;
        i++;
    }
}

MateriaSource::MateriaSource(const std::string& nam)
{
    (void)nam;
    int i = 0;
    while (i < 4)
    {
        materia[i] = NULL;
        i++;
    }
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
    *this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
    if (this != &obj)
    {
        int i = 0;
        while (i < 4)
        {
            if (this->materia[i])
                delete this->materia[i];
            if (this->materia[i])
                this->materia[i] = obj.materia[i]->clone();
            else
                this->materia[i] = NULL;
            i++;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* ma)
{
    int i = 0;
    while (i < 4)
    {
        if (!materia[i])
        {
            materia[i] = ma;
            return;
        }
        i++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    while (i < 4)
    {
        if (materia[i] && materia[i]->getType() == type)
            return materia[i]->clone();
        i++;
    }
    return NULL;
}

MateriaSource::~MateriaSource()
{
    int i = 0;
    while (i < 4)
    {
        if (materia[i])
            delete materia[i];
        i++;
    }
}