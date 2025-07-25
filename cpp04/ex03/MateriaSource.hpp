#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* materia[4];
    public:
        MateriaSource();
        MateriaSource(const std::string& nam);
        MateriaSource(const MateriaSource& obj);
        MateriaSource& operator=(const MateriaSource& obj);
        ~MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};